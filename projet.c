#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char* elements[13] =
{
    "M",
    "O",
    "U",
    "D",
    "L",
    "E",
    "I",
    "II",
    "III",
    "IV",
    "V",
    "VI",
};
    char combinaisons[40][13] =
    {
        "DEM",
        "DOM",
        "DEO",
        "DOL",
        "DUE",
        "DUO",
        "EMU",
        "LED",
        "LEM",
        "MEL",
        "MEO",
        "MOL",
        "MOU",
        "MUE",
        "ODE",
        "OUD",
        "ELU",
        "LEU",
        "LUE",
        "LUO",
        "OLE",
        "IIIIII",
        "IIIIV",
        "IIIVVI",
        "IVVVI",
        "IIIIVV",
        "III",
        "IIIIII",
        "IIIIIIIII",
        "IVIVIV",
        "VVV",
        "VIVIVI",
        "MMM",
        "OOO",
        "UUU",
        "DDD",
        "LLL",
        "EEE",

    };


int get_mise()
{
	char scan[7];
	char quitter[7]="quitter";
	char un[2]="1";
	char deux[2]="2";
	char trois[2]="3";
	scanf("%s", scan);
	if(strcmp(scan,quitter)==0)
	{
		exit(-1);
	}

	if(strcmp(scan,un)==0) 
	{
		return atoi(scan);
	}

	if(strcmp(scan,deux)==0) 
	{
		return atoi(scan);
	}

	if(strcmp(scan,trois)==0) 
	{
		return atoi(scan);
	}
	return 0;
}


int main()
{
	system("clear");
	int mise = get_mise();
	int credits = 100;
	char colone1[4];
	char colone2[4];
	char colone3[4];
	char combi[12];
	while( credits > 0 && mise != 0)
	{
			srand(time(NULL));
			int var1 = rand() % 12;
			int var2 = rand() % 12;
			int var3 = rand() % 12;

			strcpy(colone1, elements[var1]);
			strcpy(colone2, elements[var2]);
			strcpy(colone3, elements[var3]);

			printf("%s %s %s \n", colone1, colone2, colone3 );

			strcpy(combi,colone1);
			strcat(combi,colone2);
			strcat(combi,colone3);
			printf("combi : %s", combi);

			credits -=100;

	}
	return 0;
}