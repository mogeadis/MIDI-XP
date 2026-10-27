/**
 * @file CommandParser.cpp
 * 
 * @brief `MIDI-XP`: CommandParser Class Implementation File 
 * 
 * @author Alexandros Iliadis (https://github.com/mogeadis)
 * @version 1.0.0
 * @date October 2026
 */
#include "CommandParser.h"

#include "Logger.h"

// -----------------------------------------
// [Public] Constructor & Destructor Methods
// -----------------------------------------

CommandParser::CommandParser()
{
    this->buffer[0] = '\0';
    this->command_length = 0;
    this->command_available = false;
    this->cr_flag = false;
}
CommandParser::~CommandParser() = default;

// -----------------------
// [Public] Member Methods
// -----------------------

void CommandParser::update()
{
    this->command_available = false;
    while(Serial.available())
    {
        char character = Serial.read();

        if(character == '\r' || character == '\n')
        {
            if(character == '\n' && this->cr_flag)
            {
                this->cr_flag = false;
                continue;
            }
            this->cr_flag = (character == '\r');
            this->buffer[this->command_length] = '\0';
            this->command_length = 0;
            this->command_available = true;
            Logger::println(character);
            return;
        }

        this->cr_flag = false;

        if(character == '\b' || character == 0x7F)
        {
            if(this->command_length > 0)
            {
                this->command_length--;
                this->buffer[this->command_length] = '\0';
                Logger::print("\b \b");
            }
            continue;
        }
        
        if(this->command_length < CommandParser::COMMAND_BUFFER_SIZE - 1)
        {
            this->buffer[this->command_length] = character;
            this->buffer[++this->command_length] = '\0';
            Logger::print(character);
        }
    }
}
bool CommandParser::empty() const
{
    return this->buffer[0] == '\0';
}
bool CommandParser::available() const
{
    return this->command_available;
}
const char* CommandParser::command() const
{
    return this->buffer;
}