#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void game()
{
	char Mine_Plate[ROWS][COLS] = {0};
	char Show_Plate[ROWS][COLS] = {0};
	char set = '*';

	Init(Mine_Plate,ROWS,COLS,'0');
	Init(Show_Plate,ROWS,COLS,set);
	//show(Mine_Plate,ROWS,COLS);
	show(Show_Plate,ROWS,COLS);
	GetMine(Mine_Plate,ROWS,COLS,EASY_CONDITION);
	//show(Mine_Plate,ROWS,COLS);
	FindMine(Mine_Plate,Show_Plate,ROW,COL);
}

void Init(char arr[ROWS][COLS],int rows,int cols,char set)
{
	int i = 0;
	int j = 0;
	for(i=0; i<rows; i++)
		for(j=0; j<cols; j++)
			arr[i][j] = set;
}

void show(char arr[ROWS][COLS],int rows,int cols)
{
	int i = 0;
	int j = 0;
	printf("0|");
	for(j=1; j<cols-1; j++)
	{
		printf(" %d",j);
	}
	printf("\n");
	for(j=0; j<cols-1; j++)
	{
		printf("--",j);
	}
	printf("\n");
	for(i=1; i<rows-1; i++)
	{
		printf("%d|",i);
		for(j=1; j<cols-1;j++)
		{
			printf(" %c",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void GetMine(char arr[ROWS][COLS], int rows, int cols, int scale)
{
	while(scale)
	{
		int x = rand()%9+1;
		int y = rand()%9+1;
		if(arr[x][y] != '1')
		{
			arr[x][y] = 49; //'1'
			scale--;
		}
	}
}

//向下展开
void Unwrap_Down(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y)
{
	char sum = '0';
	int i = x;
	int j = y;

	Unwrap_Left(arr1,arr2,i,j);
	Unwrap_Right(arr1,arr2,i,j);

	sum += GetMineCount(arr1,++i,j);
	arr2[i][j] = sum;
	if(sum == '0' && i<=9)
	{
		Unwrap_Down(arr1,arr2,i,j);
	}
}
//向上展开
void Unwrap_Up(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y)
{
	char sum = '0';
	int i = x;
	int j = y;

	Unwrap_Left(arr1,arr2,i,j);
	Unwrap_Right(arr1,arr2,i,j);

	sum += GetMineCount(arr1,--i,j);
	arr2[i][j] = sum;
	if(sum == '0' && i>=1)
	{
		Unwrap_Up(arr1,arr2,i,j);
	}
}
//向右展开
void Unwrap_Right(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y)
{
	char sum = '0';
	int i = x;
	int j = y;

	sum += GetMineCount(arr1,i,++j);
	arr2[i][j] = sum;
	if(sum == '0' && j<=9 && arr2[i][j+1] == '*')
	{
		if(arr2[i+1][j] == '*')
		{
			Unwrap_Down(arr1,arr2,i,j);
		}
	    if(arr2[i-1][j] == '*')
		{
			Unwrap_Up(arr1,arr2,i,j);
		}
		Unwrap_Right(arr1,arr2,i,j);

	}
}
//向左展开
void Unwrap_Left(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y)
{
	char sum = '0';
	int i = x;
	int j = y;

	sum += GetMineCount(arr1,i,--j);
	arr2[i][j] = sum;
	if(sum == '0' && j>=1 && arr2[i][j-1] =='*')
	{
		if(arr2[i+1][j] == '*')
		{
			Unwrap_Down(arr1,arr2,i,j);
		}
	    if(arr2[i-1][j] == '*')
		{
			Unwrap_Up(arr1,arr2,i,j);
		}
		Unwrap_Left(arr1,arr2,i,j);
	}
}

//void Unwrap(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y)
//{
//	
//		int i =	x;
//		int j = y;
//		int sum = 0;
//
//			/*for(i=x-1; i<=x+1; i++)
//			{	
//				if(i == x)i++;
//				for(j=y-1; j<=y+1; j++)
//				{
//					if(j == y)j++;
//					sum=GetMineCount(arr1,i,j);
//					if(!sum && i>0 && i<ROW && j>0 && j<COL)
//					{
//						arr2[i][j] = '0';
//						Unwrap(arr1,arr2,i,j);
//						break;
//					}
//					else if(sum)
//					{
//						arr2[i][j] = sum+'0';
//					}
//				}
//			}		*/
//}

int Is_Win(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int ret = 0;

	for(i=1; i<row-1; i++)
		for(j=1; j<col-1; j++)
			if(arr[i][j] == '*')
				ret++;
	if(ret == EASY_CONDITION)
		return 1;
	return 0;

}


void FindMine(char arr1[ROWS][COLS],char arr2[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	char sum = '0';
	int	count = row*col-EASY_CONDITION;

	while(!Is_Win(arr2,ROWS,COLS))
	{
		sum = '0';

		printf("请输入坐标：>");
		scanf("%d%d",&x,&y);
		if(x>9 || y>9)
		{
			printf("输入有误，请重新输入\n");
		}
		else if(count == row*col-EASY_CONDITION && arr1[x][y] == '1')
		{
				arr1[x][y] = '0';
				do
				{
				i = rand()%9+1;
				j = rand()%9+1;
				}while(arr1[i][j] != '0');
				arr1[i][j] = '1';
				Unwrap_Up(arr1,arr2,x,y);
				Unwrap_Down(arr1,arr2,x,y);
				arr2[x][y] = '0';
				show(arr2,ROWS,COLS);
				count--;		
		}
		else
		{
			system("cls");
			if(arr1[x][y] == '1')
			{
				break;
			}
			else
			{
				sum += GetMineCount(arr1,x,y);
				arr2[x][y] = sum;

				if(sum == '0')
				{
				Unwrap_Up(arr1,arr2,x,y);
				Unwrap_Down(arr1,arr2,x,y);
				}

				show(arr2,ROWS,COLS);
				count--;
			}	
		}
	}

	if(Is_Win(arr2,ROWS,COLS))
	{
		printf("你赢了!\n");
	}
	else
	{
		printf("你输了!\n");
	}
	show(arr1,ROWS,COLS);
}



int GetMineCount(char arr[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	int sum = 0;
	if(x>0)
	{
		if(y>0)
		{
			for(i=x-1; i<=x+1; i++)
			{
				for(j=y-1; j<=y+1; j++)
					{
						sum += arr[i][j] - '0';
					}
			}

		}else
		{
			for(i=x-1; i<=x+1; i++)
			{
				for(j=y; j<=y+1; j++)
					{
						sum += arr[i][j] - '0';
					}
			}
		}
	}else if(y>0)
	{
		for(i=x; i<=x+1; i++)
		{
			for(j=y-1; j<=y+1; j++)
				{
					sum += arr[i][j] - '0';
				}
		}
	}else
	{
		for(i=x; i<=x+1; i++)
		{
			for(j=y; j<=y+1; j++)
				{
					sum += arr[i][j] - '0';
				}
		}
	
	}
	return sum;
}