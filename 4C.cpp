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
    vector<string> v(n);
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        // cout<<endl;
        mp[v[i]]++;
        map<string, int>::iterator itr;
        for (auto itr = mp.find(v[i]); itr != mp.end(); itr++)
        {
            int x = itr->second;
            if (x == 1)
            {
                cout << "OK" << endl;
                break;
            }
            else
            {
                cout << itr->first << x-1 << endl;
                break;
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