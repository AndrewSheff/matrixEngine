#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "screen.h"
#include "entity.h"

struct winsize w;
struct screen_struct screen = {};
struct log_struct log_field;

coordinates scene_begin_coordinates = {.y=0, .x=0};

object *get_object_on_screen(coordinates *coordinates)
{
    return screen.matrix[coordinates->y][coordinates->x];
}

void print(object *object, int y, int x)
{
    if (object->bgcolor == -1)
    {
        printf("\033[%d;%dH\033[48;5;%dm\033[38;5;%dm%c\033[0m", y, x, get_object_on_screen(&(object->coordinates))->bgcolor, object->color, object->value);
    }
    else
    {
        printf("\033[%d;%dH\033[48;5;%dm\033[38;5;%dm%c\033[0m", y, x, object->bgcolor, object->color, object->value);
    }
}

void init_screen(void)
{
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    screen.square.x = w.ws_col - w.ws_col/4; //четверть экрана для лога
    screen.square.y = w.ws_row - 3; //3 строки для ввода
    log_field.begin_coordinates.x = screen.square.x + 2;
    log_field.begin_coordinates.y = 1;
    log_field.text = calloc(screen.square.y, w.ws_col-log_field.begin_coordinates.x); //(высота лога, ширина лога)
    screen.matrix = calloc(w.ws_row - 3, sizeof(object **));
    printf("\033[3J");
    printf("\033[H");
    for (int i = 0; i < screen.square.y; i++)
    {
        screen.matrix[i] = calloc(screen.square.x, sizeof(object *));
        for (int j = 0; j < screen.square.x; j++)
        {
            screen.matrix[i][j] = &empty;
            print(screen.matrix[i][j], i+1, j+1);
        }
    }
    printf("\033[%d;%dH%s", log_field.begin_coordinates.y, log_field.begin_coordinates.x, "-НАЧАЛО ЛОГА- я пишу здесь всякую хуйню всякую поеботу короче вот");
}

void update_screen(void)
{
    printf("\033[3J");
    printf("\033[H");
    for (int i = 0; i < screen.square.y; i++)
    {
        for (int j = 0; j < screen.square.x; j++)
        {
            print(screen.matrix[i][j], i+1, j+1);
        }
    }
}

void set_scene(scene_struct *scene)
{
    scene_begin_coordinates.y = (screen.square.y - scene->square.y) / 2;
    scene_begin_coordinates.x = (screen.square.x - scene->square.x) / 2;
    for (int i = 0; i < scene->square.y; i++)
    {
        for (int j = 0; j < scene->square.x; j++)
        {
            screen.matrix[scene_begin_coordinates.y + i][scene_begin_coordinates.x + j] = scene->matrix[i][j];
        }
    }
    screen.scene = scene;
    update_screen();
}

void update(void)
{
    for (int i = 0; i < entities_size; i++)
    {
        print(get_object_on_screen(&(entities[i]->old_coordinates)), entities[i]->old_coordinates.y + 1, entities[i]->old_coordinates.x + 1);
        print(entities[i], entities[i]->coordinates.y + 1, entities[i]->coordinates.x + 1);
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
