#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int cu=0,cl=0;

    cin>>s;

    for (int i = 0; i < s.length(); i++)
    {
        /* code */
        if (isupper(s.at(i)))
        {
            /* code */
            cu++;
        }
        else if (islower(s.at(i)))
        {
            /* code */
            cl++;
        }
        
    }
    
    if (cu>cl)
    {
        /* code */
        for (int i = 0; i < s.length(); i++)
        {
            /* code */
            if (islower(s.at(i)))
            {
                /* code */
                s.at(i)-=32;
            }
            
        }
        
    }

    else if (cl>=cu)
    {
        /* code */
        for (int i = 0; i < s.length(); i++)
        {
            /* code */
            if (isupper(s.at(i)))
            {
                /* code */
                s.at(i)+=32;
            }
        }
        
    }
    
    cout<<s;
    
    return 0;
}