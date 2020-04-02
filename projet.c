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
        "IIIIII", //123
        "III IV V", //345
        "IV V VI", //456
        "II III IV", //234
        "I III V", //135
        "II IV VI", //246
        "I I I", //111
        "II II II", //222
        "III III III", //333
        "IV IV IV", //444
        "V V V", //555
        "VI VI VI", //666
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
	int i =0;
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
			printf("combi : %s\n", combi);

			for(i =0; i <40; i++) 
			{
				if(strcmp(combi,combinaisons[i]) == 0)
				{
					printf("gagne\n");
					break;
				}

			}
			if( i == 40 && strcmp(combi,combinaisons[i]) != 0)
			{
				printf("perdu\n");
			}
			credits -=100;

	}
	return 0;
}