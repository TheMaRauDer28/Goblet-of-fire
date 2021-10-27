#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define ll long long

int main()
{
    fast;
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }
    sort(v.rbegin(), v.rend());

    int ans = 0, cnt = 0, sum = 0;
    for (int i = 0; i < m; i++)
    {
        while (v[i].second-- && sum <= n)
        {
            ans += v[i].first;
            sum++;
            cnt++;
            if (cnt == n)
            {
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}