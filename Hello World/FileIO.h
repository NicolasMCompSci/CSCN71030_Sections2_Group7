#pragma once
// CSCN71030 - winter 2023
// Group Project - Tournament Bracket Generator
// Nicolas Masquieto, Ethan Groen, Louis He
// 
// Interface to the file saving and loading functions

#include "participant.h"
#include <stdbool.h>

// saves participant array file
bool Save(PARTICIPANT*, int, char[]);
// loads participant array save file
bool Load(PARTICIPANT*, int*, char[]);
// checks if filename is valid
bool IsValidFileName(char[]);