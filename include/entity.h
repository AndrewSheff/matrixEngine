#ifndef ENTITY_H
#define ENTITY_H

#include "object.h"

extern object **entities;
extern int entities_size;

void init_entities(void);
void add_entity(object *entity);
int place(object *object, coordinates new_coor);
int move(object *object, direction direction, int steps);

#endif