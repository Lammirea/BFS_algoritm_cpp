// BFS_algorithm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> convert(vector<vector<int>> a);
void BFS_for_matrix(int s, int* m[], int n);
void BFS_for_list(int ver,int n, vector<vector<int>> AdjList);
int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cin >> n;
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[n];
    }

    srand(time(NULL));
    cout << "Матрица смежности:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 100;
            if (i == j) {
                matrix[i][j] = 0;
            }
            if (matrix[i][j] >= 0 && matrix[i][j] <= 30) {
                matrix[i][j] = 0;
            }
            if (matrix[i][j] >= 31 && matrix[i][j] <= 100) {
                matrix[i][j] = 1;
            }

        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            matrix[i][j] = matrix[j][i];
            cout << matrix[i][j] << " ";

        }
        cout << endl;
    }

    int v;
    cout << "Введите вершину от 1 до " << n << endl;
    cin >> v;
    cout << endl;
    cout << "Обход в ширину для матрицы смежности:" << endl;
    
    BFS_for_matrix(v, matrix, n);
    cout << endl;

    vector<vector<int>> a;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i].push_back(matrix[i][j]);
        }
    }
    cout << "------------------------------------------------" << endl;
    vector<vector<int>> AdjList = convert(a);
    cout << "Список смежности:" << endl;
    for (int i = 0; i < AdjList.size(); i++)
    {
        cout << i;
        for (int j = 0; j < AdjList[i].size(); j++) {
            cout << " -> " << AdjList[i][j];
        }
        cout << endl;
    }
    cout << endl;

    cout << "Обход в ширину для списка смежности:" << endl;
    BFS_for_list(v,n,AdjList);

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

	return 0;
}

void BFS_for_matrix(int s, int* m[],int n) {
    
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);

    visited[s] = true;

    int vis;
    while (!q.empty()) {
        vis = q.front();

        // Print the current node
        cout << vis << "\t";
        q.pop();

        // For every adjacent vertex to the current vertex
        for (int i = 0; i < n; i++) {
            if (m[vis][i] == 1 && (!visited[i])) {

                // Push the adjacent node to the queue
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<vector<int>> convert(vector<vector<int>> a)
{
    vector<vector<int>> adjList(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            if (a[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}

void BFS_for_list(int ver, int n, vector<vector<int>> AdjList) {
    queue<int> q;
    q.push(ver);

    vector<bool> vis(n, false);
    vis[ver] = true;

    while (!q.empty()) {
        int node = q.front();

        q.pop();
        cout << node << "\t";

        vector<int> ::iterator it;
        for (it = AdjList[node].begin(); it != AdjList[node].end(); it++)
        {
            if (!vis[*it]) {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }

}