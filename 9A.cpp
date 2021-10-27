#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define ll long long

int main()
{
    fast;
    int y, w, d;
    cin >> y >> w;

    y > w ? d = y : d = w;

    int cnt = 0;
    for (int i = d; i <= 6; i++)
    {
        cnt++;
    }

    cout << (cnt / __gcd(cnt, 6)) << "/" << (6 / __gcd(cnt, 6));

    return 0;
}