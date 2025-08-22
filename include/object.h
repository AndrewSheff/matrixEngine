#ifndef OBJECT_H
#define OBJECT_H

#include <stdbool.h>

typedef enum
{
    UP,
    DOWN,
    RIGHT,
    LEFT,
} direction;

typedef struct
{
    int x;
    int y;
} coordinates;

typedef struct
{
    char id;
    coordinates old_coordinates;
    coordinates coordinates;
    bool is_solid;
    int color;
    int bgcolor;
    char value;
} object;

object* get_object_by_id(char c);


extern object player;
extern object empty;
extern object floor_concrete;
extern object wall_concrete;

#endif