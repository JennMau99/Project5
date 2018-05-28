/* Jennifer Maunder and Richa Gadgil
 * CPE 357-03
 * Project 5
 */

#include <stdio.h>
#include <stdlib.h>


void parse(int argc, char *argv[])
{


}




int readline(char *line)
{
	fprintf(stdout, "line: ");
	fgets(line, 513, stdin);
	if (line[512] != -1 && line[512] != '\0')
	{
		fprintf(stderr, "cmd: too many arguments\n");
		return -1;
	}

}

/* We probably shouldn't have main doing too much */
int main(int argc)
{
	char line[513]
	line[512] = 1;
	if (argc > 1)
	{
		fprintf(stderr, "parseline itself doesn't take args\n");
		return -1;
	}
	readline(line);
}
