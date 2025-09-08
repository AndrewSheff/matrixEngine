#include <stdlib.h>
#include "entity.h"
#include "screen.h"
#include "message.h"

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

object *place(object *object, coordinates new_coor, moving_type type, direction direction, int steps)
{
    if (
        ((new_coor.x >= 0 && new_coor.x <= (screen.square.x - 1)) && (new_coor.y >= 0 && new_coor.y <= (screen.square.y - 1))) &&
        (!(get_object_on_screen(&new_coor)->is_solid)) &&
        (!(get_entity_on_screen(&new_coor)->is_solid))
    )
    {
        (*object).old_coordinates = (*object).coordinates;
        (*object).coordinates = new_coor;
        update_out_move_message(type, object, steps, get_direction_label(direction));
        print_to_log(log_message);
        return object;
    }
    else 
    {
        return get_entity_on_screen(&new_coor);
    }
    
}
object *move(object *object, direction direction, int steps)
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
    return place(object, new_coor, MOVE, direction, steps);
}

void chase(object *chaser, object *target)
{
    direction sdirection1 = UNDEFINED;
    direction sdirection2 = UNDEFINED;
    int ydiff = target->coordinates.y - chaser->coordinates.y;
    int xdiff = target->coordinates.x - chaser->coordinates.x;
    if (abs(ydiff) <= abs(xdiff)) 
    {
        if (ydiff>0)
        {
            sdirection2 = DOWN;
        }
        else 
        {
            sdirection2 = UP;
        }
        if (xdiff>0)
        {
            sdirection1 = RIGHT;
        }
        else
        {
            sdirection1 = LEFT;
        }
    }
    else
    {
        if (ydiff>0)
        {
            sdirection1 = DOWN;
        }
        else 
        {
            sdirection1 = UP;
        }
        if (xdiff>0)
        {
            sdirection2 = RIGHT;
        }
        else
        {
            sdirection2 = LEFT;
        }
    }

    object *move_result = move(chaser, sdirection1, 1);
    if (move_result == chaser || move_result == target) 
    {
        return;
    }
    move_result = move(chaser, sdirection2, 1);
    if (move_result == chaser || move_result == target) 
    {
        return;
    }

    for (int i = 0; i < UNDEFINED; i++) {
        direction current_dir = (sdirection2 + i) % UNDEFINED;

        move_result = move(chaser, current_dir, 1);
        
        if (move_result == chaser || move_result == target) {
            return;
        }
    }
}

