#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

int ps(vector<int>&discounts,vector<int>&prices){
    int required_discount=*min_element(discounts.begin(),discounts.end());
    int ans=0;
    sort(prices.begin(),prices.end());
    int i=prices.size()-1;
    while(i>=0){
        int temp=required_discount;
        while(i>=0 && temp--){
            ans+=prices[i];
            i--;
        }
        i-=2;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;
    vector<int> discounts(m);
    for (int i = 0; i < m; i++)
    {
        cin >> discounts[i];
    }
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    cout<<ps(discounts,prices)<<endl;



    return 0;
}
