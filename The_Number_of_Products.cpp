#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

ll count_negative_pairs(vector<int> &v, vector<int> &count_negatives)
{
    ll odd_negatives = 1;
    ll even_negatives = 0;
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (count_negatives[i] & 1)
        {

            ans += odd_negatives;
            even_negatives++;
        }
        else
        {
            ans += even_negatives;
            odd_negatives++;
        }
        // cout<<i<<" "<<ans<<endl;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> count_negatives(n, 0);
    if (v[0] < 0)
    {
        count_negatives[0] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        count_negatives[i] = count_negatives[i - 1];
        if (v[i] < 0)
        {
            count_negatives[i]++;
        }
    }

    // for(int i=0;i<n;i++){
    //     cout<<count_negatives[i]<<" ";
    // }
    // cout<<endl;

    ll negative_pairs = count_negative_pairs(v, count_negatives);
    ll positive_pairs = (ll)n * (n + 1) / 2;
    positive_pairs-=negative_pairs;

    cout << negative_pairs << " " << positive_pairs << endl;

    return 0;
}
