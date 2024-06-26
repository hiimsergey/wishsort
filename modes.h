#ifndef MODES_H
#define MODES_H

#include "item.h"

// Handles user input to fill the list. Returns 0 if the program should proceed
// with sorting, 1 if the program should free memory and quit.
unsigned short insert_mode(Item *items);

// Handles user input to sort the given list.
void sort_mode(Item *items);

#endif
