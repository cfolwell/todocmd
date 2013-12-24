#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "include/todo_io/todocmd.h"
#include "include/debug/debug.h"

void todo_list_handler(cmd_obj *cmd)
{
	switch(cmd->sub_command) {
		case 'p':
			priority_list(cmd);
			break;
		case 't':
			tag_list(cmd);
			break;
		case 'd':
			done_list(cmd);
			break;
		case 'a':
			archive_list(cmd);
			break;
		case 's':
		default:
			default_list(cmd);
			break;
	}

	exit(EXIT_SUCCESS);
}

void default_list(cmd_obj *cmd)
{
	FILE *todo_file;
	char buffer[MAX_ARGS];
	int cnt = 1;
	int i = 0;

	printf("Default List\n");
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

	exit(EXIT_SUCCESS);
}

/* TODO: print out todos by priority */
void priority_list(cmd_obj *cmd)
{
	FILE *todo_file;
	char buffer[MAX_ARGS];
	int cnt = 1;
	int i = 0;

	printf("Priority List\n");
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

	exit(EXIT_SUCCESS);
}

/* TODO: print out todos by selected tag */
void tag_list(cmd_obj *cmd)
{
	FILE *todo_file;
	char buffer[MAX_ARGS];
	int cnt = 1;
	int i = 0;

	printf("Tag List\n");
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

	exit(EXIT_SUCCESS);
}

void done_list(cmd_obj *cmd)
{
	FILE *todo_file;
	char buffer[MAX_ARGS];
	int cnt = 1;
	int i = 0;

	printf("Done List\n");
	todo_file = fopen(cmd->todo_filename, "r+");
	assert(todo_file);

	while((i = fgets(buffer, sizeof(buffer), todo_file) != NULL)) {
		if(i == 1 && buffer[1] == 'x') {
			printf("%d: ", cnt);
			cnt ++;
		}
		if(buffer[1] == 'x') {
			printf("%s", buffer);
		}
	}
	
	/* Memory Management */
	fclose(todo_file);
	free(cmd->todo);
	free(cmd);

	exit(EXIT_SUCCESS);
}

void archive_list(cmd_obj *cmd)
{
	FILE *todo_file;
	char buffer[MAX_ARGS];
	int cnt = 1;
	int i = 0;

	printf("Archive List\n");
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

	exit(EXIT_SUCCESS);
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
	
	exit(EXIT_SUCCESS);
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

	exit(EXIT_SUCCESS);
}
