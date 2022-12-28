#include <bits/stdc++.h>
using namespace std;

#define int long long int
int mod = 1e9 + 7;

int find_2_pow_in_n(int n){
    if(n==0){
        return 0;
    }
    int ans=0;
    while(n%2==0){
        n=n/2;
        ans++;
    }
    return ans;
}



int find_ans_for_each_val(int n){
    // int ans=15;
    if(n==0){
        return 0;
    }

    int x=find_2_pow_in_n(n);
    int ans=15-x;
    // cout<<n<<" "<<x<<endl;
    for(int i=1;i<=15;i++){
        int op1=find_2_pow_in_n(n+i);
        // cout<<n+i<<" "<<op1<<endl;
        op1=15-op1+i;
        ans=min(ans,op1);

    }
    return ans;

}

void ps(vector<int>&v){
    for(int i=0;i<v.size();i++){
        cout<<find_ans_for_each_val(v[i])<<" ";
    }
    cout<<endl;

    

}


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ps(v);

    return 0;
}
