#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;
// -2,-2, ->means all is well
// -1,-1 means not possible
pair<int, int> give_index(vector<int>& v)
{
    vector<int> temp = v;
    sort(temp.begin(), temp.end());
    int s = -2;
    int e = -2;
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]!=temp[i]){
            if(s==-2){
                s=i;
            }else if(e==-2){
                e=i;
                
            }else{
                return {-1,-1};
            }
        }


    }
   
    return {e,s};
}

pair<int, int> ps(vector<vector<int>>& v)
{
    int s = -2;
    int e = -2;
    vector<pair<int, int>> keep_record;
    for (int i = 0; i < v.size(); i++)
    {
        pair<int, int> p = give_index(v[i]);

        keep_record.push_back(p);
        // cout<<i<<" -> "<<p.first<<" "<<p.second<<endl;
        if (p.first == -1 && p.second == -1)
        {
            return p;
        }
        if (p.first == -2)
        {
            continue;
        }
        if (s == -2)
        {
            s = p.first;
            e = p.second;
        }
        else if (s != p.first || e != p.second)
        {
            return { -1, -1 };
        }
    }
    if (s == -2)
    {
        return { e, s };
    }

    for (int i = 0; i < keep_record.size(); i++)
    {
        if (keep_record[i].first == -2)
        {
            // cout<<i<<endl;

            if (v[i][s] != v[i][e])
            {
                return { -1, -1 };
            }
        }
    }

    return { e, s };
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> v(r, vector<int>(c));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> v[i][j];
            }
        }
        pair<int, int> ans = ps(v);
        if (ans.first == -1)
        {
            cout << -1 << endl;
        }
        else if (ans.first == -2)
        {
            cout << 1 << " " << 1 << endl;
        }
        else
        {
            cout << ans.first + 1 << " " << ans.second + 1 << endl;
        }
    }

    return 0;
}
