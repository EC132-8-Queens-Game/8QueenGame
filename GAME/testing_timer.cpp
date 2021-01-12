#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <chrono>
#include <iostream>
#include <future>
#include <iostream>
#include <windows.h>

//  Const.
#define BOARD_SIZE 8
#define BACK 3
#define QUEEN 'Q' 
#define POS_SAFE 0
#define D_NOT_SAFE 3
#define R_NOT_SAFE 1
#define COL_NOT_SAFE 2

// TIMER CODE
using namespace std;

using namespace std;

//timer function
int h=0, m=0, s=5;

void timer(int h, int m, int s)
{
	for (;;)
	{
		if (h == 0 && m == 0 && s == 0)
		{
			break;
		}
		if (s == 0 && m == 0)
		{
			m = 60;
			h--;
		}
		if (s == 0)
		{
			s = 60;
			m--;
		}
		cout << h << ":" << m << ":" << s--;
		Sleep(1000);
	}
}

int time()
{
	int h, m, s;
	cout << "Hours: "; cin >> h;
	cout << "Minutes: "; cin >> m;
	cout << "Seconds: "; cin >> s;
	timer(h, m, s);
	for (int i = 100; ; i = i + 50)
		Beep(i, 1000);
}


// Gglobal Variables
char queen_board[BOARD_SIZE][BOARD_SIZE];
int Board_Size;


void Print();
void Play();

int Check_Pos(int row, int col);

void Get_Pos(int* row, int* col, int queen_number);
void game_menu();

//Clear function
void ClearBoard();

//Solve function
void Solve();
int Get_Board_Size();

//diagonals are safe
int Check_Diag(int row, int col);

//solution
int n = 8, R[51];

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
	int i, f, m, o;
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
		printf("\033[1;35m");
		printf("solution for (%d) Queen\nfor more press any key\n", n);
		printf("\033[0m");
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

		for (i = 1; i < n; i++)
			printf("%d,", R[i]);
		printf("%d", R[n]);
		_getch();
		system("cls");
		R[n] = R[n] + 1;
		i = n;

	}
}

//The main function
void main()
{
	int n = 0;
	int btn = 0;
	while (btn != 3)
	{
		printf("\n");
		printf("\tWELCOME TO THE PUZZLE GAME\n\n");

		printf("\033[1;32m");
		printf("\t----------------------------\n");
		printf("\033[0m");
		printf("\033[1;42m");
		printf("\t        THE 8 QUEENS        \n");
		printf("\033[0m");
		printf("\033[1;32m");
		printf("\t----------------------------\n");
		printf("\033[0m");
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
		scanf_s("%d", &btn);

		switch (btn)
		{
		case 1:
			game_menu();
			break;
		case 2:
			system("cls");
			printf("\033[44m");
			printf("\n\n");
			printf("\t        RULE          \n");
			printf("\033[0m");
			printf("\033[34m");
			printf("\t**********************\n");
			printf("\033[0m");


			printf("\033[0;36m");
			printf("\n\nThe eight queens’problem is the problem of placing eight queens on an 8×8 chessboard\nsuch  that  none  of  them  attack  one  another  (no  two  are  in  the  same  row,  column,  or diagonal).\n");
			printf("\033[0m");

			while (n != 1)
			{
				printf("\n\n\tOK NOW CLICK 1 TO BACK TO THE MENU\n");
				scanf_s("%d", &n);
				if (n == 1)
					puts("  ");
				else
					puts("WRONG INPUT");
				Beep(1245, 1000);
			}
			break;

		case 3:
			int e;
			system("cls");
			printf("\n\n\tAre you sure that you want to see solution?\n");
			printf("\033[4;91m");
			printf("\tif you sure press 1\n");
			printf("\033[0m");
			printf("\tif you're not press 2 and back to mune\n");
			scanf_s("%d", &e);

			while (e < 1 || e > 2)
			{
				system("cls");
				printf("\033[41m");
				printf("\n\n\tWRONG CHOICE PLEASE CHOOSE AGAIN\n\n");
				printf("\033[0m");
				Beep(1245, 1000);
				scanf_s("%d", &e);
			}
			if (e == 1)
			{
				check(0, 0);
				soln();
			}

			if (e == 2)
			{
				system("cls");
				BACK;
			}
			break;
		case 4:
			system("cls");
			printf("\033[0;36m");
			printf("\n");
			printf("\tTHANK YOU FOR PLAYING OUR GAME \t\n\tGOOD BYE.. :D\n\n\n\n");
			printf("\033[0m");
			Beep(1175, 1000);
			exit(0);

			break;
		default:
			printf("\033[0;41m");
			puts("Try again!!!");
			printf("\033[0m");
			Beep(1245, 1000);

		}
	}
}

