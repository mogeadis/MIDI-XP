/**
 * @file Application.h
 * 
 * @brief `MIDI-XP`: Application Class Header File 
 * 
 * @author Alexandros Iliadis (https://github.com/mogeadis)
 * @version 1.0.0
 * @date October 2026
 */
#pragma once

#include <stdint.h>

#include "Calibrator.h"
#include "CommandParser.h"
#include "ExpressionPedal.h"
#include "JackSwitch.h"
#include "MidiController.h"
#include "Potentiometer.h"

class Application
{
    public:

    // -----------------------------------------
    // [Public] Constructor & Destructor Methods
    // -----------------------------------------

    Application();
    ~Application();

    // -----------------------
    // [Public] Member Methods
    // -----------------------

    void begin();
    void process();

    private:

    // ----------------------
    // [Private] Enumerations
    // ----------------------

    enum class Mode : uint8_t
    {
        OPERATION,
        CALIBRATION
    };

    // ------------------------
    // [Private] Member Methods
    // ------------------------

    void processCommand();
    void processOperationMode();
    void processCalibrationMode();
    void logUnknownCommand() const;
    void logCalibrationInitialization() const;
    void logCalibrationInProgress() const;
    void logCalibrationCompletion() const;
    void logJackStatus() const;
    void logCalibratorRawValue() const;
    void logControlChangeMessage(uint8_t cc_number,uint8_t cc_value) const;

    // --------------------------
    // [Private] Member Variables
    // --------------------------

    Mode mode;
    CommandParser parser;
    JackSwitch jack;
    Potentiometer pot;
    ExpressionPedal pedal;
    Calibrator calibrator;
    MidiController midi;
};