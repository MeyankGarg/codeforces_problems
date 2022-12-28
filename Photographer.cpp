#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,d;
    cin>>n>>d;
    int a,b;
    cin>>a>>b;
    vector<pair<ll,int>>v;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        ll sum=x*a+y*b;
        v.push_back(make_pair(sum,i+1));
        
    }
    sort(v.begin(),v.end());
    vector<int>ans;

    for(int i=0;i<v.size()&&d>0;i++){
        if(v[i].first <=d){
            d-=v[i].first;
            ans.push_back(v[i].second);
        }

    }

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


    return 0;
}
