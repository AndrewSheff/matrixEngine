#ifndef SCREEN_H
#define SCREEN_H

#include "object.h"
#include "scene.h"

struct screen_struct
{
    coordinates square;
    scene_struct *scene;
    object ***matrix;
};

extern struct screen_struct screen;

object *get_object_on_screen(coordinates *coordinates);
void init_screen(void);
void update_screen(void);
void set_scene(scene_struct *scene);
void print(object *object);
void update(void);

#endif