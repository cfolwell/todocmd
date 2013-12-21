#include <stdio.h>
#include "include/debug/debug.h"

void prt_info(int status, char *str)
{
	switch(status) {
		case 1:
			printf("Calling Function: %s\n", str);
			break;
		case 2:
			printf("Executing Function: %s\n", str);
			break;
		case 3:
			printf("Executed Function: %s\n", str);
			break;
		default:
			break;
	}
}
