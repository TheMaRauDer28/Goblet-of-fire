#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define minvec(v) min_element(v.begin(), v.end())
#define maxvec(v) max_element(v.begin(), v.end())
#define vecin(v)       \
    for (auto &it : v) \
    cin >> it
#define vecout(v)    \
    for (auto i : v) \
    cout << i << " "
const int MN = 4e5 + 2;
ll arr[MN];

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if ((s[i] == 'R' && s[i + 1] == 'R') || (s[i] == 'L' && s[i + 1] == 'L'))
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
