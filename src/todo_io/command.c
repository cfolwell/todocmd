#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "include/todo_io/todocmd.h"
#include "include/debug/debug.h"

void create_command(int argc, char *argv[])
{
	cmd_obj *cmd = malloc(sizeof(cmd_obj));
	assert(cmd);

	/* TODO: Get todo.txt and done.txt from config file */
	cmd->command = argv[1][1];
	cmd->todo_filename = "todo.txt";
	cmd->done_filename = "done.txt";
	cmd->arg_cnt = argc-2;
	cmd->todo = create_todo(cmd->arg_cnt, argv, cmd->todo_filename);

	if(argv[1][2] != '\0') {
		cmd->sub_command = argv[1][2];
	} else {
		cmd->sub_command = '\0';
	}

	command_handler(cmd);

	exit(EXIT_SUCCESS);
}

void command_handler(cmd_obj *cmd)
{

	/* Execute Commands */
	switch (cmd->command) {
		case 'a':
			todo_add(cmd);
			break;
		case 'c':
		case 'd':
			todo_done(cmd);
			break;
		case 'l':
			todo_list_handler(cmd);
			break;
		case 'r':
			todo_remove(cmd);
			break;
		case 'h':
			todo_help(cmd);
			break;
		default:
			printf("[TODOCMD] ERROR: command not found\n");
			break;
	}

	exit(EXIT_SUCCESS);
}
