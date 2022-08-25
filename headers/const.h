#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "SFML\Graphics.hpp"
#include "..\headers\cell.h"
#include "..\headers\car.h"



// WINDOW
const unsigned int SCREEN_WIDTH = 1400;
const unsigned int SCREEN_HEIGHT = 900;

// GRID
const unsigned int ROWS = 60;
const unsigned int COLS = 75;

// CELLS FOR GRID
const float CELL_SIZE = 10.f;
const float CELL_SPACE = 1.f;
const int INIT_POS = (CELL_SPACE * 2) + CELL_SIZE;
const int xINIT_SPACE = 100;
const int yINIT_SPACE = 50;







