#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

// string int_to_str(int n)
// {
//     if (n == 0)
//     {
//         return;
//     }
//     int temp = abs(n);
//     string ans = ;
//     while (temp > 0)
//     {
//         int dig = temp % 10;
//         temp = temp / 10;
//         char ch = dig + '0';
//         ans = ch + ans;
//     }
//     if (n < 0)
//     {
//         ans = +ans;
//     }
//     return ans;
// }

// int str_to_int(string s)
// {
//     bool negative = false;
//     if (s[0] == '-')
//     {
//         s = s.substr(1);
//         negative = true;
//     }
//     int ans = 0;
//     while (s.length() > 0)
//     {
//         char ch = s[0];
//         s = s.substr(1);
//         int dig = ch - '0';
//         ans = ans * 10 + dig;
//     }
//     if (negative)
//     {
//         ans = ans * (-1);
//     }
//     return ans;
// }

void multiply_str(string &s, int val)
{

    int carry = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        int dig = s[i] - '0';
        dig = dig * val + carry;
        carry = dig / 10;
        dig = dig % 10;
        s[i] = dig + '0';
    }
    if (carry > 0)
    {
        string temp = to_string(carry);
        s = temp + s;
    }
}

string ps(string &s)
{
    vector<int> v(27, -1);
    string ans = "1";
    int count_temp = 10;
    string last_zeros="";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '?')
        {
            if (i == 0)
            {
                // ans*=9;
                multiply_str(ans, 9);
            }
            else
            {
                // ans*=10;
                // multiply_str(ans, 10);
                last_zeros+='0';

            }
        }
        else if (isupper(s[i]))
        {

            if (v[s[i] - 'A'] != -1)
            {
                continue;
            }

            if (i == 0)
            {
                // ans*=9;
                multiply_str(ans, 9);
                count_temp--;
            }
            else
            {
                // ans*=count_temp;
                multiply_str(ans, count_temp);
                count_temp--;
            }
            v[s[i] - 'A'] = 1;
        }
    }
    return ans+last_zeros;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    cout << ps(s) << endl;

    return 0;
}
