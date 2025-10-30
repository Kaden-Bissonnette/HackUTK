//task.c - main of task


#include <stdio.h>
#include <stdlib.h>
#include "phases.h"

FILE* infile;

int main(int argc, char* argv[])
{


	char * blob = malloc(sizeof(char) * (3*16));

	char * input0 = blob;
	char * input1 = blob + 16;
	char * input2 = blob + 32;
	size_t len;

	if (argc == 1){
		infile = stdin;
	}

	else if(argc == 2)
	{
		if(!(infile = fopen(argv[1], "r")))
		{
			printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
			exit(8);
		}
	}

	else
	{
		printf("Usages: %s [<input_file>]\n", argv[0]);
		exit(8);
	}

	printf("Welcome to your task, there are three phases to this task\n");
	printf("You must provide the appropriate input for each phase of this task\n");
	printf("It is recommended that you keep track of the flags from each phase\n\n");


	getline(&input0, &len, infile);
	phase_1(input0);

	printf("Congratulations you passed phase 1\n");

	getline(&input1, &len, infile);
	phase_2(input1);

	printf("Congratulations you passed phase 2\n");

	getline(&input2, &len, infile);
	phase_3(input2);

	printf("Congratulations you passed phase 3\n");
	printf("You've finished the task! Great Job!\n");
	return 0;
}
