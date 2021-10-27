#include<bits/stdc++.h>
using namespace std;

int main(){

    long long int n,m,a,least_num;

    cin>>n>>m>>a;
    
    if (n%a==0 && m%a==0)
    {
        /* code */
        least_num=((n/a))*((m/a));
        cout<<least_num<<endl;
    }

    else if (n%a==0 && m%a!=0)
    {
        /* code */
        least_num=((n/a))*((m/a)+1);
        cout<<least_num<<endl;
    }

    else if (n%a!=0 && m%a==0)
    {
        /* code */
        least_num=((n/a)+1)*((m/a));
        cout<<least_num<<endl;
    }
    
    else
    {
        /* code */
        least_num=((n/a)+1)*((m/a)+1);
        cout<<least_num<<endl;
    }

    return 0;

}