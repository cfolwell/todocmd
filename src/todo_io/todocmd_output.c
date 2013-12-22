#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "include/todo_io/todocmd.h"
#include "include/debug/debug.h"

void todo_list(cmd_obj *cmd)
{
	FILE *todo_file;
	char buffer[MAX_ARGS];
	int cnt = 1;
	int i = 0;

	todo_file = fopen(cmd->todo_filename, "r+");
	assert(todo_file);

	while((i = fgets(buffer, sizeof(buffer), todo_file) != NULL)) {
		if(i == 1) {
			printf("%d: ", cnt);
			cnt ++;
		}
		printf("%s", buffer);
	}
	
	/* Memory Management */
	fclose(todo_file);
	free(cmd->todo);
	free(cmd);
}

void todo_remove(cmd_obj *cmd)
{
	FILE *todo_file;
	FILE *tmp_file;
	char buffer[MAX_ARGS];
	int ln = atoi(cmd->todo->todo_body[0]);
	int cnt = 0;
	int i = 0;
	
	todo_file = fopen(cmd->todo_filename, "r");
	tmp_file = fopen("tmp.txt", "w");

	while((i = fgets(buffer, sizeof(buffer), todo_file) != NULL)) {
		if(i == 1) cnt++;
		if(cnt != ln) fprintf(tmp_file, "%s", buffer);
	}

	/* Reopen Files Change r<->w */
	fclose(todo_file);
	fclose(tmp_file);
	todo_file = fopen(cmd->todo_filename, "w");
	tmp_file = fopen("tmp.txt", "r");

	while((i = fgets(buffer, sizeof(buffer), tmp_file) != NULL)) {
		fprintf(todo_file, "%s", buffer);
	}

	/* Memory Management */
	fclose(todo_file);
	fclose(tmp_file);
	free(cmd->todo);
	free(cmd);
}

void todo_help(cmd_obj *cmd)
{
	printf("[TODOCMD] - COMMANDS:\n");
	printf("Add Todo: -a\n");
	printf("Complete Todo: -d\n");
	printf("Remove Todo: -r\n");
	printf("List Todos: -l\n");
	printf("Show Help: -h\n");
	printf("[TODOCMD] - NOTICE:\n");
	printf("View todocmd/documentation for additional information\n");
}
