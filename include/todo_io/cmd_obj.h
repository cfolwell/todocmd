#ifndef _cmd_obj_h
#define _cmd_obj_h

#include "todo_obj.h"

#ifndef MAX_ARGS
#define MAX_ARGS 1000
#endif

typedef struct {
	todo_obj *todo;
	char command;
	char *todo_filename;
	char *done_filename;
	int arg_cnt;
} cmd_obj;

void create_command(int argc, char *argv[]);
void command_executor(cmd_obj *cmd);

#endif
