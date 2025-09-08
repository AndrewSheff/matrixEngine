#include <stdio.h>
#include <stdlib.h>
#include "object.h"
#include "screen.h"
#include "entity.h"
#include "scene.h"

#ifdef _WIN32
#include <windows.h>

void enable_ansi_support() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hConsole, &mode);
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hConsole, mode);
}
#endif

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
		return UNDEFINED;
	}
}

void process_input(char* action)
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
		if (get_direction(action[0]) != UNDEFINED) {
			move(&player, get_direction(action[0]), 1);
		}
		break;
	}
}

int main(void)
{
#ifdef _WIN32
	enable_ansi_support();
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
#endif
	printf("\033[2J");

	init_screen();
	init_scene(&scene_one, scene_one_pattern);
	set_scene(&scene_one);
	init_entities();
	player.coordinates.y = scene_begin_coordinates.y + 2;
	player.coordinates.x = scene_begin_coordinates.x + 2;
	place(&player, player.coordinates, SPAWN, UNDEFINED, 0);
	goblin.coordinates.y = scene_begin_coordinates.y + 2;
	goblin.coordinates.x = scene_begin_coordinates.x + 7;
	place(&goblin, goblin.coordinates, SPAWN, UNDEFINED, 0);
	add_entity(&goblin);
	update();
	char* action;

	while (1)
	{
        action = calloc(5, sizeof(char));
        printf("\033[K");
        if (fgets(action, 5, stdin) != NULL)
        {
            size_t len = sizeof(action);
            if (len > 0 && action[len-1] == '\n') {
                action[len-1] = '\0';
            }
            printf("\033[A\033[K");
            process_input(action);
			chase(&goblin, &player);
            update();
        }
        free(action);
	}
	return 0;
}