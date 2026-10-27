/**
 * @file MidiController.h
 * 
 * @brief `MIDI-XP`: MidiController Class Header File 
 * 
 * @author Alexandros Iliadis (https://github.com/mogeadis)
 * @version 1.0.0
 * @date October 2026
 */
#pragma once

#include <stdint.h>

class MidiController
{
    public:

    // -----------------------------------------
    // [Public] Constructor & Destructor Methods
    // -----------------------------------------

    MidiController() = delete;
    MidiController(uint8_t channel);
    ~MidiController();

    // ----------------------
    // [Public] Member Methods
    // ----------------------

    uint8_t getChannel() const;
    void sendControlChange(uint8_t cc_number,uint8_t cc_value) const;

    private:

    // --------------------------
    // [Private] Member Variables
    // --------------------------

    uint8_t channel;
};