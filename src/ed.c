#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ed.h"

#define INPUT_SIZE 1024

#define unknown() printf("?\n");

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
size_t ed(fstate *fs)
{
	char *temp;
	char *cmd[2];
	char input[INPUT_SIZE];

	for (;;) {
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
			case 'a':
				break;
			case 'i':
				break;
			case 'r':
				break;
			case 'w':
				break;
			case 'e':
				/* TODO */
				break;
			case 'f':
				if (cmd[1] != NULL) {
					fs->fname = cmd[1];
				}

				if (fs->fname != NULL) {
					printf("%s\n", fs->fname);
					break;
				}

				unknown();
				break;
			case 'q':
				if (cmd[1] == NULL) {
					free(fs);
					return 0;
				}
				unknown();
				break;
		}
	}
}
