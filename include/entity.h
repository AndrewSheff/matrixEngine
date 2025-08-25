#ifndef ENTITY_H
#define ENTITY_H

#include "object.h"

typedef enum
{
	SPAWN,
	MOVE,
	TELEPORTED,
	PUSHED,
} moving_type;

extern object **entities;
extern int entities_size;

void init_entities(void);
void add_entity(object *entity);
int place(object *object, coordinates new_coor, moving_type type, direction direction, int steps);
int move(object *object, direction direction, int steps);

#endif