#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define ll long long
 
int main()
{
    fast;
    int n,m;
    cin>>n>>m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());

    int ans=0;
    for (int i = 0; i < m; i++)
    {
        if(v[i]<0)
            ans+=(-(v[i]));
    }
    
    cout<<ans;
    return 0;
}