#include <stdlib.h>
#include "object.h"
#include "screen.h"
#include "scene.h"

scene_struct scene_one = {.square.y = 13, .square.x = 41};
char *scene_one_pattern[13] =
    {
    "2222222222                               ",
    "21111111122222222222222222222222222      ",
    "21111211111111111111111111111111112      ",
    "21111111122222222222222222222222212      ",
    "2222222222                      212      ",
    "                                212      ",
    "                                212      ",
    "                                212      ",
    "                            2222212222222",
    "                            2111111111112",
    "                            2111111111112",
    "                            2111111111112",
    "                            2222222222222"
};

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