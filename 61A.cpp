#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s1, s2, ans;
    cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); i++)
    {
        /* code */
        if (s1[i] != s2[i])
        {
            /* code */
            ans.push_back('1');
        }
        else
        {
            /* code */
            ans.push_back('0');
        }
    }

    cout << ans;

    return 0;
}