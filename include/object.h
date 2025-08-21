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
    coordinates old_coordinates;
    coordinates coordinates;
    bool is_solid;
    int color;
    int bgcolor;
    char value;
} object;

extern object player;
extern object empty;

#endif