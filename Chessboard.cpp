#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

int valid_String_Starts_with_one(string &s)
{
    int ans = 0;
    for (int i = 0; i < s.length(); i += 2)
    {
        if (s[i] != '1')
        {
            ans++;
        }
    }
    for (int i = 1; i < s.length(); i += 2)
    {
        if (s[i] != '0')
        {
            ans++;
        }
    }

    return ans;
}

int valid_String_Starts_with_zero(string &s)
{
    int ans = 0;
    for (int i = 0; i < s.length(); i += 2)
    {
        if (s[i] != '0')
        {
            ans++;
        }
    }
    for (int i = 1; i < s.length(); i += 2)
    {
        if (s[i] != '1')
        {
            ans++;
        }
    }

    return ans;
}

pair<int, int> form_pair(vector<string> &b1){
    pair<int,int>p1(make_pair(0,0));
    for(int i=0;i<b1.size();i+=2){
        p1.first+=valid_String_Starts_with_one(b1[i]);
        p1.second+=valid_String_Starts_with_zero(b1[i]);
    }
    for(int i=1;i<b1.size();i+=2){
        p1.first+=valid_String_Starts_with_zero(b1[i]);
        p1.second+=valid_String_Starts_with_one(b1[i]);
    }
    return p1;




}



int ps(vector<string> &b1, vector<string> &b2, vector<string> &b3, vector<string> &b4)
{

    pair<int, int> p1, p2, p3, p4;
    p1=form_pair(b1);
    p2=form_pair(b2);
    p3=form_pair(b3);
    p4=form_pair(b4);
   
    // for(int i=0;i<b1.size();i+=2){
    //     p1.first+=valid_String_Starts_with_one(b1[i]);
    //     p2.first+=valid_String_Starts_with_one(b2[i]);
    //     p3.first+=valid_String_Starts_with_one(b3[i]);
    //     p4.first+=valid_String_Starts_with_one(b4[i]);
    // }
    //  for(int i=1;i<b1.size();i+=2){
    //     p1.second+=valid_String_Starts_with_zero(b1[i]);
    //     p2.second+=valid_String_Starts_with_zero(b2[i]);
    //     p3.second+=valid_String_Starts_with_zero(b3[i]);
    //     p4.second+=valid_String_Starts_with_zero(b4[i]);
    // }


    // cout<<p1.first<<" "<<p1.second<<endl;
    // cout<<p2.first<<" "<<p2.second<<endl;
    // cout<<p3.first<<" "<<p3.second<<endl;
    // cout<<p4.first<<" "<<p4.second<<endl;



    int op1=p1.first+p2.first+p3.second+p4.second;
    int op2=p1.first+p2.second+p3.first+p4.second;
    int op3=p1.first+p2.second+p3.second+p4.first;
    int op4=p1.second+p2.second+p3.first+p4.first;
    int op5=p1.second+p2.first+p3.second+p4.first;
    int op6=p1.second+p2.first+p3.first+p4.second;
    return min(min(op1,op2),min(min(op3,op4),min(op5,op6)));

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> b1(n), b2(n), b3(n), b4(n);
    for (int i = 0; i < n; i++)
    {

        cin >> b1[i];
    }
    for (int i = 0; i < n; i++)
    {

        cin >> b2[i];
    }
    for (int i = 0; i < n; i++)
    {

        cin >> b3[i];
    }
    for (int i = 0; i < n; i++)
    {

        cin >> b4[i];
    }

    cout<<ps(b1,b2,b3,b4)<<endl;



    return 0;
}
