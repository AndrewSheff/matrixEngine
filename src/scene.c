#include <stdlib.h>
#include "object.h"
#include "screen.h"
#include "scene.h"

scene_struct scene_one = {.square.y = 5, .square.x = 10};
char *scene_one_pattern[5] =
    {"2222222222",
     "2111111112",
     "2111121112",
     "2111111112",
     "2222222222"};

void init_scene(scene_struct *scene, char **scene_pattern)
{
    scene->matrix = calloc(scene->square.y, sizeof(object **));
    for (int i = 0; i < scene->square.y; i++)
    {
        scene->matrix[i] = calloc(scene->square.x, sizeof(object *));
        for (int j = 0; j < scene->square.x; j++)
        {
            scene->matrix[i][j] = get_object_by_id(scene_pattern[i][j]);
        }
    }
}
