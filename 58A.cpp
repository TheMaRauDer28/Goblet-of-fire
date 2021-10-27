#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    string s1="hello";
    string s2;
    int j=0;
    for (int i = 0; i < s.length(); i++)
    {
        /* code */
        if (s[i]==s1[j])
        {
            /* code */
            s2[j]=s[i];
            j++;
        }        
    }

    int cnt=0;
    for (int i = 0; i < s1.length(); i++)
    {
        /* code */
        if (s1[i]==s2[i])
        {
            /* code */
            cnt++;
        }
    }
    
    cnt==5 ? cout<<"YES" : cout<<"NO";
    return 0;
}