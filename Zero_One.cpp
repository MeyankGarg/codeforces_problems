#include <bits/stdc++.h>            
using namespace std;

#define ll long long int           
#define pii pair<int,int>    
#define pb push_back      
int mod = 1e9 + 7;


void problem_solver(string& s1, string& s2, ll x, ll y) {
    bool take_consicutive_indeces = false;

    if (x <= y) {
        take_consicutive_indeces = true;


    }

    ll count_differences = 0;
    ll count_consicutive_ones = 0;

    for (int i = 0;i < s1.length();i++) {


        if (s1[i] != s2[i]) {
            if ((i) > 0 && s1[i - 1] != s2[i - 1]) {
                count_consicutive_ones += 2;
            }
            count_differences++;
        }
    }

    // cout << count_differences << " " << count_consicutive_ones << " " << take_consicutive_indeces << endl;;

    if (count_differences % 2) {
        cout << -1 << endl;
        return;
    }

    if (take_consicutive_indeces) {
        ll ans = (count_consicutive_ones / 2) * x + ((count_differences - count_consicutive_ones) / 2) * y;
        cout << ans << endl;

    }
    else {
        if (count_differences == 2 ) {
            cout << min(x, 2 * y) << endl;
            return;
        }

        ll ans = (count_differences / 2) * y;
        cout << ans << endl;

    }










}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        string s1, s2;
        cin >> s1 >> s2;

        problem_solver(s1, s2, x, y);

    }


    return 0;
}
