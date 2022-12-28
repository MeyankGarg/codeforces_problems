#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;
void ps(vector<int> &v, vector<int> &b)
{
    int n = v.size();
    vector<int>min_val(n,-100);

    for(int i=0;i<n;i++){
        int index=lower_bound(b.begin(),b.end(),v[i])-b.begin();
        min_val[i]=b[index]-v[i];
    }










    
    vector<int> max_val(n, -100);
    int s = 0;
    for (int i = 0; i < n; i++)
    {

        int index = upper_bound(v.begin(), v.end(), b[i]) - v.begin();
        if (index <= (i + 1))
        {

            while (s <= i)
            {
                max_val[s] = b[i] - v[s];
                s++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<min_val[i]<<" ";
    }
    cout<<endl;
    for (int i =0;i< max_val.size(); i++)
    {
        cout << max_val[i] << " ";
    }
    cout << endl;


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        ps(v, b);
    }

    return 0;
}
