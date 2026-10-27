/**
 * @file JackSwitch.cpp
 * 
 * @brief `MIDI-XP`: JackSwitch Class Implementation File 
 * 
 * @author Alexandros Iliadis (https://github.com/mogeadis)
 * @version 1.0.0
 * @date October 2026
 */
#include "JackSwitch.h"

#include <Arduino.h>

// -----------------------------------------
// [Public] Constructor & Destructor Methods
// -----------------------------------------

JackSwitch::JackSwitch(uint8_t pin,uint16_t debounce_time) : debouncer(debounce_time)
{
    this->pin = pin;
}
JackSwitch::~JackSwitch() = default;

// -----------------------
// [Public] Member Methods
// -----------------------

void JackSwitch::init()
{
    pinMode(this->pin,INPUT_PULLUP);
    this->debouncer.init(digitalRead(this->pin));
}
void JackSwitch::update()
{
    this->debouncer.update(digitalRead(this->pin));
}
bool JackSwitch::changed() const
{
    return this->debouncer.changed();
}
bool JackSwitch::connected() const
{
    return (this->debouncer.state() == HIGH);
}