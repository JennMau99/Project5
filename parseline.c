/* Jennifer Maunder and Richa Gadgil
 * CPE 357-03
 * Project 5
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

/* getline takes char array of 512, int startpipe, int endpipe */

int checkstage(char *stage, int stagenum, int startpipe, int endpipe)
{
	int leftchevron = 0;
	int rightchevron = 0;
	int i;
	int length;
	fprintf(stdout, "stage %d: %s\n", stagenum, stage);
	length = strlen(stage);
	if (length == 0)
	{
		fprintf(stderr, "invalid null command\n");
		return -1;
	}
	for (i = 0; i < length; i++)
	{
		if (stage[i] == '<')
			leftchevron++;
		else if (stage[i] == '>')
			rightchevron++;
	}
	if (leftchevron > 1)
	{
		fprintf(stderr, "cmd: bad input redirection\n");
		return -1;
	}
	if (rightchevron > 1)
	{
		fprintf(stderr, "cmd: bad output redirection\n");
		return -1;
	}
	if (leftchevron  && startpipe != -1)
	{
		fprintf(stderr, "cmd: ambiguous input\n");
		return -1;
	}
	if (rightchevron && endpipe != -1)
	{
		fprintf(stderr, "cmd: ambiguous output\n");
		return -1;
	}

	return 0;
}

int readline(char *line)
{
	int i = 0;
	int j = 0;
	int stagenum = 0;
	int startpipe = -1;
	int endpipe = -1;
	int length = 0;
	int check = 0;
	char stage[513] = {0};
	fprintf(stdout, "line: ");
	fgets(line, 513, stdin);
	if (line[512] != 0)
	{
		fprintf(stderr, "cmd: too many arguments\n");
		return -1;
	}
	length = strlen(line);
	if (length == 0)
	{
		fprintf(stderr, "cmd: no commands given\n");
		return -1;
	}
	for (i = 0; i < length; i++)
	{
		if (line[i] != '|')
			stage[j++] = line[i];
		else if (line[i] == '|')
		{
			endpipe++;
			stage[j] = '\0';
			check = checkstage(stage, stagenum, startpipe, endpipe);
			if (check == -1)
				return -1;
			stagenum++;
			startpipe++;
			j = 0;
		}
	}
	endpipe = -1;
	stage[j] = '\0';
	check = checkstage(stage, stagenum, startpipe, endpipe);
	if (check == -1)
		return -1;
	return 0;
}

/* We probably shouldn't have main doing too much */
int main(int argc, char *argv[])
{
	char line[513] = {0};
	if (argc > 1)
	{
		fprintf(stderr, "parseline itself doesn't take args\n");
		return -1;
	}
	readline(line);
	return 0;
}

