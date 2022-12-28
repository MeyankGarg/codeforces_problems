#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

void modify_s(string s,int& last_digit,unordered_map<string,int>&h){
    string choti_string=s.substr(0,3);
    char ch=last_digit+'0';

    while(h.count(choti_string + (ch))>0){
        last_digit++;
        ch=last_digit+'0';

    }
    h[choti_string + ch]++;
    last_digit++;


}

int ps(unordered_map<string,int>&h){
    int ans=0;
    int last_digit=0;
    for(auto itr:h){
        while(itr.second>1){
            modify_s(itr.first,last_digit,h);
            itr.second--;
            ans++;


        }
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
        int n;
        cin>>n;
        unordered_map<string,int>h;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            h[s]++;

        }

        cout<<ps(h)<<endl;
        for(auto itr:h){
            cout<<itr.first<<endl;
        }

    }

    return 0;
}
