#pragma once

#include <iostream>
#include "my-coordinates.h"

bool check_coordinates(const coordinates& line, const double pos[]);

void scalpel(coordinates& action);

void location(coordinates& action, coordinates& check_action, std::string& command);

void suture(coordinates& action, coordinates& check_action);
