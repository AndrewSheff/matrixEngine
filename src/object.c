#include "object.h"

object player = {.coordinates.x = 0, .coordinates.y = 0, .value = '@', .bgcolor = -1, .color = 226, .is_solid = true};

object empty = {.is_solid = false, .value = ' ', .color = 0, .bgcolor = -1};