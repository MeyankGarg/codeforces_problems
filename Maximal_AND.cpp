#include <bits/stdc++.h>
using namespace std;

#define int long long int
int mod = 1e9 + 7;

int ps(vector<int> &v, int k)
{
    int ans = 0;
    int n = v.size();
    int j = 30;
    while (j >= 0)
    {
        int jth_bit = 1 << j;
        j--;
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] & jth_bit)
            {
                x++;
            }
        }
        if ( n - x <= k)
        {
            // cout<<j+1<<" "<<x<<" "<<jth_bit<<endl;
            ans += jth_bit;
            k = k + x - n;
        }
    }
    // cout<<ans<<endl;
    if (ans == 0)
    {
        ans=v[0];
        for (int i = 1; i < n; i++)
        {
           ans=ans&v[i];
        }
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        cout << ps(v, k) << endl;
    }

    return 0;
}
