#include <stdint.h>
#include <stdio.h>
#include <string.h>

int fcount(FILE *f)
{
	char c;
	int count;

	while (1) {
		c = fgetc(f);
		if (c == EOF)
			break;
		++count;
	}		

	return count;
}

FILE *f;
char *fname;
char fbuf[2048];

int main(int argc, char **argv)
{
	if (argc > 1) {
		fname = argv[1];
		f = fopen(fname, "w+");
		if (f == NULL) {
			fprintf(stderr, "file error\n");
			return 1;
		}
		printf("%d\n", fcount(f));
	}

	char input;
	char buf[1024];

	while (1) {
		scanf("%c", &input);
		switch (input) {
			case 'a':
				while (1) {
					scanf("%s", buf);
					if (!strcmp(buf, ".")) {
						break;
					}
					strcat(fbuf, buf);
				}
				break;
			case 'w':
				printf("%d\n", fprintf(f, "%s\n", fbuf));
				break;
			case 'q':
				fclose(f);
				return 0;
		}
	}
}
