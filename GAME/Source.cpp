#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <iomanip> 
#include <iostream>


void menu();
void main()
{
	menu();
}


//SOLN_ CODE

int n, R[51];

int check(int x, int y)
{
	int i;
	for (i = 1; i < x; i++)
	{
		if ((R[i] == y) || (i - R[i] == x - y) || (i - x == y - R[i]))
		{
			y = y + 1;
			i = 0;
		}
	}

	if (y > n)
		return 0;
	else
		return y;
};

int soln()
{
	int i, f;

	printf("\033[0;34m");

	printf("enter size of the board:");

	printf("\033[0m");

	scanf_s("%d", &n);
	printf("\t press enter for more soln_..");

	printf("\n");
	for (i = 1; i <= n; i++)
		R[i] = 1;
	i = 1;
	while (1)
	{
		for (; i <= n; i++)
		{
			f = check(i, R[i]);
			if (f != 0)
				R[i] = f;
			else
			{
				R[i] = 1;
				R[i - 1] = R[i - 1] + 1;
				i = i - 2;
			}
		}

		for (i = 1; i <= n; i++)
		{
			for (f = 1; f <= n; f++)
			{
				if (f == R[i])
					printf(" Q ");
				else
					printf(" - ");
			}
			printf("\n");
		}
		printf("\n");
		for (i = 1; i < n; i++)
			printf("%d,", R[i]);
		printf("%d", R[n]);
		_getch();
		system("cls");

		printf("\033[0;35m");

		printf("solution for (%d) Queen\t\nfor more press enter..\n\n", n);

		printf("\033[0m");


		R[n] = R[n] + 1;
		i = n;
	}
}

// TIMER CODE

int hour = 0, minute = 0, second = 0, flag = 0;

void delay(int z)  //delay function
{
	clock_t timeDelay = z + clock();    //Step up the difference from clock delay
	while (timeDelay > clock());         //stop when the clock is higher than time delay
}

int printTimeOnscreen() {
	system("cls");
	printf("\t     1.Start  2.Stop  3.Reset    \n");

	printf("\033[46m");

	printf("\t              %d:%d:%d              \n", hour, minute, second);

	printf("\033[0m");

	printf("\033[0;45m");

	printf("\t     Time allowed: One Minute    \n");

	printf("\033[0m");

	return 0;
}

int selection() {
	switch (_getch()) {
	case 49: flag = 0; break;
	case 50: flag = 1; break;
	case 51:
		hour = minute = second = 0; flag = 1;
		printTimeOnscreen();
		break;
	}


	return 0;
}

int counter() {
	while (!_kbhit() && flag == 0) {     //keep looping while the user didn't hit any key and flag is 0
		if (minute > 59) {            //after minute is greater than 59, reset minute and increase 1 hour
			minute = 0; ++hour;
		}
		if (second > 59) {         //after second is greater than 59, reset second and increase 1 minute
			second = 0; ++minute;
		}
		printTimeOnscreen();           //print out the new data, delay for 1000 millisecond and increase 1 second.
		delay(1000); second += 1;
	}
	selection();    //after the user hit the keyboard, call the menu selection
	return 0;
}

int timer()
{
	while (1) {
		counter();
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////


void menu() {
	int x;
	printf("\n");

	printf("\tWELCOME TO THE PUZZLE GAME\n\n");

	printf("\033[1;32m");


	printf("\t----------------------------\n\t\tTHE 8 QUEENS\n\t----------------------------\n");
	printf("\n\n");

	printf("\033[0m");



	printf("\tPLAY :D\t\t\t\t\t.1\n");
	printf("\n\n");
	printf("\n\n");
	printf("\tKNOW THE RULE OF THE QUEENS PUZZLE\t.2\n");
	printf("\n\n");
	printf("\n\n");
	printf("\tSEE THE SOLUTION\t\t\t.3\n");
	printf("\n\n");
	printf("\n\n");
	printf("\tEXIT :'(\t\t\t\t.4\n");
	printf("\n\n\tPLEASE ENTER YOUR CHOICE: ");
	printf("\n\n");
	scanf_s("%d", &x);


	if (x < 1 || x > 4)
	{

		while (x < 1 || x > 4)
		{
			system("cls");

			printf("\033[41m");

			printf("\n\n\tWRONG CHOICE PLEASE CHOOSE AGAIN\n\n");

			printf("\033[0m");

			printf("\tPLAY :D\t\t\t\t\t1\n");
			printf("\n\n");
			printf("\n\n");
			printf("\tKNOW THE RULES OF THE QUEENS PUZZLE\t\t\t2\n");
			printf("\n\n");
			printf("\n\n");
			printf("\tSEE THE SOLUTION\t\t\t3\n");
			printf("\n\n");
			printf("\n\n");
			printf("\tEXIT :'(\t\t\t\t4\n");
			printf("\n\n\tPLEASE ENTER YOUR CHOICE: ");
			printf("\n\n");
			scanf_s("%d", &x);
		}
	}

	if (x == 4)
	{
		system("cls");
		printf("\033[0;36m");
		printf("\n");
		printf("\tTHANK YOU FOR PLAYING OUR GAME \tGOOD BYE.. :D\n\n\n\n");
		printf("\033[0m");
	}

	if (x == 3)
	{
		check(0, 0);
		soln();

		printf("\n\n\tOK NOW I WANT TO  : ");
		scanf_s("%d", &x);
		system("cls");
	}

	if (x == 2)
	{

		printf("\n\nThe eight queens’problem is the problem of placing eight queens on an 8×8 chessboard\nsuch  that  none  of  them  attack  one  another  (no  two  are  in  the  same  row,  column,  or diagonal).");
		printf("\n\n\tOK NOW I WANT TO  : ");
		scanf_s("%d", &x);
		system("cls");
	}

	if (x == 1)
	{
		// TIMER CODE 
		delay(0);
		printTimeOnscreen();
		selection();
		counter();
		timer();
		// TIMER CODE END

		printf("\n\n\tOK NOW I WANT TO  : ");
		scanf_s("%d", &x);
		system("cls");
	}
}