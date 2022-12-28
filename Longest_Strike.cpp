#include <bits/stdc++.h>
using namespace std;

#define int long long int
int mod = 1e9 + 7;

vector<vector<int>> modify_v(vector<int>&v){

    vector<vector<int> >ans;
    int i=0;
    while(i<v.size()){
        int count_ele=0;
        int ele=v[i];
        while(i<v.size() && v[i]==ele){
            count_ele++;
            i++;
        }
        ans.push_back({ele,count_ele});
    }
    return ans;

}

void ps(vector<int>&nums,int k){
    sort(nums.begin(),nums.end());
    vector<vector<int> >v=modify_v(nums);
    int i=0;
    while(i<v.size() && v[i][1]<k){
        i++;
    }
    if(i>=v.size()){
        cout<<-1<<endl;
        return ;
    }
    int l=v[i][0];
    int r=v[i][0];
    while(i<v.size()){
        int temp_l=v[i][0];
        int temp_r=v[i][0];
        while((i+1)<v.size() && (v[i+1][0]==v[i][0]+1) && v[i+1][1]>=k ){
            i++;
            temp_r=v[i][0];
        }
        if((temp_r-temp_l) > (r-l)){
            r=temp_r;
            l=temp_l;
        }
        
        i++;
        while(i<v.size() && v[i][1]<k){
            i++;
        }
    }

    cout<<l<<" "<<r<<endl;

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
        int k;
        cin>>k;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        ps(v,k);

    }

    return 0;
}
