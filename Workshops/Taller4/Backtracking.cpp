#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j);

int main() {

  // Generar Matriz Aleatoria para Analisis Experimental
  int n = 18;

  cout << "Tamaño de la matriz: " << n << "x" << n << endl;
  vector<vector<int>> matrix(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      matrix[i][j] = rand() % 10;
    }
  }

  // Imprimimos la matriz generada
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  vector<vector<int>> dp(n, vector<int>(n, 0));
  int max = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int len = dfs(matrix, dp, i, j);
      if (len > max)
        max = len;
    }
  }

  cout << endl;
  cout << "Camino creciente mas largo: " << max << endl;

  vector<vector<int>> path;
  int x = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dp[i][j] == max) {
        vector<int> p{i, j};
        path.push_back(p);
        max--;
        for (x = 0; x < n; x++) {
          if (dp[i][x] == max) {
            vector<int> p{i, x};
            path.push_back(p);
            max--;
            x = 0;
          }
        }
        i = 0;
      }
    }
  }

  int aux = 0;
  cout << "--Secuencia que genera el camino creciente mas largo--" << endl;
  for (int i = 0; i < path.size(); i++) {
    if (i == 0) {

      cout << matrix[path[i][0]][path[i][1]] << " ";
      aux = matrix[path[i][0]][path[i][1]];

    } else {

      cout << aux + 1 << " ";
      aux = aux + 1;
    }
  }
  cout << endl;

  return 0;
}

int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {
  if (dp[i][j] != 0)
    return dp[i][j];

  int n = matrix.size();
  int max = 1;
  if (i > 0 && matrix[i - 1][j] == matrix[i][j] + 1) {
    int len = 1 + dfs(matrix, dp, i - 1, j);
    if (len > max)
      max = len;
  }
  if (i < n - 1 && matrix[i + 1][j] == matrix[i][j] + 1) {
    int len = 1 + dfs(matrix, dp, i + 1, j);
    if (len > max)
      max = len;
  }
  if (j > 0 && matrix[i][j - 1] == matrix[i][j] + 1) {
    int len = 1 + dfs(matrix, dp, i, j - 1);
    if (len > max)
      max = len;
  }
  if (j < n - 1 && matrix[i][j + 1] == matrix[i][j] + 1) {
    int len = 1 + dfs(matrix, dp, i, j + 1);
    if (len > max)
      max = len;
  }

  dp[i][j] = max;
  return max;
}
