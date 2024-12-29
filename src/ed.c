#include <stdio.h>
#include <string.h>

/* Main loop with command processing */	

int ed(FILE *f)
{
	// TODO: put in for (;;) {}
	char input[1024];
	
	fgets(input, 1024, stdin);

	char *cmd[2];

	int count = 0;
	char *ptr = input;
	while((ptr = strchr(ptr, ' ')) != NULL) {
		count++;
		ptr++;
	}

	if (count != 1)
		cmd[0] = "?";
	else {
		for (int i = 0; i < 2; ++i)
			cmd[i] = strtok(input, " ");
	}
	
	if (strlen(cmd[0]) != 1)
		cmd[0] = "?";

	switch ((char)(*cmd[0])) {
		// TODO: cases		
		case '?':
			printf("?\n");
			break;
	}


	return 0;
}
