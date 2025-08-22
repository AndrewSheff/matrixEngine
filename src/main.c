#include <stdio.h>
#include <stdlib.h>
#include "object.h"
#include "screen.h"
#include "entity.h"
#include "scene.h"

direction get_direction(char c)
{
    switch (c)
    {
    case 'w':
        return UP;
    case 'a':
        return LEFT;
    case 's':
        return DOWN;
    case 'd':
        return RIGHT;
    default:
        return ERROR;
    }
}

void process_input(char *action)
{
    switch (action[0])
    {
    case 'w':
        move(&player, UP, 1);
        break;
    case 'a':
        move(&player, LEFT, 1);
        break;
    case 's':
        move(&player, DOWN, 1);
        break;
    case 'd':
        move(&player, RIGHT, 1);
        break;
    case 'A':
        // attack(&player, get_direction(action[1]));
    default:
        if (get_direction(action[0])!=ERROR) {
            move(&player, get_direction(action[0]), 1);
        }
        break;
    }
}

int main(void)
{
    printf("\033[2J");

    init_screen();
    init_scene(&scene_one, scene_one_pattern);
    set_scene(&scene_one);
    init_entities();
    player.coordinates.y = scene_begin_coordinates.y + 2;
    player.coordinates.x = scene_begin_coordinates.x + 2;
    place(&player, player.coordinates);
    update();

    char *action;

    while (1)
    {
        action = calloc(5, sizeof(char));
        scanf("%s", action);
        printf("\033[A\033[K");
        process_input(action);
        update();
        free(action);
    }
    return 0;
}