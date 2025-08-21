#include <stdlib.h>
#include "entity.h"
#include "screen.h"

object **entities;
int entities_size;

void init_entities()
{
    entities_size = 1;
    entities = calloc(1, sizeof(object *));
    extern object player;
    entities[0] = &player;
}

void add_entity(object *entity)
{
    entities_size++;
    entities = realloc(entities, entities_size * sizeof(object *));
    entities[entities_size - 1] = entity;
}

int place(object *object, coordinates new_coor)
{
    if (
        ((new_coor.x >= 0 && new_coor.x <= (screen.square.x - 1)) && (new_coor.y >= 0 && new_coor.y <= (screen.square.y - 1))) &&
        (!(get_object_on_screen(&new_coor)->is_solid)))
    {
        (*object).old_coordinates = (*object).coordinates;
        (*object).coordinates = new_coor;
    }
    return 0;
}
int move(object *object, direction direction, int steps)
{
    coordinates new_coor = (*object).coordinates;
    switch (direction)
    {
    case UP:
        new_coor.y = new_coor.y-steps;
        break;
    case DOWN:
        new_coor.y = new_coor.y+steps;
        break;
    case RIGHT:
        new_coor.x = new_coor.x+steps;
        break;
    case LEFT:
        new_coor.x = new_coor.x-steps;
        break;
    default:
        break;
    }
    place(object, new_coor);
    return 0;
}