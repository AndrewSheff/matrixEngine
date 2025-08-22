#include <stdio.h>
#include "object.h"
#include "screen.h"
#include "entity.h"
#include "scene.h"

int main(void)
{
    printf("\033[2J");

    init_screen();
    init_scene(&scene_one, &scene_one_pattern);
    set_scene(&scene_one);
    update_screen();
    init_entities();
    place(&player, player.coordinates);
    update();

    while (1)
    {
        char action;
        scanf("%c", &action);
        printf("\033[A\033[K");
        switch (action)
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
        default:
            break;
        }
        update();
    }
    return 0;
}