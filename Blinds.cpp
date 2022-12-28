#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

ll ps(vector<int>&v,ll len){
    sort(v.begin(),v.end());
    int n=v.size();
    // for(int i=0;i<n;i++){
    //     cout<<v[i]<<" ";

    // }
    // cout<<endl;
    

    ll sum=0;
    for(int i=0;i<v.size();i++){
        if(v[i]<len){
            continue;
        }
       


        ll temp_sum=0;
        for(int j=i;j<n;j++){
            temp_sum+= v[i] * (v[j]/v[i]);
        }
        // cout<<i<<" "<<temp_sum<<" "<<v[i] <<" "<<sum<<endl;
        sum=max(sum,temp_sum);
    }

    ll temp_sum=0;

    for(int i=0;i<n;i++){
          if(v[i]<len){
            continue;
        }
        temp_sum+= len*(v[i]/len);

      

    }
    
    return max(sum,temp_sum);


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,l;
    cin>>n>>l;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<ps(v,l)<<endl;


    return 0;
}
