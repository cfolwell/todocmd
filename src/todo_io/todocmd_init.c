#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "include/todo_io/todocmd.h"
#include "include/todo_logic/sort.h"
#include "include/debug/debug.h"

int main(int argc, char *argv[])
{
	/* Check for User Input */
	switch (argc) {
		case 0:
		case 1:
			printf("[TODOCMD]: ERROR - No Input Recieved.\n");
			break;
		default:
			/* Create cmd_obj, Execute Command */
			create_command(argc, argv);
	}

        exit(EXIT_SUCCESS);
}
