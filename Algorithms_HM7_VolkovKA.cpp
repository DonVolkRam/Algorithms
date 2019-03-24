// Graph.cpp: определяет точку входа для консольного приложения.
//
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <queue>

#define MaxRank 64
#define FName1 "D:\\Projects\\VS\\Graph\\Graph\\Graph.txt"
#define FName2 "\\..\\Graph\\Graph.txt" 
#define FName3 "Graph1.txt"

int Graph[MaxRank][MaxRank];
int Visit[MaxRank];
bool Used[MaxRank];
int Depth, Width;
int Rank;

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
				for (int j = 0; j < MaxRank - rank; j++)
					*Buf++;
			}
		}
		fclose(in);
	}
	else
		return -1;
	return Rank = rank;
}

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

void Gr_bfs(int u) {
	Used[u] = true;
	queue <int> q;
	q.push(u);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < (int)g[u].size(); i++) {
			int v = g[u][i];
			if (!Used[v]) {
				Used[v] = true;
				q.push(v);
			}
		}
	}
}

int Gr_Depth(int start)
{
	Gr_dfs(start);
	return Depth;
}

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
		printf("Error Reading file\n");
	Gr_Print(rank, Graph);
	printf("\nDepth is %d\n", Gr_Depth(1));
	char temp;
	scanf("%c", &temp);
	return 0;
}

