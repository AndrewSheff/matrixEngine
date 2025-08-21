#ifndef SCREEN_H
#define SCREEN_H

#include "object.h"

struct screen_struct
{
    coordinates square;
    object ***matrix;
};

extern struct screen_struct screen;

object *get_object_on_screen(coordinates *coordinates);
void init_screen(void);
void print(object *object);
void update(void);

#endif