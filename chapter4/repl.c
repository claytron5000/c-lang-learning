#include <stdio.h>
#include <stdlib.h>

/* If we are compiling on Windows */
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* Fake readline function */
char* readline(char* prompt) {
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);
	char* cpy = malloc(strlen(buffer)+1);
	strcpy(cpy, buffer);
	cpy[strlen(cpy)-1] = '\0';
	return cpy;
}

/* Fake history */
void add_history(char* unused) {}

/* Otherwise inlcude the editline headers */
#else
#include <editline/readline.h>
#endif

int main(int argc, char** argv) {
	puts("Lispy Version 0.0.0.0.1");
	puts("Press Ctrl+c to Exit\n");

	/* Neverending loop*/
	while(1) {
		char* input = readline("lispy> ");

		add_history(input);

		printf("No you're a %s\n", input);

		free(input);
	}
	return 0;
}
