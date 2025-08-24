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

struct log_struct
{
    coordinates begin_coordinates;
    int empty_rows;
    char *text; 
    //TODO координата курсора еще нужна
};

extern struct screen_struct screen;
extern struct log_struct log_field;
extern coordinates scene_begin_coordinates;

object *get_object_on_screen(coordinates *coordinates);
void init_screen(void);
void update_screen(void);
void set_scene(scene_struct *scene);
void print_to_log(char* text);
void print(object *object, int y, int x);
void update(void);

#endif