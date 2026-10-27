/**
 * @file Utilities.cpp
 * 
 * @brief `MIDI-XP`: Utilities Namespace Implementation File 
 * 
 * @author Alexandros Iliadis (https://github.com/mogeadis)
 * @date October 2026
 */
#include "Utilities.h"

#include <ctype.h>

// ----------------
// String Utilities
// ----------------

bool utils::stringsAreEqual(const char* str1,const char* str2,bool ignore_case)
{
    while(*str1 && *str2)
    {
        char char1 = *str1;
        char char2 = *str2;

        if(ignore_case)
        {
            char1 = tolower(static_cast<unsigned char>(char1));
            char2 = tolower(static_cast<unsigned char>(char2));
        }

        if(char1 != char2)
        {
            return false;
        }

        str1++;
        str2++;
    }
    return *str1 == *str2;
}