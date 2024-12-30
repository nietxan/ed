#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 1024

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

int ed(FILE *f)
{
	char c;
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
					temp = strtok(input, " ");
					/* TODO: more advanced cmd processing */
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
				;
			case 'w':
				;
			default:
				printf("?\n");
				free(input);
		}
	}
}
