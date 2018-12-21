#include <iostream>



#define INF -1 // Нет вершины
#define MatrixLen 8
int matrix[MatrixLen][MatrixLen] =
{
//	1	  2	   3	4	 5    6    7    8
	{0, 4, 6, 7, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 8, 0, 0},
	{0, 0, 0, 0, 5, 0, 0, 0},
	{0, 0, 0, 0, 9, 6, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 14},
	{0, 0, 0, 0, 0, 0, 10, 12},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
};

void printSolution(int dist[], int n, int time)
{
	printf("Path [ ");
	for (int i = 0; i < n; i++)
	{
		if(dist[i] == 0)
			printf("%d ", i + 1);
	}
	printf(" ]\nTime: %d\n", time);
}

//===================================

int minDistance(int dist[], bool shortest[])
{
	int min = INF, min_index;

	for (int v = 0; v < MatrixLen; v++)
	{
		if (shortest[v] == false && dist[v] >= min)
		{
			min = dist[v], min_index = v;
		}
	}

	return min_index;
}


void solution()
{
	int dist_max[MatrixLen],
		dist_relation[MatrixLen],
		dist_solve[MatrixLen];

	bool shortestPath[MatrixLen];

	for (int i = 0; i < MatrixLen; i++)
	{
		dist_max[i] = INF, shortestPath[i] = false;
	}

	dist_max[0] = 0;
	for (int count = 0; count < MatrixLen; count++)
	{
		int u = minDistance(dist_max, shortestPath);
		shortestPath[u] = true;

		for (int v = 0; v < MatrixLen; v++)
		{
			if (!shortestPath[v] && matrix[u][v]
				&& dist_max[u] + matrix[u][v] > dist_max[v])
				dist_max[v] = dist_max[u] + matrix[u][v];
		}
	}

	for (int i = 0; i < MatrixLen; i++)
	{
		dist_relation[i] = INF, shortestPath[i] = false;
	}

	dist_relation[0] = dist_max[MatrixLen - 1];
	dist_relation[MatrixLen - 1] = 0;
	int temp;
	for (int i = 0; i < MatrixLen; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}

	for (int count = 0; count < MatrixLen; count++)
	{
		int u = minDistance(dist_relation, shortestPath);
		shortestPath[u] = true;

		for (int v = 0; v < MatrixLen; v++)
		{
			if (!shortestPath[v] && matrix[u][v]
				&& dist_relation[u] + matrix[u][v] > dist_relation[v])
				dist_relation[v] = dist_relation[u] + matrix[u][v];
		}

		if (dist_relation[count] == INF)
			dist_relation[count] = 0;

		dist_solve[count] = dist_max[MatrixLen - 1] - dist_relation[count];
		dist_solve[count] = dist_max[count] - dist_solve[count];
		//printf("%d = %d - %d\n", dist_solve[count], dist_relation[count], dist_max[MatrixLen - 1]);
	}

	printSolution(dist_solve, MatrixLen, dist_max[MatrixLen - 1]);
}

int main()
{
	solution();
	system("pause");
	return 1;
}