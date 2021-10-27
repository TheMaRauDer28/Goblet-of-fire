#include<bits/stdc++.h>
using namespace std;

// _______________________ Recurcive _______________________

int mpcRecur(vector<vector<int>> &mat, int x, int y) {

	if (x < 0 || y < 0)
		return INT_MAX;

	if (x == 0 && y == 0)
		return mat[x][y];

	return mat[x][y] + min({
		mpcRecur(mat, x - 1, y - 1),
		mpcRecur(mat, x, y - 1),
		mpcRecur(mat, x - 1, y)
	});

}
// _________________________________________________________

// _______________________ Tabulation _______________________

int mpcTabuler(vector<vector<int>> &mat, int x, int y) {

	int row = mat.size();
	int columns = mat[0].size();

	int dp[row][columns];

	dp[0][0] = mat[0][0];
	for (int i = 1; i < columns; i++)
		dp[0][i] = dp[0][i - 1] + mat[0][i];
	for (int i = 1; i < row; i++)
		dp[i][0] = dp[i - 1][0] + mat[i][0];

	for (int i = 1; i < row; i++) {
		for (int j = 1; j < columns; j++) {

			dp[i][j] = mat[i][j] + min({
				dp[i - 1][j - 1],
				dp[i][j - 1],
				dp[i - 1][j]
			});
		}
	}

	return dp[x][y];
}
// We can even use cost matrix as a DP matrix to optimize space
// __________________________________________________________

// Can be used Dijkstra`s Algorithm for Shortest Path

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> mat(n, vector<int>(m));
	for (vector<int> &row : mat) {
		for (int &cell : row) {
			cin >> cell;
		}
	}

	int x, y;
	cin >> x >> y;

	cout << "Min Path Cost (Recurcive): " << mpcRecur(mat, x, y) << endl;

	cout << "Min Path Cost (Tabulation): " << mpcTabuler(mat, x, y) << endl;
}