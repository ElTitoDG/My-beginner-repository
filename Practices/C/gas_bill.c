#include<stdlib.h>
#include<stdio.h>

int main()
{

	int opc, used_energy;
	float final_price = 0, kw = 0;

	printf("What ammount of energy will use: ");
	scanf(" %i", &used_energy);
	printf("Choose option: \n");
	printf("1. Registration of housing\n");
	printf("2. Test\n");
	scanf(" %i", &opc);

	if(used_energy >= 50)
	{
		kw = 0.1;
	}else
	{
		kw = 0.05;
	}

	switch(opc)
	{
		case 1:
			final_price = 100 + (used_energy*kw);
			printf("Your bill is : %.2f\n", final_price);
		break;
		case 2:
			printf("Placeholder\n");
		break;
	}

	return 0;
}
