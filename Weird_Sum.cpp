#include <bits/stdc++.h>            
using namespace std;

#define ll long long int           
#define pii pair<int,int>    
#define pb push_back      
int mod = 1e9 + 7;

ll ps(vector<int>&v){
    sort(v.begin(),v.end());
    vector<ll>prefix_sum(v.size());
    prefix_sum[0]=v[0];
    for(int i=1;i<v.size();i++){
        prefix_sum[i]=prefix_sum[i-1]+v[i];
    }
    ll ans=0;
    int n=v.size()-1;
    for(int i=0;i<n;i++){
        ll temp=n-i;
        temp*=v[i];
        ll x=prefix_sum.back()-prefix_sum[i] - temp;
        ans+=abs(x);
    }
    return ans;
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r,c;
    cin>>r>>c;
    vector<vector<int>>v(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>v[i][j];
        }
    }
    unordered_map<int,vector<int>>color_x,color_y;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            color_x[v[i][j]].pb(i+1);
            color_y[v[i][j]].pb(j+1);
        }
    }
    ll ans=0;
    for(auto itr:color_x){
        ll x=ps(itr.second);
        ans+=x;

    }
    for(auto itr:color_y){
        ll x=ps(itr.second);
        ans+=x;
    }
    cout<<ans<<endl;

    








    return 0;
}
