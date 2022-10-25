#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"
#define minvec(v) min_element(v.begin(), v.end())
#define maxvec(v) max_element(v.begin(), v.end())
#define vecin(v)       \
    for (auto &it : v) \
    cin >> it
#define vecout(v)    \
    for (auto i : v) \
    cout << i << " "
void func()
{
    int n, k;
    cin >> n >> k;

    if (k == 1)
    {
        if (n == 0 || n % 4 == 0)
            cout << "On" << endl;
        else
            cout << "Ambiguous" << endl;
    }
    else
    {
        if (n % 4 != 0)
            cout << "On" << endl;
        else
            cout << "Off" << endl;
    }
}
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        func();
    return 0;
}