#ifndef _debug_h
#define _debug_h


/* #define DEBUG */
/* #define DEV */


#define MAJOR 0
#define MINOR 1
#define BUGFIX 0

/* Check Functions */

/* Message Functions */
void prt_info(int status, char *str);
void prt_err();
void prt_debug();

#endif
