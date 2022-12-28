#include <bits/stdc++.h>
using namespace std;

#define int long long int
int mod = 1e9 + 7;

void ps(vector<int>&v){
    v.insert(v.begin(),-1);
    // unordered_map<int,int>pos;
    vector<int>pos(v.size()+2,0);
    for(int i=1;i<v.size();i++){
        pos[v[i]]=i;
    }
    vector<int>ans(v.size()+1,0);
    int n=v.size()-1;
    // int count_shift=0;
    for(int i=n;i>=1;i--){
        
        
       
        ans[i]=pos[i]%i;
        int x=i-pos[i];
        // pos.erase(i);
        // cout<<i<<" "<<" "<<pos[i]<<" "<<ans[i]<<" -> "<<endl;
        for(int k=1;k<=n;k++){
            pos[k]=(pos[k]+x)%i;
        }
        //  for(int k=1;k<=n;k++){
        //     // pos[i]=(pos[i]+x)%i;
        //     cout<<pos[k]<<" ";
        // }
        // cout<<endl;
       

        
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        ps(v);

    }

    return 0;
}
