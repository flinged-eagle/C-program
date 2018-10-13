#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include"game.h"


void menu()
{
	printf("*****************************\n");
	printf("*********1. play  ***********\n");
	printf("*********0. exit  ***********\n");
	printf("*****************************\n");
}

int main()
{
	int n = 0;
	srand((unsigned)time(NULL));

	do
	{
		menu();
		printf("ÇëÊäÈëÄãµÄÑ¡Ôñ£º>\n");
		scanf("%d",&n);
		switch(n)
		{
		case 1 :
			game();
			break;
		case 0 :
			printf("EXIT!\n");
			break;
		default:
			printf("Please try again!\n");
			break;
		}
	}while(n);

	return 0;

}