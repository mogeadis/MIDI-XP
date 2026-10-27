/**
 * @file Utilities.h
 * 
 * @brief `MIDI-XP`: Utilities Namespace Header File 
 * 
 * @author Alexandros Iliadis (https://github.com/mogeadis)
 * @date October 2026
 */
#pragma once

namespace utils
{   
    // ----------------
    // String Utilities
    // ----------------

    bool stringsAreEqual(const char* str1,const char* str2,bool ignore_case = false);
};