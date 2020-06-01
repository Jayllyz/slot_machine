#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "fonctions.h"

char* elements[12] =
{
	"M",
	"O",
	"U",
	"D",
	"L",
	"E",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
};

char combinaisons[40][4] =
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
	"123",
	"345",
	"456",
	"234",
	"135",
	"246",
	"111",
	"222",
	"333",
	"444",
	"555",
	"666",
	"MMM",
	"OOO",
	"UUU",
	"DDD",
	"LLL",
	"EEE",

};

int tabgain[40]=
{
	25, //DEM
	25, //DOM
	250, //DEO
	25, //DOL
	25, //DUE
	250, //UO
	25, //EMU
	1000, //LED
	25, //LEM
	25, //MEL
	25, //MEO
	250, //MOL
	500, //MOU
	25,  //MUE
	25, //ODE
	25, //OUD
	25, //ELU
	25, //LEU
	25, //LUE
	25, //LUO
	25, //OLE
	250, //123
	60, //345
	250, //456
	40, //234
	25, //135
	50, //246
	1000, //111
	200, //222
	300, //333
	400, //444
	5, //555
	6, //666
	100, //MMM
	100, //OOO
	100, //UUU
	100, //DDD
	100, //LLL
	100, ///EEE
	};

int main()
{
	system("clear");
	int credits = 100;
	int mise;
	char colone1[5];
	char colone2[5];
	char colone3[4];
	char *combi;
	int i =0;
	int caractere = 0;
	FILE* fichier = NULL;
	fichier = fopen("vitrine.txt", "r"); //on ouvre le fichier en lecture
	if( fichier != NULL) //on verifie que le fichier existe bien 
	{ 
		while ( caractere != EOF) //
		{   
			caractere = fgetc(fichier);// On lit le caractère
			if( caractere == EOF) //si c'est la fin il stop
			{
			   break;            
			} 
			printf("%c", caractere); //on print le caractere récupéré
		}

	} 	
	fclose(fichier); 


	while(credits != 0 && credits > 0)
	{
			cursorPosition(25,55);
			printf("                  ");
			
			mise = get_mise();
			cursorPosition(25,10);
			printf("            ");
			if(credits - mise < 0)
			{
				continue;
			}
			cursorPosition(25,55);
			printf("               ");
			srand(time(NULL)); 
			int var1 = rand() % 12;
			int var2 = rand() % 12;
			int var3 = rand() % 12; //ici on genere nos 3 variable aleatoires

			strcpy(colone1, elements[var1]);//avec la variable aleatoire on prend l'elements correspondant et on le copie dans une chaine
			strcpy(colone2, elements[var2]);
			strcpy(colone3, elements[var3]);//même chose pour les 3 colonnes

			combi = concatener(colone1,colone2,colone3);//on combine les 3 chaines pour en avoir une seul


			for(int m = 0; m < 35; m++)
			{
				int alea1 = rand() %12;
				int alea2 = rand() %12;
				int alea3 = rand() %12;
				if(m<10)
				{
					affichage(alea1,2);

				}
				if(m<20)
				{
					affichage(alea2,43);
					
				}
				if(m <25)
				{
					affichage(alea3,84);
				}
				usleep(100000);
				affichage(var1,2);
				affichage(var2,43);
				affichage(var3,84);
			}



			for(i =0; i <40; i++) //on regarde dans les 40 combinaisons possibles
			{
				if(strcmp(combi,combinaisons[i]) == 0) //si la combinaison existe on continue
				{
					credits = (credits + (tabgain[i]* mise)) - mise;
					cursorPosition(23,20);
					printf("       ");
					cursorPosition(23,20);
					printf("%d\n", credits);
					cursorPosition(23,104);
					printf("       ");
					cursorPosition(23,104);
					printf("%d\n", tabgain[i] * mise);
					cursorPosition(25,10);
					printf("            ");
					cursorPosition(25,10);
					printf("VICTOIRE !");

					break;
				}

			}
			if( i == 40 && strcmp(combi,combinaisons[i]) != 0)//si la dernier est fausse le joueur a perdu
			{
				credits = credits - mise;
				cursorPosition(25,10);
				printf("            ");
				cursorPosition(25,10);
				printf("Perdu !");
				cursorPosition(23,20);
				printf("       ");
				cursorPosition(23,20);
				printf(" %d\n", credits);
				cursorPosition(23,104);
				printf("       ");
				cursorPosition(23,104);
				printf("0");
			}
	}

	return 0;
}