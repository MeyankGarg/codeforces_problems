#include <bits/stdc++.h>            
using namespace std;

#define ll long long int           
#define pii pair<int,int>    
#define pb push_back      
int mod = 1e9 + 7;

void all_prime_nums(int n,unordered_set<int>&primes){
    // n->max_value of of a[i]
    vector<int>visited(n+1,false);
    
    for(int i=2;i<=n;i++){
        if(visited[i]==false){
            // means it's prime
            primes.insert(i);
            // make all it's factors till n visited....as they are for sure not prime
            for(int k=1;k*i<n;k++){
                visited[k*i]=true;
            }

        }


    }

    // for(int i=0;i<primes.size();i++){
    //     cout<<primes[i]<<" ";
    // }
    // cout<<endl;

}


// required product will be prime if and only if one of them is prime,rrest of them is 1

void problem_solver(vector<int>& nums, int e,unordered_set<int>&prime) {
    ll k = 0;

    for(int i=0;i<nums.size();i++){


       if(prime.find(nums[i]) != prime.end()){
         // means it's prime number
        //  we will count all valid one to it's right(let it's count be r) and left(let it's count be l) and  for each l we have count (r+1) hence ans = (l* (r+1) )+r;(as we have to count prime number itself)
        ll l=0;
        for(int a=i-e;a>=0 && nums[a]==1;a-=e){

                l++;

        }

        ll r=0;
        for(int a=i+e;a<nums.size() && nums[a]==1;a+=e){

                r++;

        }
        k+= (l)*(r+1) +r ;

        // cout<<i<<" "<<nums[i]<<" "<<l<<" "<<r<<" "<<k<<endl;;
       }

       



    }
    cout<<k<<endl;

    // return k;


}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
// stores all prime numbers till max_value of a[i];
    unordered_set<int>primes;

    all_prime_nums(1e6,primes);



    while (t--) {
        int n, e;
        cin >> n >> e;
        vector<int>nums(n);
        for (int i = 0;i < n;i++) {
            cin >> nums[i];
        }
        problem_solver(nums,e,primes);
    }


    return 0;
}
