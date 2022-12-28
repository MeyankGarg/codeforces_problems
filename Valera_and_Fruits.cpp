#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

int ps(map<ll, ll> &h, ll k)
{
    ll ans = 0;

    map<ll, ll> last_day;
    // cout<<"day  fruits  ans  pick_up  pick_l  left"<<endl;
    for (auto itr : h)
    {

       

        ll x = itr.second + last_day[itr.first];

        ll pick_up = min(x, k);
        ans += pick_up;

        ll pick_up_from_last_day = min(last_day[itr.first], pick_up);
        ll left = pick_up - pick_up_from_last_day;

        last_day[itr.first + 1] += (itr.second - left);
        last_day.erase(itr.first);

        // cout<<itr.first<<" "<<itr.second<<" "<<ans<<" "<<pick_up<<" "<<pick_up_from_last_day<<" "<<left<<endl;
    }
    // cout<<endl<<endl;

    for (auto child : last_day)
    {
       
        // ans += min(itr.second, k);
        ans+=min(child.second,k);
        // cout<<itr.first<<" -> ";
        // cout<<itr.second<<" -> "<<ans<<endl;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    map<ll, ll> h;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        h[a] += b;
    }

    cout << ps(h, m) << endl;
    

    return 0;
}


