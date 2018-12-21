// ---------------------------------------------------------------------------
// Implementation of Dijkstra's shortest path algorithm
//
// main.cpp
// use sample by dijkstra_graph.png
//
// Author: Vyacheslav Borisenko
//
#include <iostream>
#include <algorithm>



/* Алгоритм Дейкстры.*/

#define INF 9000000 // Нет вершины
#define MatrixLen 9

/* Исходная матрица расстояний */
int matrix[MatrixLen][MatrixLen] = {
	{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	{ 0, 0, 4, 0, 10, 0, 2, 0, 0 },
	{ 0, 0, 0, 14, 0, 2, 0, 1, 6 },
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
};




int minDistance(int dist[], bool shortest[])
{
	int min = INF, min_index;

	for (int v = 0; v < MatrixLen; v++)
	{
		if (shortest[v] == false && dist[v] <= min)
		{
			min = dist[v], min_index = v;
		}
	}

	return min_index;
}

void printSolution(int dist[], int n)
{
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < n; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int from)
{
	int dist[MatrixLen];
	bool shortestPath[MatrixLen];

	for (int i = 0; i < MatrixLen; i++)
	{
		dist[i] = INF, shortestPath[i] = false;
	}

	dist[from] = 0;

	for (int count = 0; count < MatrixLen - 1; count++)
	{
		int u = minDistance(dist, shortestPath);

		shortestPath[u] = true;

		for (int v = 0; v < MatrixLen; v++)
		{
			if (!shortestPath[v] && matrix[u][v] && dist[u] != INF
				&& dist[u] + matrix[u][v] < dist[v])
				dist[v] = dist[u] + matrix[u][v];
		}
	}

	printSolution(dist, MatrixLen);
}



int main()
{
	dijkstra(0);
	system("pause");
	return 1;
}

