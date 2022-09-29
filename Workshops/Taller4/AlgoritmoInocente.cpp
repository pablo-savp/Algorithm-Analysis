#include <iostream>
#include <vector>
using namespace std;
int solve(vector<vector<int>> &mat, int i, int j);

int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int longestIncreasingPath(vector<vector<int>> &matrix) {
  int maxPath = 1;
  for (int i = 0; i < matrix.size(); i++)
    for (int j = 0; j < matrix[0].size(); j++)
      maxPath = max(maxPath, solve(matrix, i, j));
  return maxPath-1;
}
int solve(vector<vector<int>> &mat, int i, int j) {
  
  int MAX = 1; 
  for (int k = 0; k < 4; k++) {
    int new_i = i + moves[k][0], new_j = j + moves[k][1];
    if (new_i < 0 || new_j < 0 || new_i >= mat.size() || new_j >= mat[0].size() ||
        mat[new_i][new_j] <= mat[i][j])
      continue;

    MAX = max(MAX, 1 + solve(mat, new_i, new_j));
  }
  return MAX;
}


int main() {

  vector<vector<int>> matrix{
      {10, 11, 15, 12}, {9, 8, 7, 13}, {2, 5, 6, 14}, {3, 4, 1, 11}};

  cout<<"Camino creciente mas largo: "<<longestIncreasingPath(matrix);
}
