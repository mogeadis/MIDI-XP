/**
 * @file CommandParser.h
 * 
 * @brief `MIDI-XP`: CommandParser Class Header File 
 * 
 * @author Alexandros Iliadis (https://github.com/mogeadis)
 * @version 1.0.0
 * @date October 2026
 */
#pragma once

#include <stdint.h>

#include "Configuration.h"

class CommandParser
{
    public:

    // -----------------------------------------
    // [Public] Constructor & Destructor Methods
    // -----------------------------------------

    CommandParser();
    ~CommandParser();

    // -----------------------
    // [Public] Member Methods
    // -----------------------

    void update();
    bool empty() const;
    bool available() const;
    const char* command() const;

    private:

    // --------------------------
    // [Private] Static Variables
    // --------------------------
    
    static constexpr uint8_t COMMAND_BUFFER_SIZE = sizeof(cfg::PARSER_CALIBRATION_COMMAND);

    // --------------------------
    // [Private] Member Variables
    // --------------------------

    char buffer[COMMAND_BUFFER_SIZE];
    uint8_t command_length;
    bool command_available;
    bool cr_flag;
};