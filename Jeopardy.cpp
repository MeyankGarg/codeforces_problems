#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;


ll ps(vector<int>&v,vector<int>&auction){
    ll sum=accumulate(v.begin(),v.end(),0);
    sum-= accumulate(auction.begin(),auction.end(),0);
    // cout<<sum<<" -> "<<endl;
    

    sort(auction.begin(),auction.end());
    // for(int i=0;i<auction.size();i++){
    //     cout<<auction[i]<<" ";
    // }cout<<endl;
    bool check=false;
    ll temp_sum=sum;
    for(int i=0;i<auction.size();i++){
        if(sum<=auction[i]){
            check=true;
            break;
            
        }
        sum*=2;
    }
    // if(!check){
    //     return sum;
    // }
    
    temp_sum+=auction.back();
    temp_sum*= (1<<(auction.size()-1));
    cout<<sum<<" "<<temp_sum<<endl;
    return max(temp_sum,sum);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>auction(m);
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        auction[i]=v[x-1];
    }
    cout<<ps(v,auction)<<endl;;


    return 0;
}
