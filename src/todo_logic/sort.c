#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void sort(char *todo_filename);
{
	FILE *todo_file;
	FILE *tmp_file;
	char buffer[MAX_ARGS];
	int cnt = 1;
	int i = 0;

	todo_file = fopen(todo_filename, "w+");
	tmp_file = fopen("tmp.txt", "r+");

	fprintf(tmp_file, "%d: ", cnt);
	while((i = fgets(buffer, sizeof(buffer), todo_file) != NULL)) {
		old = cnt;
		if(i == 1) cnt++;

		if(cnt > old)
			fprintf(tmp_file, "%d: ", cnt);

		fprintf(tmp_file, "%s", buffer);
	}
}
