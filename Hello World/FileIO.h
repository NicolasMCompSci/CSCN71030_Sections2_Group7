#pragma once
// CSCN71030 - winter 2023
// Group Project - Tournament Bracket Generator
// Nicolas Masquieto, Ethan Groen, Louis He
// 
// Interface to the file saving and loading functions

#include "organize.h"

// saves file. char[] is file name
void Save(PARTICIPANT[], char[]);
// loads file with char[] name
PARTICIPANT* Load(char[]);