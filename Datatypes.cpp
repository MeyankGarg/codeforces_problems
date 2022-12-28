#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

bool ps(vector<int>&v){
    sort(v.begin(),v.end());
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<v.size()-1;i++){
        if(v[i]*2 > v[i+1] && v[i+1]>v[i]){
            // cout<<i<<" -> "<<endl;
            return true;
        }
    }
    return false;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
   
    if(ps(v)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }


    return 0;
}
