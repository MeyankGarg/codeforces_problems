#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

void ps(vector<int> &v)
{
    if (v[0] < 0)
    {
        cout << -1 << endl;
        return;
    }
    unordered_map<int, int> visited;
    vector<int> prefix_sum(v.size());
    prefix_sum[0] = v[0];
    visited[v[0]]++;
    int count_d = 0;
    for (int i = 1; i < v.size(); i++)
    {

        if ((v[i] > 0 && visited.count(v[i]) > 0)||(v[i]<0 && (visited.count(abs(v[i]))==0 || visited[abs(v[i])]==0)))
        {


            cout << -1 << endl;
            return;
        }else if(v[i]>0){

            visited[v[i]]++;

            

        }else if(v[i]<0){
            visited[abs(v[i])]--;

        }
        prefix_sum[i]=prefix_sum[i-1]+v[i];
        if(prefix_sum[i]==0){
            count_d++;
            visited.clear();
        }

    }
    if(prefix_sum.back()!=0){
        cout<<-1<<endl;
        return;
    }
    cout<<count_d<<endl;
    int len=0;
    for(int i=0;i<prefix_sum.size();i++){
        len++;

        if(prefix_sum[i]==0){
            cout<<len<<" ";
            len=0;
        }

    }
    cout<<endl;
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
    ps(v);

    return 0;
}
