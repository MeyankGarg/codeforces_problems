#include <bits/stdc++.h>
using namespace std;

#define int long long int
int mod = 1e9 + 7;

int ps(vector<int> &v)
{
    int n = v.size();
    int ans = LLONG_MAX;
    for (int k = 0; k < n; k++)
    {
        vector<int> b(n, 0);
        int temp_ans = 0;
        for (int i = k - 1; i >= 0; i--)
        {
            // int a=b[i+1];

            int x = abs(b[i + 1]) / abs(v[i]) + 1;
            temp_ans += x;
            b[i] = -v[i] * x;
            // while(b[i]>=b[i+1]){
            //     b[i]=b[i]-v[i];
            //     temp_ans++;

            // }
            // cout<<b[i]<<" "<<x<<endl;
        }


        for (int i = k + 1; i < n; i++)
        {
            // int a=b[i-1];
            int x;
            if (b[i - 1] == 0)
            {
                x=1;
                temp_ans += 1;
                b[i] = v[i];
            }
            else
            {
                  x= abs(b[i - 1]) / abs(v[i]) + 1;

                temp_ans += x;
                b[i] = v[i] * x;
            }

            // while(b[i]<=b[i-1]){
            //     b[i]=b[i]+v[i];
            //     temp_ans++;
            // }
            // cout<<b[i]<<" "<<x<<endl;
        }
        // cout << k << " " << temp_ans << endl;
        
        ans = min(ans, temp_ans);
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << ps(v) << endl;
    // }

    return 0;
}
