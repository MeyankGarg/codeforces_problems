#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

int sum_of_digits(ll n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n=n/10;
    }
    return sum;
}

bool checkperfectsquare(ll n)
{
     
    // If ceil and floor are equal
    // the number is a perfect
    // square
    if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) {
        // cout << "perfect square";
        return true;
    }
    else {
        // cout << "not a perfect square";
        return false;
    }
}
 



int ps(ll n){

    for(ll i=0;i<=90;i++){

        ll d=i*i+4*n;


        // if(checkperfectsquare(d)){
            // cout<<sqrt(d)<<" "<<d<<endl;
            ll a=sqrt(d);
            if(a*a == d){
                // cout<<d<<endl;
                // cout<<"mayank"<<endl;

                 ll x=(sqrt(d)-i)/2;
            if(sum_of_digits(x)==i){
                return x;
            }
            }
           
        // }


    }
    return -1;


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;

    cout<<ps(n)<<endl;




    return 0;
}
