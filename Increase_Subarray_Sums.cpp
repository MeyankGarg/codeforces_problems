#include <bits/stdc++.h>            
using namespace std;

#define ll long long int           
#define pii pair<int,int>    
#define pb push_back      
int mod = 1e9 + 7;

void ps(vector<int>&v,int t){

    vector<int>max_sub_arr_len(v.size()+2,0);

    for(int i=1;i<=v.size();i++){
        int sum=0;
        int max_sum=0;
        for(int j=0;j<i;j++){
            sum+=v[j];
        }
        max_sum=max(max_sum,sum);
        for(int j=i;j<v.size();j++){
            sum-= v[j-i];
            sum+=v[j];
            max_sum=max(max_sum,sum);


        }
        max_sub_arr_len[i]=max_sum;
    }

    for(int i=0;i<=v.size();i++){
        cout<<max_sub_arr_len[i]<<" ";
    }

    cout<<endl;
    vector<int>ans(v.size()+1,0);
    ans[0]=*(max_element(max_sub_arr_len.begin(),max_sub_arr_len.end()));
    for(int k=1;k<=v.size();k++){

        int max_sum=0;

        for(int i=0;i<=v.size();i++){
            if(i>k){
                int temp=max_sub_arr_len[i] + t*k ;
                max_sum=max(max_sum,temp);
            }else{
                int temp=max_sub_arr_len[i] + t*(i) ;
                max_sum=max(max_sum,temp);

            }

        }
        ans[k]=max_sum;

    }

    for(int i=0;i<=v.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


 
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        ps(v,x);


    }


    return 0;
}
