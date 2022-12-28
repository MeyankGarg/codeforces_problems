#include <bits/stdc++.h>
using namespace std;

#define int long long int
int mod = 1e9 + 7;

bool ps(string &s, string &t)
{
    // string new_s = "";
    // string new_t = "";
    vector<int> new_s, new_t;
    int count_a = 0, count_b = 0, count_c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
        {
            // new_s += s[i];
            new_s.push_back(i);
            count_a++;
        }
        else if (s[i] == 'c')
        {
            // new_s += s[i];
            new_s.push_back(i);
            count_b++;
        }
        else
        {
            count_c++;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (t[i] == 'a')
        {
            new_t.push_back(i);
            count_a--;
        }
        else if (t[i] == 'c')
        {
            // new_t += t[i];
            new_t.push_back(i);
            count_b--;
        }
        else
        {
            count_c--;
        }
    }
    if (count_a != 0 || count_b != 0 || count_c != 0)
    {
        return false;
    }
    for (int i = 0; i < new_s.size(); i++)
    {
        if(s[new_s[i]]!=t[new_t[i]]){
            return false;
        }
        if(s[new_s[i]]=='a'){

            if(new_s[i]>new_t[i]){
                return false;
                
            }

        }else{
            if(new_s[i]<new_t[i]){
                return false;
            }

        }
        
    }

    return true;
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
        string s, t;
        cin >> s >> t;
        if (ps(s, t))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
