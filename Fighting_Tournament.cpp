#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

void ps(vector<int> &v, vector<vector<int>> &qry)
{
    for(int i=0;i<qry.size();i++){
        cout<<qry[i][0]<<" "<<qry[i][1]<<" "<<qry[i][2]<<endl;
    }
    cout<<endl;
    int n=v.size();
    int max_ele=v.size();
    vector<int>count_wins(n+3,0);
    int i=0;
    int j=1;
    int k=0;
    int count_round=0;
    vector<int>ans(qry.size());

    while(i<v.size() && v[i]!=max_ele){
        if(v[i]>v[j]){
            count_wins[v[i]]++;
            j++;
        }else{
            i=j;
            count_wins[v[j]]++;
            j++;
        }
        count_round++;
        
        while(k<qry.size() && qry[k][0]==count_round){
            ans[qry[k][2]+1]=count_wins[qry[k][1]];
            k++;





        }
    }

    

    for(int a=0;a<ans.size();a++){
        cout<<ans[a]<<endl;

    }




}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<vector<int>> qry(q, vector<int>(3));
        for (int i = 0; i < q; i++)
        {
            // cin>>qry[i][0]>>qry[i][1];
            cin >> qry[i][1] >> qry[i][0];
            qry[i][2]=i;
        }
        sort(qry.begin(), qry.end());
        ps(v,qry);
    }
    
    return 0;
}
