#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdio.h>
#include "entity.h"
#include "object.h"

extern char* log_message[100];

void update_out_move_message(moving_type type, object *object, int steps, char* direction);
// char* int_to_string(int integer);

#endif