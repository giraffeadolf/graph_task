#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream input("test/input4.txt");
ofstream output("output.txt");

// выделение памяти для матрицы
int** allocate_matrix(int dim)
{
    int** matrix = new int* [dim];

    for (int i = 0; i < dim; i++)
    {
        matrix[i] = new int[dim];
    }

    return matrix;
}

// очистка памяти под матрицу
void delete_matrix(int** source, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        delete[] source[i];
    }
    delete[] source;
}

// чтение элементов матрицы
void read_matrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			input >> matrix[i][j];
		}
	}
}

// алгоритм поиска в глубину
int* dfs(int** matrix, int n, int v, int* visited) {

    int* connect = new int[n];
    for (int i = 0; i < n; i++) {
        connect[i] = 0;
    }

    stack <int> q;
    q.push(--v);
    connect[v] = 1;
    visited[v] = 0;
    while (!q.empty()) {
        v = q.top();
        q.pop();
        for (int u = 0; u < n; u++) {
            if (matrix[v][u] && visited[u]) {
                q.push(u);
                visited[u] = 0;
                connect[u] = 1;
            }
        }
    }
    return connect;
}

// вывод компонент связности
void print_connect(int* list, int n) {
    output << "Компоненты связности: ";
    for (int i = 0; i < n; i++) {
        if (list[i]) {
            output << i + 1 << ' ';
        }
    }
    output << '\n';
}

// поиск непосещённой вершины
int first_not_null(int* visited, int n) {
    for (int i = 0; i < n; i++) {
        if (visited[i] != 0) {
            return visited[i];
        }
    }
    return 0;
}

int main() {

	// размеры матрицы смежности
    int n;
	input >> n;

	//считываем матрицу смежности
	int** matrix = allocate_matrix(n);
    read_matrix(matrix, n);

    //массив посещённых вершин
    int* visited = new int[n];
    for (int i = 0; i < n; i++) {
        visited[i] = i+1;
    }

    // массив для записи компонент связности
    int* connect = new int[n];

    int current = first_not_null(visited, n);

    // поиск компонент связности
    // продолжается, пока не пройдёт все вершины
     do 
     {
         connect = dfs(matrix, n, current, visited);
         print_connect(connect, n);
         current = first_not_null(visited, n);
     } 
     while (current);

     // очистка памяти
     delete_matrix(matrix, n);
     delete[] visited;
     delete[] connect;

	return 0;
}