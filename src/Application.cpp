/**
 * @file Application.cpp
 * 
 * @brief `MIDI-XP`: Application Class Implementation File 
 * 
 * @author Alexandros Iliadis (https://github.com/mogeadis)
 * @version 1.0.0
 * @date October 2026
 */
#include "Application.h"

#include "Configuration.h"
#include "Logger.h"
#include "Utilities.h"

// -----------------------------------------
// [Public] Constructor & Destructor Methods
// -----------------------------------------

Application::Application() :
    jack(cfg::JACK_PIN,cfg::JACK_DEBOUNCE_TIME),
    pot(cfg::POTENTIOMETER_PIN),
    pedal(this->pot,cfg::PEDAL_CC_MIN,cfg::PEDAL_CC_MAX,cfg::PEDAL_RAW_MIN,cfg::PEDAL_RAW_MAX,cfg::PEDAL_DEADZONE,cfg::PEDAL_THRESHOLD),
    calibrator(this->pot),
    midi(cfg::MIDI_CHANNEL)
{
    this->mode = Mode::OPERATION;
}
Application::~Application() = default;

// -----------------------
// [Public] Member Methods
// -----------------------

void Application::begin()
{
    Logger::init(cfg::LOGGER_BAUD_RATE);
    this->jack.init();
    this->pedal.init();
    DBG_PRINTLN("\nDevice initialized");
}
void Application::process()
{
    this->parser.update();
    if(this->parser.available())
    {
        this->processCommand();
    }

    if(this->mode == Mode::OPERATION)
    {
        this->processOperationMode();
    }
    else if(this->mode == Mode::CALIBRATION)
    {
        this->processCalibrationMode();
    }
}

// ------------------------
// [Private] Member Methods
// ------------------------

void Application::processCommand()
{
    if(this->parser.empty())
    {
        if(this->mode == Mode::CALIBRATION)
        {
            this->mode = Mode::OPERATION;
            this->pedal.assignLowerBound(this->calibrator.minValue());
            this->pedal.assignUpperBound(this->calibrator.maxValue());
            this->logCalibrationCompletion();
        }
        return;
    }

    if(utils::stringsAreEqual(this->parser.command(),cfg::PARSER_CALIBRATION_COMMAND,true))
    {
        if(this->mode == Mode::OPERATION)
        {
            this->calibrator.begin();
            this->mode = Mode::CALIBRATION;
            this->logCalibrationInitialization();
        }
        else if(this->mode == Mode::CALIBRATION)
        {
            this->logCalibrationInProgress();
        }
        return;
    }

    this->logUnknownCommand();
}
void Application::processOperationMode()
{
    this->jack.update();
    if(this->jack.changed())
    {
        this->logJackStatus();
    }
    if(!this->jack.connected())
    {
        return;
    }
    if(this->pedal.update())
    {
        uint8_t cc_value = this->pedal.value();
        this->midi.sendControlChange(cfg::MIDI_CC,cc_value);
        this->logControlChangeMessage(cfg::MIDI_CC,cc_value);
    }
}
void Application::processCalibrationMode()
{
    if(this->calibrator.update())
    {
        this->logCalibratorRawValue();
    }
}
void Application::logUnknownCommand() const
{
    Logger::print("Unknown command: ");
    Logger::println(this->parser.command());
}
void Application::logCalibrationInitialization() const
{
    Logger::println("");
    Logger::println("Calibration process initialized:");
    Logger::println("Move the pedal through its full range and press Enter to finish...");
}
void Application::logCalibrationInProgress() const
{
    Logger::println("");
    Logger::println("Calibration process already in progress:");
    Logger::println("Press Enter to finish current process...");
}
void Application::logCalibrationCompletion() const
{
    Logger::println("Calibration process completed:");
    Logger::println("Adjust the following configuration variables and reupload firmware to device:");
    Logger::print("[*] PEDAL_RAW_MIN <-- ");
    Logger::println(this->calibrator.minValue());
    Logger::print("[*] PEDAL_RAW_MAX <-- ");
    Logger::println(this->calibrator.maxValue());
    Logger::println("");
}
void Application::logJackStatus() const
{
    DBG_PRINT("Jack ");
    DBG_PRINTLN(this->jack.connected() ? "connected" : "disconnected");
}
void Application::logCalibratorRawValue() const
{
    DBG_PRINT("Raw value: ");
    DBG_PRINTLN(this->calibrator.rawValue());
}
void Application::logControlChangeMessage(uint8_t cc_number,uint8_t cc_value) const
{
    DBG_PRINT("[MIDI CC] ");
    DBG_PRINT("Channel: ");
    DBG_PRINT(this->midi.getChannel());
    DBG_PRINT(" | Number: ");
    DBG_PRINT(cc_number);
    DBG_PRINT(" | Value: ");
    DBG_PRINTLN(cc_value);
}