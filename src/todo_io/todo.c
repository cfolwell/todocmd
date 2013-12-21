#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "include/todo_io/todo_obj.h"
#include "include/debug/debug.h"

/* TODO: allow functions to update data, too */
/* TODO: add debugging functions */
todo_obj* create_todo(int arg_cnt, char *argv[], char *todo_filename)
{
	/* If no command exists, exit */
	if(arg_cnt < 0) {
		exit(EXIT_FAILURE);
	}
	
	int i = 0;
	int cont = 1;

	todo_obj *todo = malloc(sizeof(todo_obj));
	assert(todo);

	/* TODO: allow tags to be added before priority... */
	todo->tag_cnt = 0;
	for(i = 0; i < arg_cnt; i++) {
		if(todo_parse(argv[i+2]) == 1) {
			printf("adding priority\n");
			todo->priority = set_priority(i, argv);
			cont = 0;
		} else if(todo_parse(argv[i+2]) == 2) {
			printf("adding tags\n");
			set_tags(i, arg_cnt, argv, todo);
			cont = 0;
		}

		if(cont) {
			todo->todo_body[i] = argv[i+2];
		}
	}

	return todo;
}

int todo_parse(char *str)
{
	if(strcmp(str, "-p") == 0) {
		return 1;
	} else if(strcmp(str, "-t") == 0) {
		return 2;
	} else {
		return 0;
	}
}

int set_priority(int cnt, char *argv[])
{
	if(argv[cnt+3]) {
		int priority;
		priority = atoi(argv[cnt+3]);

		return priority;
	} else {
		return -1;
	}
}

void set_tags(int cnt, int arg_cnt, char *argv[], todo_obj *todo)
{
	int i = 0;
	int tmp = 0;

	for(; cnt < arg_cnt; cnt++, i++) {
		if(todo_parse(argv[cnt+2]) == 1)
			break;
			
		if(argv[cnt+3] && todo_parse(argv[cnt+3]) != 1)
			todo->tags[i] = argv[cnt+3];
	}

	todo->tag_cnt = i;
}
