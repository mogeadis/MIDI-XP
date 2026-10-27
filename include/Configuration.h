/**
 * @file Configuration.h
 * 
 * @brief `MIDI-XP`: Configuration Namespace File 
 * 
 * @author Alexandros Iliadis (https://github.com/mogeadis)
 * @version 1.0.0
 * @date October 2026
 */
#pragma once

#include <stdint.h>

namespace cfg
{
    // ----------------------------
    // Command Parser Configuration
    // ----------------------------

    constexpr char PARSER_CALIBRATION_COMMAND[] = "CALIBRATE";

    // ------------------------------
    // Expression Pedal Configuration
    // ------------------------------

    constexpr uint8_t PEDAL_CC_MIN = 0;
    constexpr uint8_t PEDAL_CC_MAX = 127;
    constexpr uint16_t PEDAL_RAW_MIN = 0;
    constexpr uint16_t PEDAL_RAW_MAX = 1023;
    constexpr uint16_t PEDAL_DEADZONE = 5;
    constexpr uint16_t PEDAL_THRESHOLD = 5;

    // -------------------------
    // Jack Switch Configuration
    // -------------------------

    constexpr uint8_t JACK_PIN = 5;
    constexpr uint16_t JACK_DEBOUNCE_TIME = 300;

    // --------------------
    // Logger Configuration
    // --------------------

    constexpr uint32_t LOGGER_BAUD_RATE = 9600;
    
    // -----------------------------
    // MIDI Controller Configuration
    // -----------------------------

    constexpr uint8_t MIDI_CHANNEL = 1;
    constexpr uint8_t MIDI_CC = 4;

    // ---------------------------
    // Potentiometer Configuration
    // ---------------------------
    
    constexpr uint8_t POTENTIOMETER_PIN = 18;
}

// -----------------
// Macro Definitions
// -----------------

#define DEBUG 0