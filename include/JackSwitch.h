/**
 * @file JackSwitch.h
 * 
 * @brief `MIDI-XP`: JackSwitch Class Header File 
 * 
 * @author Alexandros Iliadis (https://github.com/mogeadis)
 * @version 1.0.0
 * @date October 2026
 */
#pragma once

#include <stdint.h>

#include "Debouncer.h"

class JackSwitch
{
    public:

    // -----------------------------------------
    // [Public] Constructor & Destructor Methods
    // -----------------------------------------

    JackSwitch() = delete;
    JackSwitch(uint8_t pin,uint16_t debounce_time);
    ~JackSwitch();

    // -----------------------
    // [Public] Member Methods
    // -----------------------

    void init();
    void update();
    bool changed() const;
    bool connected() const;

    private:

    // --------------------------
    // [Private] Member Variables
    // --------------------------

    uint8_t pin;
    Debouncer debouncer;
};