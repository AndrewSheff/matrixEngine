#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdio.h>

typedef enum
{
	MOVE1,
} message_type;

char* get_message_by_type(message_type type);

char* form_message(char* message, ...);

#endif