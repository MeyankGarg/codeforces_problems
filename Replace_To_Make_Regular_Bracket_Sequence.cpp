#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

int ps(string &s){
    stack<char>stk;
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{'||s[i]=='['||s[i]=='<'||s[i]=='('){

            stk.push(s[i]);

        }else{

            if( !stk.empty()  &&((s[i]=='}' && stk.top()=='{')||(s[i]==']'&& stk.top()=='[')||(s[i]=='>'&&stk.top()=='<')||(s[i]==')' && stk.top()=='('))){

                stk.pop();

            }else if(stk.empty()==true){
                // cout<<i<<" "<<endl;
                return -1;
            }else{
                // cout<<i<<" "<<s[i]<<" "<<stk.top()<<endl;
                ans++;
                stk.pop();
            }

        }
    }
    if(stk.empty()){
        return ans;

    }else{
        return -1;
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    // cout<<ps(s)<<endl;

    int x=ps(s);
    if(x==-1){
        cout<<"Impossible"<<endl;
    }else{
        cout<<x<<endl;
    }


    return 0;
}
