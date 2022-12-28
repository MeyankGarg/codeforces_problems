#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

void ps(string &s, int k)
{
    int n=s.length();
    int i=n-1;
    while( i>=0 && s[i]=='1'){
        i--;
    }
    int j=i-1;
    while(j>=0 && k>0){
        while(j>=0 && s[j]!='1'){
            j--;
        }
        int len=i-j;
        if(len>k){
            break;

        }else{
            swap(s[i],s[j]);
            i--;
            j--;
            k-=len;
        }


    }
    // cout<<s<<endl;
    // cout<<i<<" "<<j<<endl;
    ll result=0;
    for(int i=0;i<(n-1);i++){

        int num=stoi(s.substr(i,2));
        result+=num;




    }
    cout<<result<<endl;


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ps(s,k);
    }

    return 0;
}
