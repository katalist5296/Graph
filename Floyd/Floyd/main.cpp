#include <iostream>

#define INF 9000000 // Нет вершины
#define MatrixLen 5

/* Алгоритм Флойда — Уоршелла.*/

/* Исходная матрица расстояний */
int matrix[MatrixLen][MatrixLen] =
{
//	1	2	3	4	5
	{0, 5, 2, INF, INF}, // 1
	{5, 0, INF, 7, INF}, // 2
	{2, INF, 0, 2, 8},	 // 3
	{INF, 7, 2, 0, 1},	 // 4
	{INF, INF, 8, 1, 0}	 // 5
};


int main()
{
	/* Поиск расстояния минимального пути от каждой до каждой вершины */
	for (size_t k(0); k < MatrixLen; ++k)
		for (size_t i(0); i < MatrixLen; ++i)
			for (size_t j(0); j < MatrixLen; ++j)
				if (matrix[i][k] < INF && matrix[k][j] < INF)
					if (matrix[i][k] + matrix[k][j] < matrix[i][j])
						matrix[i][j] = matrix[i][k] + matrix[k][j];


	int from = 0;
	int to = 4;

	/* Теперь минимальное расстояние от любой до любой будет matrix[ОТКУДА][КУДА] */

	std::cout << "Lenght from " << from << " to " << to << ": " << matrix[from][to] << std::endl;

	system("pause");
	return 1;
}

