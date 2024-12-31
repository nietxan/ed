#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ed.h"

#define INPUT_SIZE 4096

void strtrim(char *s)
{
	char * p = s;
	int l = strlen(p);

	while(isspace(p[l - 1])) p[--l] = 0;
	while(*p && isspace(*p)) ++p, --l;

	memmove(s, p, l + 1);
}

int chrcount(char *input, char chr)
{
	int count = 0;
	char *ptr = input;
	while ((ptr = strchr(ptr, chr)) != NULL) {
		count++;
		ptr++;
	}
	return count;
}

/* Main loop with command processing */	

size_t ed(FILE *f)
{
	char *fn;
	char *temp;
	char *input;
	char *cmd[2];

	for (;;) {
		input = (char*)malloc(INPUT_SIZE * sizeof(char));
		cmd[0] = "?";
		cmd[1] = "";

		fgets(input, INPUT_SIZE, stdin);
		if (strcmp(input, "\n")) {
			strtrim(input);

			switch (chrcount(input, ' ')) {
				case 0:
					if (strlen(input) == 1)
						cmd[0] = input;
				case 1:
					/* TODO: more advanced cmd processing */
					temp = strtok(input, " ");
					if (strlen(temp) == 1) {
						cmd[0] = temp;
						cmd[1] = strtok(NULL, " ");
					}
			}
		}

		switch ((int)(*cmd[0])) {
			case 'q':
				if (cmd[1] == NULL) {
					return 0;
				}
			case 'a':
				;
			case 'i':
				;
			case 'e':
				;
			case 'r':
				;
			case 'f':
				if (cmd[1] != NULL) {
					fn = cmd[1];
					f = fopen(fn, "a+");
					if (f != NULL) {
						printf("%d\n", fcount(f));
						break;
					}
				}

				if (f != NULL) {
					fn = fname(f);
					if (fn != NULL) {
						printf("%s\n", fn);
						free(fn);
						break;
					}
				}
			case 'w':
				;
			default:
				printf("?\n");
				free(input);
		}
	}
}
