#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FONCTIONS_H
#define FONCTIONS_H

void cursorPosition(int YPos, int XPos) //Fonction pour déplacer le curseur
{
    printf("\033[%d;%dH",YPos,XPos);
}

int get_mise()
{
	char scan[7];
	char quitter[2]="0";
	char un[2]="1";
	char deux[2]="2";
	char trois[2]="3";
	cursorPosition(23,61);
	printf("      ");
	cursorPosition(23,61);
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
	else
	{
		cursorPosition(25,55);
		printf("Impossible !");
		get_mise();
	}
	return 0;
}


void affichage( int i,int L)
{
	int tab_caractere[12] = {0,684,1368,2052,2736,3420,4104,4788,5472,6156,6840,7524};
	int C=2;
	FILE* fichier = NULL;
	int caractere = 0;
	fichier = fopen("lettres_chiffres_romains.txt", "r"); //on ouvre le fichier en lecture
	int var = tab_caractere[i];

	fseek(fichier,var,SEEK_SET);

	if(fichier != NULL) //on verifie que le fichier existe bien 
	{ 
		for(int y=0; y < 18; y++)
		{
			printf("\033[%d;%dH",C,L);
			for (int j = 0; j < 38; j++)
			{
				caractere = fgetc(fichier);
				printf("%c", caractere);
			
			}
			C++;
		}
	} 
	fclose(fichier); 
}

char* concatener(const char *a, const char *b, const char *c )
{
	char *combi = malloc(1 + 1 +1 +1);
	if(combi)
	{
		memcpy(combi,a,1);
		memcpy(combi+1,b,1);
		memcpy(combi + 1 + 1,c,1 +1);
	}
	return combi;
}

#endif