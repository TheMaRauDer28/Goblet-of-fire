#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, s1;
    cin >> s >> s1;

    reverse(s.begin(), s.end());

    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        /* code */
        if (s[i] != s1[i])
        {
            /* code */
            cnt++;
            break;
        }
    }

    if (cnt == 1)
    {
        /* code */
        cout << "NO";
    }
    else
    {
        /* code */
        cout << "YES";
    }

    return 0;
}