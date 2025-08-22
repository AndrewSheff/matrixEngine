#ifndef OBJECT_H
#define OBJECT_H

#include <stdbool.h>

typedef enum
{
    UP,
    DOWN,
    RIGHT,
    LEFT,
    ERROR
} direction;

typedef struct
{
    int x;
    int y;
} coordinates;

typedef enum
{
    healthy,
    wounded,
    seriously_wounded,
    dead,
} health_status;

typedef enum
{
    healthy_limb,
    small_cut,
    deep_cut,
    bruise,
    fracture,
    paralysis,
    missing,
} limb_health_status;

typedef struct
{
    char *name;
    limb_health_status status;
} limb;

typedef struct
{
    health_status status;
    int pain_level;
    int consciousness_level;
    limb *limbs;
} health;

typedef struct
{
    char id;
    coordinates old_coordinates;
    coordinates coordinates;
    health health;
    bool is_entity;
    bool is_solid;
    int color;
    int bgcolor;
    char value;
} object;

object *get_object_by_id(char c);

extern object player;
extern object empty;
extern object floor_concrete;
extern object wall_concrete;

#endif