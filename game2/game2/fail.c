//#define _CRT_SECURE_NO_WARNINGS 1

//void Unwrap(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y)
//{
//	char sum = '0';
//	int i = x;
//	int j = y;
//
//	sum += GetMineCount(arr1,++i,j);
//	arr2[i][j] = sum;
//
//	while(sum == '0' && i<9)
//	{
//		Unwrap(arr1,arr2,i,j);
//	}
//
//	i = x;
//
//	sum += GetMineCount(arr1,--i,j);
//	arr2[i][j] = sum;

//	while(sum == '0' && i>1)
//	{
//		sum += GetMineCount(arr1,--i,j);
//		arr2[i][j] = sum;
//		Unwrap(arr1,arr2,i,j);
//	}
//
//	i = x;
//
//	sum += GetMineCount(arr1,i,++j);
//	arr2[i][j] = sum;

//	while(sum == '0' && j<9)
//	{
//		Unwrap(arr1,arr2,i,j);
//	}
//
//	j = y;
//
//	sum += GetMineCount(arr1,i,--j);
//	arr2[i][j] = sum;
//
//	while(sum == '0' && j>1)
//	{
//		Unwrap(arr1,arr2,i,j);
//	}
//
//
//}


//向下展开
//void Unwrap1(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y)
//{
//	char sum = '0';
//	int i = x;
//	int j = y;
//
//	sum += GetMineCount(arr1,++i,j);
//	arr2[i][j] = sum;
//	if(sum == '0' && i<9)
//	{
//		Unwrap1(arr1,arr2,i,j);
//		//Unwrap3(arr1,arr2,x,y);
//		//Unwrap4(arr1,arr2,x,y);
//	}
//}
////向上展开
//void Unwrap2(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y)
//{
//	char sum = '0';
//	int i = x;
//	int j = y;
//
//	sum += GetMineCount(arr1,--i,j);
//	arr2[i][j] = sum;
//	if(sum == '0' && i>1)
//	{
//		Unwrap2(arr1,arr2,i,j);
//		//Unwrap3(arr1,arr2,x,y);
//		//Unwrap4(arr1,arr2,x,y);
//	}
//}
////向右展开
//void Unwrap3(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y)
//{
//	char sum = '0';
//	int i = x;
//	int j = y;
//
//	sum += GetMineCount(arr1,i,++j);
//	arr2[i][j] = sum;
//	if(sum == '0' && j<9)
//	{
//		//Unwrap1(arr1,arr2,i,j);
//		//Unwrap2(arr1,arr2,i,j);
//		Unwrap3(arr1,arr2,i,j);
//	}
//}
////向左展开
//void Unwrap4(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y)
//{
//	char sum = '0';
//	int i = x;
//	int j = y;
//
//	sum += GetMineCount(arr1,i,--j);
//	arr2[i][j] = sum;
//	if(sum == '0' && j>1)
//	{
//		//Unwrap1(arr1,arr2,i,j);
//		//Unwrap2(arr1,arr2,i,j);
//		Unwrap4(arr1,arr2,i,j);
//	}
//}


