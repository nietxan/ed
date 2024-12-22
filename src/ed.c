#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int fcount(FILE *f)
{
	char c;
	int count;

	for (;;) {
		c = fgetc(f);
		if (c == EOF)
			break;
		++count;
	}		

	return count;
}

int main(int argc, char **argv)
{
	FILE *f;
	char *fname;
	// TODO: with dynamic array
	char fbuf[4096];

	if (argc > 1) {
		fname = argv[1];
		f = fopen(fname, "a+");
		if (f == NULL) {
			fprintf(stderr, "file error\n");
			return 1;
		}
		printf("%d\n", fcount(f));
	}

	char input;
	// TODO: with dynamic array
	char buf[1024];

	for (;;) {
		scanf("%c", &input);
		switch (input) {
			case 'a':
				for (;;) {
					scanf("%s", buf);
					if (!strcmp(buf, ".")) {
						break;
					}
					strncat(fbuf, buf, sizeof(fbuf) - strlen(fbuf) - 1);
					strcat(fbuf, "\n");	
				}
				break;
			case 'w':
				printf("%d\n", fprintf(f, "%s", fbuf));	
				fclose(f);
				break;
			case 'q':
				return 0;
		}
	}
}
