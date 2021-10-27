#include<bits/stdc++.h>
using namespace std;
// _______________________ Brute Force _______________________

// Generate All Subsequence for one given string O(2^N)
// Check every Subsequence in other string O(N)
// Total TC: O(N*2^N)
// ___________________________________________________________

// _______________________ Recurcive _______________________

int lcsRecur(string str1, string str2, int n, int m) {

	if (n == 0 || m == 0)
		return 0;

	if (str1[n - 1] == str2[m - 1])
		return 1 + lcsRecur(str1, str2, n - 1, m - 1);

	return max(lcsRecur(str1, str2, n, m - 1), lcsRecur(str1, str2, n - 1, m));
}
// _________________________________________________________

// _______________________ DP Tabulation _______________________

int lcsTabuler(string str1, string str2) {

	int n = str1.length(), m = str2.length();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {

			if (i == 0 || j == 0)
				dp[i][j] = 0;

			else if (str1[i] == str2[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];

			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[n][m];
}
// _____________________________________________________________

// _______________________ Space Optimized DP _______________________

// 1) 2*N Space
int lcsOptimized(string str1, string str2) {

	int n = str1.length(), m = str2.length();
	vector<vector<int>> dp(2, vector<int>(m + 1));

	bool binary_index;
	for (int i = 0; i <= n; i++) {

		binary_index = i & 1;
		for (int j = 0; j <= m; j++) {

			if (i == 0 || j == 0)
				dp[binary_index][j] = 0;
			else if (str1[i - 1] == str2[j - 1])
				dp[binary_index][j] = 1 + dp[1 - binary_index][j - 1];
			else
				dp[binary_index][j] = max(dp[1 - binary_index][j], dp[binary_index][j - 1]);
		}
	}

	return dp[binary_index][m];
}

// 2) 1*N Space
int lcsMAXOptimized(string str1, string str2) {

	int n = str1.length(), m = str2.length();
	vector<int> dp(m + 1);

	int prev = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {

			int temp = dp[j];

			if (i == 0 || j == 0)
				dp[j] = 0;
			else if (str1[i - 1] == str2[j - 1])
				dp[j] = 1 + prev;
			else
				dp[j] = max(dp[j], dp[j - 1]);

			prev = temp;
		}
	}

	return dp[m];
}
// __________________________________________________________________

// _______________________ Print the Sequence as Well _______________________

string lcs(string str1, string str2) {

	int n = str1.length(), m = str2.length();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {

			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (str1[i] == str2[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	string lcs = "";

	int i = n, j = m;
	while (i > 0 && j > 0) {

		if (str1[i - 1] == str2[j - 1]) {
			lcs += str1[i - 1];
			i--, j--;
		} else if (dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		} else {
			j--;
		}
	}

	reverse(lcs.begin(), lcs.end());
	return lcs;
}
// ___________________________________________________________________________

int main() {

	string str1, str2;
	cin >> str1 >> str2;

	cout << "Longest Common Subsequence (Recurcive): " << lcsRecur(str1, str2, str1.length(), str2.length()) << endl;

	cout << "Longest Common Subsequence (Tabulation): " << lcsTabuler(str1, str2) << endl;

	cout << "Longest Common Subsequence (Space Optimized): " << lcsOptimized(str1, str2) << endl;

	cout << "Longest Common Subsequence (1D Array): " << lcsMAXOptimized(str1, str2) << endl;

	cout << "LCS: " << lcs(str1, str2) << endl;

	return 0;
}