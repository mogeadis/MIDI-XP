/**
 * @file main.cpp
 * 
 * @brief `MIDI-XP`: Main File 
 * 
 * @author Alexandros Iliadis (https://github.com/mogeadis)
 * @date October 2026
 */
#include <Arduino.h>

#include "Application.h"

static Application app;

void setup()
{
    app.begin();
}

void loop()
{
    app.process();
}