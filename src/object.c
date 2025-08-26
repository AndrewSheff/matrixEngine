#include "object.h"

char* get_direction_label(direction direction) 
{
    switch (direction)
    {
    case UP:
        return "вверх";
        break;
    case DOWN:
        return "вниз";
        break;
    case LEFT:
        return "влево";
        break;
    case RIGHT:
        return "вправо";
        break;
    default:
        return "неопределенно";
        break;
    }
}

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

object player = {.name="Игрок", .value = '@', .bgcolor = -1, .color = 226, .is_solid = false};

object empty = { .name = "Пустота", .id = ' ', .is_solid = false, .value = ' ', .color = 0, .bgcolor = 0};

object floor_concrete = { .name = "Бетонный пол", .id = '1', .is_solid = false, .value = ' ', .color = 7, .bgcolor = 7};

object wall_concrete = { .name = "Бетонная стена", .id = '2', .is_solid = true, .value = '#', .color = 7, .bgcolor = 8};