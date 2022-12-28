#include <bits/stdc++.h>
using namespace std;

#define int long long int
int mod = 1e9 + 7;

int ps(vector<int>&v,int w){
    vector<int>works(w+1,0);
    for(int i=0;i<v.size();i++){
        works[v[i]]++;
    }
    // for(int i=1;i<=w;i++){
    //     cout<<works[i]<<" ";
    // }
    // cout<<endl;

    int l=0;
    int r=2*v.size();
    int ans=2*v.size();
    while(l<=r){
        int mid=(l+r)/2;
        int t=mid;
        // int left_time=0;
        int left_work=0;
        for(int i=1;i<=w;i++){
            if(works[i]>=t){
                left_work+=works[i]-t;

            }else{
                left_work-=(t-works[i])/2;

            }
            
        }
        if(left_work>0){
            l=mid+1;
             

        }else{
            ans=mid;
           
            r=mid-1;
        }
        // cout<<l<<" "<<r<<" "<<ans<<" "<<left_work<<endl;

    }

    return ans;




}


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        
        int w;
        cin>>w;
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        cout<<ps(v,w)<<endl;

    }

    return 0;
}
