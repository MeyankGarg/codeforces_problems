#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

bool check_condition(vector<vector<int>> &m1, vector<vector<int>> &m2, int i, int j)
{
    // int n=m1.size();
    // int m=m1[0].size();
    // cout << i << " " << j << endl;

    // if (i == 0 && j == 1)
    // {

    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < m; j++)
    //         {
    //             cout << m1[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < m; j++)
    //         {
    //             cout << m2[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    if (i != 0 && (m1[i][j] <= m1[i - 1][j] || m2[i][j] <= m2[i - 1][j]))
    {

        // cout << "1" << endl
        //  << endl;

        return false;
    }

    if (j != 0 && (m1[i][j] <= m1[i][j - 1] || m2[i][j] <= m2[i][j - 1]))
    {
        // cout << "2" << endl
        //  << endl;
        return false;
    }

    if ((i + 1) < m1.size() && (m1[i][j] >= m1[i + 1][j] || m2[i][j] >= m2[i + 1][j]))
    {
        // cout << "3" << endl
        //  << endl;
        return false;
    }

    if ((j + 1) < m1[i].size() && (m1[i][j] >= m1[i][j + 1] || m2[i][j] >= m2[i][j + 1]))
    {
        // cout << "4" << endl
        //      << endl;
        return false;
    }
    return true;
}

bool ps(vector<vector<int>> &m1, vector<vector<int>> &m2)
{
    int n = m1.size();
    int m = m1[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (m1[i][j] > m2[i][j])
            {
                swap(m1[i][j], m2[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(check_condition(m1,m2,i,j)==false){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> m1(n, vector<int>(m));
    vector<vector<int>> m2(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> m1[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cin >> m2[i][j];
        }
    }

    if (ps(m1, m2))
    {
        cout << "Possible" << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }

    return 0;
}
