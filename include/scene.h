#ifndef SCENE_H
#define SCENE_H

#include "object.h"

typedef struct
{
    coordinates square;
    object ***matrix;
} scene_struct;

extern scene_struct scene_one;
extern char *scene_one_pattern[13];

void init_scene(scene_struct *scene, char **scene_pattern);

#endif
