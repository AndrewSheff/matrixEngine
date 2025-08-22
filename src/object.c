#include "object.h"

object *get_object_by_id(char c)
{
    switch (c)
    {
    case '1':
        return &floor_concrete;
    case '2':
        return &wall_concrete;
    default:
        return &empty;
    }
}

object player = {.value = '@', .bgcolor = -1, .color = 226, .is_solid = false};

object empty = {.id = ' ', .is_solid = false, .value = ' ', .color = 0, .bgcolor = 0};

object floor_concrete = {.id = '1', .is_solid = false, .value = ' ', .color = 7, .bgcolor = 7};

object wall_concrete = {.id = '2', .is_solid = true, .value = '#', .color = 7, .bgcolor = 8};