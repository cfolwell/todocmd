#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "include/todo_io/todocmd.h"
#include "include/debug/debug.h"

void todo_add(cmd_obj *cmd)
{
	#ifdef DEBUG
	prt_info(2, "todo_add");
	#endif

	FILE *todo_file;
	char buffer[MAX_ARGS];
	int i;

	/* Failure to run if todo_body[0] is null */
	if(!cmd->todo->todo_body[0])
		exit(EXIT_FAILURE);

	
	/* Open todo_file, insure successful opening */
	todo_file = fopen(cmd->todo_filename, "a");
	assert(todo_file);

	/* Write todo_body to todo_file */
	for(i = 0; i < cmd->arg_cnt; i++) {
		if(cmd->todo->todo_body[i]) {
			fputs(cmd->todo->todo_body[i], todo_file);
			fputs(" ", todo_file);
		}
	}
	/* Write priority to todo_file */
	if(cmd->todo->priority > 0) {
		sprintf(buffer, "(%d)", cmd->todo->priority);
		fputs(buffer, todo_file);
		fputs(" ", todo_file);
	}

	/* Write tags to todo_file */
	if(cmd->todo->tags[0])
		fputs("[", todo_file);
	for(i = 0; i < cmd->todo->tag_cnt; i++) {
		if(cmd->todo->tags[i]) {
			fputs(cmd->todo->tags[i], todo_file);
		}
		if(i+2 < cmd->todo->tag_cnt) {
			fputs(", ", todo_file);
		}
	}
	if(cmd->todo->tag_cnt > 0)
		fputs("]", todo_file);

	/* Add newline to todo.txt */
	fputs("\n", todo_file);

	/* TODO: make console out function - debug */

	/* Memory Clean-Up */
	fclose(todo_file);
	free(cmd->todo);
	free(cmd);

	#ifdef DEBUG
	prt_info(3, "todo_add");
	#endif

	exit(EXIT_SUCCESS);
}
