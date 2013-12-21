#ifndef _todo_obj_h
#define _todo_obj_h

#ifndef MAX_ARGS
#define MAX_ARGS 1000
#endif

typedef struct {
	char *todo_body[MAX_ARGS];
	int priority;
	char *tags[MAX_ARGS];
	int tag_cnt;
} todo_obj;

todo_obj* create_todo(int arg_cnt, char *argv[], char *todo_filename);
int todo_parse(char *str);
int set_priority(int cnt, char *argv[]);
void set_tags(int cnt, int arg_cnt, char *argv[], todo_obj *todo);

#endif
