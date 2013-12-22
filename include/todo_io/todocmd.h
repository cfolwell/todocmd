#ifndef _todocmd_h
#define _todocmd_h

#include "todo_obj.h"
#include "cmd_obj.h"

/* File Input Functions */
void todo_add(cmd_obj *cmd);

/* File Output Functions */
void todo_list(cmd_obj *cmd);
void todo_done(cmd_obj *cmd);
void todo_remove(cmd_obj *cmd);

/* Additional Functions */
void todo_help(cmd_obj *cmd);

#endif