// Print function
void Print(int a, int b)
{
	int i, j;
	printf("\033[44m");
	printf("\n 8 x 8 Chessboard:");
	printf("\033[0m");
	printf("\n");
	for (i = 0; i < Board_Size; i++)
	{
		for (j = 0; j < Board_Size; j++)
		{
			printf(" ---");
		}
		printf("\n");
		for (j = 0; j < Board_Size; j++)
		{
			printf("| ");
			printf("%c ", queen_board[i][j]);

		}
		printf("|");
		printf("\n");
	}

	for (i = 0; i < Board_Size; i++)
	{
		printf(" ---");
	}
	printf("\n");
}

// PUT QUEENS
int Check_Pos(int row, int col)
{
	int i, j;

	// check row
	for (i = 0; i < Board_Size; i++)
	{
		if (queen_board[row][i] == QUEEN)
		{
			return R_NOT_SAFE;
		}
	}

	// check column
	for (i = 0; i < Board_Size; i++)
	{
		if (queen_board[i][col] == QUEEN)
		{
			return COL_NOT_SAFE;
		}
	}
	if (Check_Diag(row, col) == D_NOT_SAFE)
	{
		return D_NOT_SAFE;
	}

	return POS_SAFE;
}

// Play function
void Play()
{
	int row, col;
	int number_of_queens = 0;
	int status;
	
	do
	{
		cout << "Hours: "; cin >> h;
		cout << "Minutes: "; cin >> m;
		cout << "Seconds: "; cin >> s;

		for (;;) {
			if (h == 0 && m == 0 && s == 0)
			{
				break;
			}
			if (s == 0 && m == 0)
			{
				m = 60;
				h--;
			}
			if (s == 0)
			{
				s = 60;
				m--;
			}
			cout << h << ":" << m << ":" << s--;
			Sleep(1000);
		}
		Print(0, 0);
		
		Get_Pos(&row, &col, number_of_queens + 1);

		status = Check_Pos(row - 1, col - 1);

		if (status == POS_SAFE)
		{
			queen_board[row - 1][col - 1] = QUEEN;
			number_of_queens++;
		}
		else if (status == R_NOT_SAFE)
		{
			printf("\nRow [%d] is not safe !!!\n", row);
			Beep(1245, 1000);
		}

		else if (status == COL_NOT_SAFE)
		{
			printf("\nColumn [%d] is not safe !!!\n", col);
			Beep(1397, 200);
		}
		else if (status == D_NOT_SAFE)
		{
			printf("\nDiagonal [%d]X[%d] is not safe !!!\n", row, col);
			Beep(1397, 200);
		}
		

	} while (number_of_queens < Board_Size);

}

void Get_Pos(int* row, int* col, int queen_number)
{
	char row_c, col_c;
	int status;

	int is_pos_valid = 0;
	do
	{
		printf("\033[0;36m");
		printf("PRESS C TO CLEAR THE BOARD");
		printf("\033[0m");
		printf("\n");
		printf("\033[0;32m");
		printf("PRESS S TO SEE THE SOLUTIONS");
		printf("\033[0m");
		printf("\n");
		printf("\n\n");
		printf("Enter the row of queen    %d: ", queen_number);

		row_c = getchar();

		while (!isalnum(row_c))
		{
			row_c = getchar();
		}

		if (isalpha(row_c))
		{
			if (row_c == 'c' || row_c == 'C')
			{
				ClearBoard();
				Play();
			}
			else if (row_c == 's' || row_c == 'S')
			{
				ClearBoard();
				Solve();
			}
			else if (row_c == 'q' || row_c == 'Q')
			{
				// retun tomenu
			}
			else
			{
				printf("\nInvalid Selection, Try again...\n");
				Beep(1245, 1000);
				is_pos_valid = 0;
				continue;
			}

		}
		else if (isdigit(row_c))
		{
			*row = row_c - 48;
		}


		printf("Enter the column of queen %d: ", queen_number);
		scanf_s("%d", col);

		if (((*row) >= 1 && (*row) <= Board_Size) && ((*col) >= 1 && (*col) <= Board_Size))
		{
			is_pos_valid = 1;
		}
		else
		{
			printf("\nNOT VALID INPUT. INPUT MUST BE <= %d , TRY ONE MORE TIME...\n", Board_Size);
			Beep(1245, 1000);
		}
	} while (is_pos_valid != 1);

}

