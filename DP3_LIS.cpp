#include<bits/stdc++.h>
using namespace std;


// _______________________ Recursive Solution _______________________

int _lisRecur(vector<int> &a, int n, int &mx) {

	if (n == 1)
		return 1;

	int mx_ending_here = 1;
	for (int i = 1; i < n; i++) {
		int mx_ending_at_i = _lisRecur(a, i, mx);
		if (a[i - 1] < a[n - 1] && mx_ending_at_i + 1 > mx_ending_here) {
			mx_ending_here = mx_ending_at_i + 1;
		}
	}
	mx = max(mx, mx_ending_here);

	return mx_ending_here;
}

int lisRecur(vector<int> &a, int n) {
	int mx = 1;
	_lisRecur(a, n, mx);
	return mx;
}
// __________________________________________________________________

// _______________________ Bottom-Up DP _______________________

int lisBottomUp(vector<int> &a, int n) {
	vector<int> lis(n);
	lis[0] = 1;

	for (int i = 1; i < n; i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && lis[j] + 1 > lis[i])
				lis[i] = lis[j] + 1;
		}
	}

	return *max_element(lis.begin(), lis.end());
}
// ___________________________________________________________

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &it : a)
		cin >> it;
	cout << "Recurcive: " << lisRecur(a, n) << endl;
	cout << "Bottom-Up DP: " << lisBottomUp(a, n) << endl;
}