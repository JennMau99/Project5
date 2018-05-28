/* Jennifer Maunder and Richa Gadgil
 *  * CPE 357-03
 *   * Project 5
 *    */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

int getline(char *array, int stage, int startpipe, int endpipe);
int main()
{
	char array[]= " sort\0";
	getline(array, 2, 1, -1);
	return 0;
}
int getline(char *array, int stage, int startpipe, int endpipe)
{
	int i = 0;
	int sp = startpipe;
	int ep = endpipe;
	int geti = 0;
	int geto = 0;

	char input[512];
	char output[512];
	
	int argc = 0;
	char argv[10][512];

	char * words;

	printf("--------");
	printf("\nStage %d: \"%s\"", stage, array);
	printf("\n--------");	 
	

	words = strtok(array, " ");

	while(words != NULL)
	{

		if(strcmp(words, "<") && strcmp(words, ">") && geto == 0 && geti == 0)
                {
                        strcpy(argv[argc], words);
                        /*get commands*/
                        argc++;

                }

		if(sp == -1 && strcmp(words, "<") == 0)
			geti = 1;
		else if(geti == 1)
		{
			strcpy(input, words);
			geti = 0;
			sp = -2;
		}


		if(ep == -1 && strcmp(words, ">") == 0)
			geto = 1;	
		else if(geto == 1)
		{
			strcpy(output, words);
			geto = 0;
			ep = -2;
		}
		

		words = strtok(NULL, " ");
	}

	printf("\n\tinput: ");
	if(sp == -1)
		printf("original stdin");
	else if(sp == -2)
		printf(input);
	else
		printf("pipe from stage %d", sp);

	printf("\n\toutput: ");
        if(ep == -1)
                printf("original stdout");
        else if(ep == -2)
                printf(output);
        else
                printf("pipe to stage %d", ep);


	printf("\n\targc: %d", argc);

	printf("\n\targv: ");
	for(i = 0; i < argc; i++)
	{
		printf("\"%s\"", argv[i]);
		if(i != (argc - 1))
			printf(", ");
	}
		
	


	return 0;


}





