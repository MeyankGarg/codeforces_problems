#include <bits/stdc++.h>
using namespace std;

#define int long long int
int mod = 1e9 + 7;

// void change_state(string &s,int i,vector<int>&ans){

// }

void ps(string &s, int k)
{

    // state will represent wheather state is inverted or not
    int state = 0;
    int n = s.length();
    vector<int> ans(n, 0);
    int i = 0;

    for (i = 0; i < (n - 1) && k > 0; i++)
    {

        if ((((s[i] == '1' && state == 0) || (s[i] == '0' && state == 1)) && k % 2 != 0) || (((s[i] == '1' && state == 1) || (s[i] == '0' && state == 0)) && k % 2 == 0))
        {
            // cout<<"asdf";

            state ^= 1;
            ans[i]++;
            k--;
        }
        s[i] = '1';
    }
    // cout<<i<<" "<<k<<" "<<state<<" "<<s<<endl;

    if (i == (n - 1))
    {
        if ((s[i] == '1' && state == 0) || (s[i] == '0' && state == 1))
        {
            // if(k%2==0){
            //     s[i]='1';
            // }else{
            //     s[i] = '0';

            // }
            s[i]='1';
        }
        else if ((s[i] == '0' && state == 0) || (s[i] == '1' && state == 1))
        {
            // if(k%2==0){
            //     s[i]='0';
            // }else{
            //     s[i] = '1';

            // }
            s[i]='0';
            // s[i] = '1';
        }
        ans[i]+=k;
        cout << s << endl;
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }

    // cout<<s<<" -> "<<k<<endl;

    while(i<n && state==1 && k==0){
        if(s[i]=='0'){
            s[i]='1';
        }else{
            s[i]='0';
        }
        i++;
    }

    // k>0

    // ans[n - 1] += k;
    // if(k%2){
    //    if(s[n-1]=='1'){
    //     s[n-1]='0';
    //    }else{
    //     s[n-1]='1';
    //    }
    // }

    cout << s << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main()
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
        ps(s, k);
    }

    return 0;
}
