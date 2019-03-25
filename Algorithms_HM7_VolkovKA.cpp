// Graph.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MaxRank 64
#define FName1 "D:\\Projects\\VS\\Graph\\Graph\\Graph.txt"
#define FName2 "\\..\\Graph\\Graph.txt" 
#define FName3 "Graph1.txt"

int Graph[MaxRank][MaxRank];
int Visit[MaxRank];
bool Used[MaxRank];
int Quene[MaxRank];
int Count=0;
int Depth=1, Width=1;
int Rank;

//Функции работы с очередью
//начало
void B_Push(int U)
{	
	Quene[Count] = U;
	Count++;
}

void B_Pop()
{
	for (int i = 0; i < Count; i++)
	{
		Quene[i] = Quene[i + 1];
	}
	Count--;
}

int B_Empty()
{
	if (Count)
		return false;
	else
		return true;
}

int B_Front()
{
	return Quene[0];
}

int B_Back()
{
	return Quene[Count-1];
}
//конец

//чтение матрицы из файла
int Gr_Read(char* filename, int** Buf)
{
	int rank = 0;

	FILE *in;
	in = fopen(filename, "r");
	if (in != NULL)
	{
		int c;
		fscanf(in, "%d", &rank);

		while ((c = getc(in)) != EOF)// пока не конец файла		
		{
			for (int i = 0; i < rank; i++)
			{
				for (int j = 0; j < rank; j++)
				{
					fscanf(in, "%d", &c);
					*Buf = c;
					*Buf++;					
				}
				for (int j = 0; j < MaxRank-rank; j++)
					*Buf++;
			}
		}
		fclose(in);
	}
	else
		return -1;
	return Rank=rank;
}

//получение матрицы в буфер
void Gr_GetMatrix(int** Buf[MaxRank][MaxRank])
{
	for (int i = 0; i < Rank; i++)
	{
		for (int j = 0; j < Rank; j++)
		{
			Graph[i][j] = Buf[i][j];
		}
	}
}

//рекурсивный обход в глубину
void Gr_dfs(int v)
{
	Depth = 1;
	int i;
	Visit[v] = 1;
	printf("Vertex %d is visited\n", v);
	for (i = 1; i <= Rank; i++)
		if (Graph[v][i] && !Visit[i])
		{
			Gr_dfs(i);
			Depth++;
		}
}

//обход в ширину
int Gr_Width(int u) 
{
	Width = 1;
	Used[u-1] = true;
	B_Push(u);
	int num = 0;  //количество точек смежных с текущей вершиной
	while (!B_Empty()) 
	{
		int u = B_Front();		
		B_Pop();		
		num--;
		if(num==0)
			Width++;
		for (int i = 0; i < Rank; i++) 
		{		
			if (!Used[i] && Graph[u-1][i])
			{
				Used[i] = true;				
				B_Push(i+1);
				num++;
			}
		}
	}
	return Width;
}

//получение значения обхода графа в глубину
int Gr_Depth(int start)
{	
	Gr_dfs(start);
	return Depth;
}

//печать матрицы графа
void Gr_Print(int rank, int Buf[MaxRank][MaxRank])
{
	for (int i = 0; i < rank; i++)
	{
		for (int j = 0; j < rank; j++)
			printf("%d ", Buf[i][j]);
		printf("\n");
	}
}

int main()
{
//	int Matrix[MaxRank][MaxRank];
	int rank;
	printf("Hello\n");

	rank = Gr_Read(FName3, &Graph);
	if (rank > 0)
		printf("Graph Rank is %d\n", rank);
	else
		printf("Error Reading file");
	Gr_Print(rank, Graph);
	printf("\nDepth is %d\n",Gr_Depth(1));

	printf("\nWidth is %d\n", Gr_Width(1));

	char temp;
	scanf("%c", &temp);
	return 0;
}

