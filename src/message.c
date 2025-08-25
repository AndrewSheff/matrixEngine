#include "message.h"

char* log_message[100];

void update_out_move_message(moving_type type, object *object, int steps, char* direction)
{
	switch (type)
	{
		case MOVE: 
			snprintf(log_message, sizeof log_message, "%s переместился на %d клеток %s", object->name, steps, direction);
			break;
		case SPAWN:
			snprintf(log_message, sizeof log_message, "%s появился", object->name);
			break;
		case TELEPORTED:
			snprintf(log_message, sizeof log_message, "%s телепортировался", object->name);
			break;
		case PUSHED:
			snprintf(log_message, sizeof log_message, "%s был отброшен на %d клеток %s", object->name, steps, direction);
			break;
		default: 
			break;
	}
};


// char* int_to_string(int integer)
// {
// 	char* output[3];
// 	snprintf(output, sizeof output, "%d", integer);
// 	return output;
// }