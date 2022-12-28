#include <bits/stdc++.h>
using namespace std;

#define int long long int
int mod = 1e9 + 7;

void dfs(int src, map<int, vector<int>> h, vector<int> &path, queue<int> &q)
{

    path.push_back(src);
    vector<int> temp = h[src];
    if (temp.size() == 0)
    {
        return;
    }

    for (int i = 1; i < temp.size(); i++)
    {
        q.push(temp[i]);
    }

    dfs(temp[0], h, path, q);
}

void ps(vector<int> &v)
{

    map<int, vector<int>> h;
    int root;
    // graph creation
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == (i + 1))
        {
            root = i + 1;
        }
        else
        {
            h[v[i]].push_back(i + 1);
        }
    }

    vector<vector<int>> ans;
    //   dfs trivarsal

    // 3 has childs 1 4 6 7 then we will choose any one child for path and rest we will push to q as root element for new path
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        vector<int>path;
        int x=q.front();
        q.pop();
        dfs(x,h,path,q);
        ans.push_back(path);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].size()<<endl;
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;

    }

    cout<<endl;
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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ps(v);
    }

    return 0;
}
