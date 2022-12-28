#include <bits/stdc++.h>            
using namespace std;

#define ll long long int           
int mod = 1e9 + 7;

int ps(vector<int>&v){
    map<int,int>h;
    for(int i=0;i<v.size();i++){
        h[v[i]]++;
    }
    int t=0,s=0;
    for(auto itr:h){
        if(itr.second>=2){
            t++;
        }else{
            s++;
        }
    }

    if(s%2){
        return t+s/2 + 1;
    }else{
        return t+s/2;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>v(n);
        for (int i = 0;i < n;i++) {
            cin >> v[i];
        }
        cout << ps(v) << endl;


    }


    return 0;
}
