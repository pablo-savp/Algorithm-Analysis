#include <bits/stdc++.h>
using namespace std;

// Stores the number of rows
// and columns in given matrix
int N, M;

// Maximum number of rows
// and columns possible
#define MAXM 100
#define MAXN 100

int dx[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int dy[9] = { 0, 0, 0, -1, -1, -1, 1, 1, 1 };

// Function to check if the
// cell (x, y) is valid or not
bool isValid(int x, int y)
{
	return (x >= 0 && y >= 0
			&& x < N && y < M);
}

// Function to print the matrix grid[][]
void printGrid(bool grid[MAXN][MAXM])
{
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			if (grid[row][col])
				cout << "x ";
			else
				cout << "_ ";
		}
		cout << endl;
	}
}

// Function to check if the cell (x, y)
// is valid to have a mine or not
bool isSafe(int arr[MAXN][MAXM], int x, int y)
{

	if (!isValid(x, y))
		return false;

	for (int i = 0; i < 9; i++) {

		if (isValid(x + dx[i], y + dy[i])
			&& (arr[x + dx[i]][y + dy[i]] - 1 < 0))
			return (false);
	}

	for (int i = 0; i < 9; i++) {
		if (isValid(x + dx[i], y + dy[i]))

			arr[x + dx[i]][y + dy[i]]--;
	}

	return true;
}

bool findUnvisited(bool visited[MAXN][MAXM],
				int& x, int& y)
{
	for (x = 0; x < N; x++)
		for (y = 0; y < M; y++)
			if (!visited[x][y])
				return (true);
	return (false);
}

bool isDone(int arr[MAXN][MAXM],
			bool visited[MAXN][MAXM])
{
	bool done = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			done
				= done && (arr[i][j] == 0)
				&& visited[i][j];
		}
	}

	return (done);
}

bool SolveMinesweeper(bool grid[MAXN][MAXM],
					int arr[MAXN][MAXM],
					bool visited[MAXN][MAXM])
{

	bool done = isDone(arr, visited);

	if (done)
		return true;

	int x, y;

	if (!findUnvisited(visited, x, y))
		return false;

	visited[x][y] = true;

	if (isSafe(arr, x, y)) {

		grid[x][y] = true;

		if (SolveMinesweeper(grid, arr, visited))

			return true;

		grid[x][y] = false;
		for (int i = 0; i < 9; i++) {
			if (isValid(x + dx[i], y + dy[i]))
				arr[x + dx[i]][y + dy[i]]++;
		}
	}

	if (SolveMinesweeper(grid, arr, visited))

		return true;

	visited[x][y] = false;

	return false;
}

void minesweeperOperations(int arr[MAXN][MAXN], int N,
						int M)
{
	bool grid[MAXN][MAXM];
	bool visited[MAXN][MAXM];

	memset(grid, false, sizeof(grid));
	memset(visited, false, sizeof(visited));

	if (SolveMinesweeper(grid, arr, visited)) {

		printGrid(grid);
	}

	else
		printf("No solution exists\n");
}

// Driver Code
int main()
{
	N = 7;
	M = 7;
	int arr[MAXN][MAXN] = {
		{ 1, 1, 0, 0, 1, 1, 1 },
		{ 2, 3, 2, 1, 1, 2, 2 },
		{ 3, 5, 3, 2, 1, 2, 2 },
		{ 3, 6, 5, 3, 0, 2, 2 },
		{ 2, 4, 3, 2, 0, 1, 1 },
		{ 2, 3, 3, 2, 1, 2, 1 },
		{ 1, 1, 1, 1, 1, 1, 0 }
	};

	minesweeperOperations(arr, N, M);

	return 0;
}
