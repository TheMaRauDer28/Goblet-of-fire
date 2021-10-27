#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define ll long long

int main()
{
    fast;
    string s;
    cin >> s;

    int i = 0;
    while (i < s.length())
    {
        if (s[i] == '.')
        {
            cout << 0;
            i += 1;
        }
        else if (s[i] == '-' && s[i + 1] == '.')
        {
            cout << 1;
            i += 2;
        }
        else if (s[i] == '-' && s[i + 1] == '-')
        {
            cout << 2;
            i += 2;
        }
    }

    return 0;
}