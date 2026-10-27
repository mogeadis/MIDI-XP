/**
 * @file MidiController.cpp
 * 
 * @brief `MIDI-XP`: MidiController Class Implementation File 
 * 
 * @author Alexandros Iliadis (https://github.com/mogeadis)
 * @version 1.0.0
 * @date October 2026
 */
#include "MidiController.h"

#include <MIDIUSB.h>

// -----------------------------------------
// [Public] Constructor & Destructor Methods
// -----------------------------------------

MidiController::MidiController(uint8_t channel)
{
    this->channel = channel;
}
MidiController::~MidiController() = default;

// ----------------------
// [Public] Member Methods
// ----------------------

uint8_t MidiController::getChannel() const
{
    return this->channel;
}
void MidiController::sendControlChange(uint8_t cc_number,uint8_t cc_value) const
{
    midiEventPacket_t event = {static_cast<uint8_t>(0x0B),static_cast<uint8_t>(0xB0 | (this->channel - 1)),cc_number,cc_value};
    MidiUSB.sendMIDI(event);
    MidiUSB.flush();
}