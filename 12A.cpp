#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define ll long long

int main()
{
    fast;
    string a, b, c;
    cin >> a >> b >> c;

    if (a[0] == c[2] &&
        a[1] == c[1] &&
        a[2] == c[0] &&
        b[0] == b[2])
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}