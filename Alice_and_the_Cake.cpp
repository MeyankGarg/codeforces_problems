#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

bool ps(map<ll,int>&h,ll sum){
    // base case

    if(h[sum]>0){
        h[sum]--;
       return true;
    }
    if(sum==0){
        return false;
    }


    // recursive case
    ll a=sum/2;
    ll b=a;
    if(sum%2){
        b++;

    }

    return ps(h,a)&& ps(h,b);

}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<ll,int>h;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            h[x]++;
        }
        ll sum=0;
        for(auto itr:h){
            sum+= itr.first*itr.second;
        }

        if(ps(h,sum)==false){
            cout<<"NO"<<endl;

        }else{

            // bool check=true;
            // for(auto itr:h){
            //     if(itr.second !=0){
            //         check=false;
            //         break;
            //     }
            // }
            // if(check){
            //     cout<<"YES"<<endl;
            // }else{
            //     cout<<"NO"<<endl;
            // }

            cout<<"YES"<<endl;



        }



       

    }

    return 0;
}
