#pragma once

// CSCN71030 - winter 2023
// Author: Nicolas Masquieto
// 
// Interface for display functions

#include "participant.h"
#include <stdio.h>

// Displays a menu of variable size.
// Every new prompt is another line.
void DisplayMenu(int, char[], ...);

// Displays sort form of tournment bracket.
void DisplayTournament_Short(PARTICIPANT[], size_t);
// Displays full form tournament graph.
void DisplayTournament_Full(PARTICIPANT[], size_t);