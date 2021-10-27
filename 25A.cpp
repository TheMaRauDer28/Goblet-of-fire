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
    vector<int> v(n);
    vecin(v);
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        v[i] % 2 == 0 ? even++ : odd++;
    }
    if (even > 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] % 2 != 0)
            {
                cout << i + 1;
                return;
            }
        }
    }
    else if (odd > 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] % 2 == 0)
            {
                cout << i + 1;
                return;
            }
        }
    }
}
int main()
{
    fast;
    solve();
    return 0;
}