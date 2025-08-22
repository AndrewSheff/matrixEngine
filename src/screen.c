#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "screen.h"
#include "entity.h"

struct winsize w;
struct screen_struct screen = {};

object *get_object_on_screen(coordinates *coordinates)
{
    return screen.matrix[coordinates->y][coordinates->x];
}

void print(object *object)
{
    if (object->bgcolor == -1)
    {
        printf("\033[48;5;%dm\033[38;5;%dm%c\033[0m", get_object_on_screen(&(object->coordinates))->bgcolor, object->color, object->value);
    }
    else
    {
        printf("\033[48;5;%dm\033[38;5;%dm%c\033[0m", object->bgcolor, object->color, object->value);
    }
}

void init_screen(void)
{
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    screen.square.x = w.ws_col;
    screen.square.y = w.ws_row - 3;
    screen.matrix = calloc(w.ws_row - 3, sizeof(object **));
    printf("\033[3J");
    printf("\033[H");
    for (int i = 0; i < screen.square.y; i++)
    {
        screen.matrix[i] = calloc(w.ws_col, sizeof(object *));
        for (int j = 0; j < screen.square.x; j++)
        {
            screen.matrix[i][j] = &empty;
            print(screen.matrix[i][j]);
        }
    }
}

void update_screen(void)
{
    printf("\033[3J");
    printf("\033[H");
    for (int i = 0; i < screen.square.y; i++)
    {
        for (int j = 0; j < screen.square.x; j++)
        {
            print(screen.matrix[i][j]);
        }
    }
}

void set_scene(scene_struct *scene)
{
    int ybegin = (screen.square.y - scene->square.y) / 2;
    int xbegin = (screen.square.x - scene->square.x) / 2;
    for (int i = 0; i < scene->square.y; i++)
    {
        for (int j = 0; j < scene->square.x; j++)
        {
            screen.matrix[ybegin + i][xbegin + j] = scene->matrix[i][j];
        }
    }
    screen.scene = scene;
    update_screen();
}

void update(void)
{
    for (int i = 0; i < entities_size; i++)
    {
        printf("\033[%d;%dH", entities[i]->old_coordinates.y + 1, entities[i]->old_coordinates.x + 1);
        print(get_object_on_screen(&(entities[i]->coordinates)));
        printf("\033[%d;%dH", entities[i]->coordinates.y + 1, entities[i]->coordinates.x + 1);
        print(entities[i]);
    }
    printf("\033[%d;1H", w.ws_row - 1);
}

// полное обновление экрана
//  void print(object* object) {
//      printf("\033[38;5;%dm%c", object->color, object->value);
//  }

// void update(void) {
//     printf("\033[3J\033[48;5;%dm", screen.background_color);
//     printf("\033[H");
//     for (int i=0;i<screen.square.y;i++) {
//         for (int j=0;j<screen.square.x;j++) {
//             print(screen.matrix[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\033[0m");
// }
