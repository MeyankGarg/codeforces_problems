#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

ll ps(vector<int>&presents_in_stack, vector<int>&list_of_presents){
    unordered_set<int>presents_till_now;
    ll ans=0;
    ll count_presents=0;

    for(int i=0,j=0;i<list_of_presents.size();i++){

       if(presents_till_now.find(list_of_presents[i])!=presents_till_now.end()){

        ans++;
        

       }else{
        while(j<presents_in_stack.size() && presents_in_stack[j]!=list_of_presents[i]){
            presents_till_now.insert(presents_in_stack[j]);
            count_presents++;
            j++;
        }

        ans+=(2*count_presents+1);




       }

       count_presents--;

    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>presents_in_stack(n);
        for(int i=0;i<n;i++){
            cin>>presents_in_stack[i];
        }
        vector<int>list_of_presents(m);
        for(int i=0;i<m;i++){
            cin>>list_of_presents[i];
        }

        cout<<ps(presents_in_stack,list_of_presents)<<endl;;
    }

    return 0;
}
