#ifndef _todocmd_h
#define _todocmd_h

#include "todo_obj.h"
#include "cmd_obj.h"

/* Input Functions */
void todo_add(cmd_obj *cmd);
void todo_done(cmd_obj *cmd);

/* List Output Functions */
void todo_list_handler(cmd_obj *cmd);
void default_list(cmd_obj *cmd);
void priority_list(cmd_obj *cmd);
void tag_list(cmd_obj *cmd);
void done_list(cmd_obj *cmd);
void archive_list(cmd_obj *cmd);

/* Additional Output Functions */
void todo_remove(cmd_obj *cmd);
void todo_help(cmd_obj *cmd);

#endif
