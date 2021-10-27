#include <bits/stdc++.h>
using namespace std;

// _______________________ Recurcive _______________________

int editDistanceRecur(string initial, string target, int n, int m) {

	if (n == 0)
		return m;
	if (m == 0)
		return n;

	if (initial[n - 1] == target[m - 1])
		return editDistanceRecur(initial, target, n - 1, m - 1);

	return 1 + min(
	{	editDistanceRecur(initial, target, n - 1, m),		// Erase
		editDistanceRecur(initial, target, n, m - 1),		// Insert
		editDistanceRecur(initial, target, n - 1, m - 1)	// Replace
	});
}
// Time Complexity: O(3^m)
// Worst Case: None of char of two string matches
// _________________________________________________________

// _______________________ Tabulation _______________________

int editDistanceTabuler(string initial, string target) {

	int n = initial.length(), m = target.length();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {

			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;
			else if (initial[i - 1] == target[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min(
			{	dp[i - 1][j],		// Erase
				dp[i][j - 1],		// Insert
				dp[i - 1][j - 1]	// Replace
			});
		}
	}

	return dp[n][m];
}
// __________________________________________________________

// _______________________ DP Optimal _______________________

int editDistanceOptimized(string initial, string target) {

	int n = initial.length(), m = target.length();
	vector<vector<int>> dp(2, vector<int>(m + 1));

	bool binary_index;
	for (int i = 0; i <= n; i++) {

		binary_index = i & 1;
		for (int j = 0; j <= m; j++) {

			if (i == 0)
				dp[binary_index][j] = j;
			else if (j == 0)
				dp[binary_index][j] = i;
			else if (initial[i - 1] == target[j - 1])
				dp[binary_index][j] = dp[1 - binary_index][j - 1];
			else
				dp[binary_index][j] = 1 + min(
			{	dp[1 - binary_index][j],		// Erase
				dp[binary_index][j - 1],		// Insert
				dp[1 - binary_index][j - 1]		// Replace
			});
		}
	}

	return dp[binary_index][m];
}

int editDistanceMAXOptimized(string initial, string target) {

	int n = initial.length(), m = target.length();
	vector<int> dp(m + 1);

	int prev;
	for (int i = 0; i <= n; i++) {

		for (int j = 0; j <= m; j++) {
			int temp = dp[j];
			if (i == 0)
				dp[j] = j;
			else if (j == 0)
				dp[j] = i;
			else if (initial[i - 1] == target[j - 1])
				dp[j] = prev;
			else
				dp[j] = 1 + min(
			{	dp[j],		// Erase
				dp[j - 1],	// Insert
				prev		// Replace
			});
			prev = temp;
		}
	}

	return dp[m];
}
// __________________________________________________________


int main() {

	string initial, target;
	cin >> initial >> target;

	cout << "Edit Distance (Recurcive): " << editDistanceRecur(initial, target, initial.length(), target.length()) << endl;

	cout << "Edit Distance (Tabulation): " << editDistanceTabuler(initial, target) << endl;

	cout << "Edit Distance (Space Optimized): " << editDistanceOptimized(initial, target) << endl;

	cout << "Edit Distance (1D DP): " << editDistanceMAXOptimized(initial, target) << endl;
	return 0;
}