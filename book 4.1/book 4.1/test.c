#define _CRT_SECURE_NO_WARNINGS 1
#define MAXLINE 1000     //最大输入行长度
#include<stdio.h>

int getline(char line[], int lim);
int strindex(char source[], char searchfor[]);
int strrindex(char s[], char t[]);

char pattern[] = "ould";   //待查找模式

//查找带有pattern字符串的行


int main()
{
	char line[MAXLINE];
	int i;
	int found = 0;
	while(getline(line,MAXLINE)>0)
	{
		if(strindex(line,pattern) >= 0)
		{
			printf("%s",line);
			printf("%d",strrindex(line,pattern)+1);
			found++;
		}
	}
	return 0;
}

//将行保存到s中，并返回长度
int getline(char s[], int lim)
{
	int i = 0, c;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}


//返回pattern在s中的位置，若未找到返回-1
int strindex(char s[], char pattern[])
{
	int i,j,k;
	for(i=0 ; s[i] != '\0' ; i++)
	{
		for(j=i, k=0; pattern[k] != '\0' && s[j] == pattern[k] ; j++,k++)
			;
		if(k > 0 && pattern[k] == '\0')
			return i;
	}
	return -1;
}

int strrindex(char s[], char t[])
{
	int i,j,k,a;
	for(i=0 ; s[i] != '\0' ; i++)
	{
		for(j=i, k=0; pattern[k] != '\0' && s[j] == pattern[k] ; j++,k++)
			;
		if(k > 0 && pattern[k] == '\0')
			a = i;
	}
	
	return a>0? a : -1;
}