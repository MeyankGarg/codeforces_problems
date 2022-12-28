#include <bits/stdc++.h>            
using namespace std;

#define ll long long int           
#define pii pair<int,int>    
#define pb push_back      
int mod = 1e9 + 7;


int ps(vector<int>& spend, vector<int>& budget) {
    multiset<int>positives;
    multiset<int>negatives;
    multiset<int>left;
    int zeros = 0;
    for (int i = 0;i < spend.size();i++) {
        int x = budget[i] - spend[i];
        if (x >= 0) {
            positives.insert(x);
        }
        else if (x < 0) {
            negatives.insert(abs(x));
        }
        
    }

    // for (auto itr : positives) {
    //     cout << itr << " ";
    // }
    // cout << endl;
    // for (auto itr : negatives) {
    //     cout << itr << " ";
    // }
    // cout << endl;
    int ans = 0;
    for (auto itr : negatives) {

        auto itr_ele= positives.lower_bound(itr);
        // cout<<itr<<"->  "<<*(itr_ele)<<endl;
        if(itr_ele!=positives.end()){
            ans++;
            positives.erase(itr_ele);
        }else{

            
            break;

        }


    }
    ans+=  positives.size()/2;



    return ans;
}





int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>spend(n);
        for (int i = 0;i < n;i++) {
            cin >> spend[i];
        }

        vector<int>budget(n);

        for (int i = 0;i < n;i++) {
            cin >> budget[i];
        }
        cout << ps(spend, budget) << endl;
    }


    return 0;
}
