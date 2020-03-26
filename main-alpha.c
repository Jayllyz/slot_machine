#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	system("clear");
	int credits = 100;
	int gain =0;
	while(credits > 0)
	{
		printf("Vous avez %d crédits, que voulez vous miser ? \nMiser 1 ou Miser 2 ou Miser 3 \n", credits);
		int get_mise =0;
		scanf("%d", &get_mise);
		srand(time(NULL));
		int var1 = rand() % 101;
		int var2 = rand() % 101;
		int var3 = rand() % 101;
		if(get_mise != 1 && get_mise != 2 && get_mise != 3)
		{
			printf("Vous avez quitté la machine à sous, à bientot");
			exit(-1);
		}
		printf("Vous avez misé %d \n", get_mise);
		credits -= get_mise;
		printf("Vous avez obtenu :\n  %d  |  %d  | %d\n", var1,var2,var3);
		if(var1 % 2 == 0 && var2 % 2 == 0 && var3 % 2 == 0)
		{
			gain = 1000* get_mise;
			credits += gain;
			printf("Vous avez gagné %d crédits, vous etes à %d crédits ! \n", gain,credits);
		}
		if(var1 % 2 == 1 && var2 % 2 == 1 && var3 % 2 == 1)
		{
			gain = 500* get_mise;
			credits += gain;
			printf("Vous avez gagné %d crédits, vous etes à %d crédits ! \n", gain,credits);
		}
		else
		{
			printf("perdu ! \n");
		}
	}

	return 0;
}