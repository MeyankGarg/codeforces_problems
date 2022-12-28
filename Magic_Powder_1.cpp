#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

bool cookie_possible(vector<int> &ingredients_needed, vector<int> &ingredients_available, int k, int val)
{
    int n = ingredients_needed.size();

    for (int i = 0; i < n; i++)
    {

        int temp = ingredients_available[i] - ingredients_needed[i] * val;
        if (temp < 0)
        {
            k += temp;
        }
        if (k < 0)
        {
            return false;
        }
    }

    return true;
}

int ps(vector<int> &ingredients_needed, vector<int> &ingredients_available, int k)
{
    int ans=0;
    int min_cookie = 0;
    int max_cookie = 1000+k;
    while(min_cookie<=max_cookie){
        int mid=(min_cookie+max_cookie)/2;
        if(cookie_possible(ingredients_needed,ingredients_available,k,mid)){
            ans=mid;
            min_cookie=mid+1;
        }else{
            max_cookie=mid-1;
        }
    }
    return ans;
}

int main()

{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> ingredients_needed(n), ingredients_available(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ingredients_needed[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> ingredients_available[i];
    }
    cout<<ps(ingredients_needed,ingredients_available,k)<<endl;

    return 0;
}