void game_menu()
{
	int status;
	int menu2 = 0;

	system("cls");
	printf("\033[35m");
	printf("\t----------------------------\n");
	printf("\033[0m");
	printf("\033[45m");
	printf("\t        PALY MODE           \n");
	printf("\033[0m");
	printf("\033[35m");
	printf("\t----------------------------\n");
	printf("\033[0m");

	printf("\tPLAY WITHOUT TIME:\t\t\t.1\n");
	printf("\n\n");

	printf("\tPLAY WITH TIME:   \t\t\t.2\n");
	printf("\n\n");

	printf("\tBACK TO THE MENU \t\t\t.3\n");
	printf("\n\n");
	printf("\n\n\tPLEASE ENTER YOUR CHOICE: ");
	scanf_s("%d", &menu2);
	if (menu2 == 1)
	{
		status = Get_Board_Size();

		if (status == 0)
		{
			ClearBoard();
			Play();
		}
	}
	else if (menu2 == 2)
	{
		
		status = Get_Board_Size();

		if (status == 0)
		{
			ClearBoard();
			Play();
		}

	}
	else if (menu2 == 3)
	{
		printf("\n\n\tOK NOW CLICK 1 TO BACK TO THE MENU\n");
		scanf_s("%d", &n);
		if (n == 1)
			puts("  ");
		else
			puts("WRONG INPUT");
		Beep(1245, 1000);
	}
	else
		printf("\e[0;31m");
	system("cls");
	puts("ERROR NUMBER ENTER VALID.. Welcome in menu again");
	printf("\033[0m");
	Beep(1245, 1000);
}

void ClearBoard()
{
	int i, j;
	for (i = 0; i < Board_Size; i++)
	{
		for (j = 0; j < Board_Size; j++)
		{
			queen_board[i][j] = ' ';
		}
	}
}

void Solve()
{
	int row, col;
	int i;
	int s;
	int queens_num = 0;

	if (Board_Size % 2 == 0)
	{
		row = 1;
	}
	else
	{
		row = 0;
	}

	col = 0;

	while (row < Board_Size)
	{
		queen_board[row][col] = QUEEN;
		queens_num++;
		row += 2;
		col += 1;
	}

	for (col; col < Board_Size; col++)
	{
		if (Board_Size % 2 == 0)
		{
			row = 0;
		}
		else
		{
			row = 1;
		}

		for (row; row < Board_Size; row += 2)
		{
			s = Check_Pos(row, col);
			if (s == POS_SAFE)
			{
				queen_board[row][col] = QUEEN;
				queens_num++;
				break;
			}

		}

	}

	Print(0, 0);

}

int Get_Board_Size()
{
	int size;
	int k = 0;

	while (1)
	{
		int k = 1;

		if (k == 1)
		{
			Board_Size = BOARD_SIZE;
			break;
		}
		else if (k == 2)
		{
			return BACK;
		}
		else
			printf("error");
		Beep(1245, 1000);
	}

	return 0;
}

// check diagonals
int Check_Diag(int row, int col)
{
	int r, c;

	r = row;
	c = col;

	while (r > 0 && c > 0)
	{
		r -= 1;
		c -= 1;
	}

	do
	{
		if (queen_board[r][c] == QUEEN)
		{
			Print(r, c);
			return D_NOT_SAFE;
		}

		r += 1;
		c += 1;

	} while (r < Board_Size && c < Board_Size);


	r = row;
	c = col;

	while (r < (Board_Size - 1) && c > 0)
	{
		r += 1;
		c -= 1;
	}

	do
	{
		if (queen_board[r][c] == QUEEN)
		{
			Print(r, c);
			return D_NOT_SAFE;
		}

		r -= 1;
		c += 1;

	} while (r >= 0 && c < Board_Size);

	return 0;
}
