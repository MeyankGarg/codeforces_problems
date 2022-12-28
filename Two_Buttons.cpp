#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

int ps(int n, int target,vector<int>&visited)
{
    if (n <= 0)
    {
        return 1e9 + 7;
    }

    if (n >= target)
    {
        return n - target;
    }
    if(visited[n]==-1){
        return 1e9+7;
    }else if(visited[n]!=-2){
        return visited[n];
    }

    // recursive case
    visited[n]=-1;
    int op1 = ps(2 * n, target,visited);
    int op2 = ps(n - 1, target,visited);
    return visited[n]= min(op1, op2) + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // cout<<n<<" "<<m<<endl;
    vector<int>v(2*m,-2);
    cout << ps(n, m,v) << endl;

    return 0;
}
