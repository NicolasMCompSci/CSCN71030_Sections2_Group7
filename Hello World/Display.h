#pragma once

// CSCN71030 - winter 2023
// Author: Nicolas Masquieto
// 
// Interface for display functions

#include "Participant.h"
#include <stdio.h>

// Displays a menu of variable size.
// Every new prompt is another line.
void DisplayMenu(int, char[], ...);

// Displays the tournment bracket.
void DisplayTournament_Short(PARTICIPANT[], size_t);