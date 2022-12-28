#include <bits/stdc++.h>            
using namespace std;

#define ll long long int           
#define pii pair<int,int>    
#define pb push_back      
#define pci pair<int,char>
int mod = 1e9 + 7;

bool check_if_we_can_assign(priority_queue<pci> odd_count, priority_queue<pci>even_count, int k, int val) {
    // cout<<k<<" "<<odd_count.size()<<" "<<even_count.size()<<endl;;
    while (k > 0 && (even_count.size() > 0 || odd_count.size()>0)) {

        k--;

        int temp_val = val;

        if (temp_val % 2 && odd_count.size()>0 ) {

            int odd_ele = odd_count.top().first;
            if (temp_val >= odd_ele) {
                temp_val -= odd_ele;
                odd_count.pop();
            }
            else {

                odd_count.pop();

                odd_count.push({ odd_ele - temp_val,'a' });



                temp_val = 0;
                // continue;

            }




        }

        while (even_count.size() > 0 && temp_val > 0) {

            int even_ele = even_count.top().first;


            if (temp_val >= even_ele) {
                temp_val -= even_ele;
                even_count.pop();
            }
            else {
                even_count.pop();
                // if ((even_ele - temp_val) % 2 == 0) {
                    even_count.push({ even_ele - temp_val,'a' });

                // }
                // else {
                //     odd_count.push({ even_ele - temp_val,'a' });

                // }

                temp_val = 0;
            }

        }

        while (odd_count.size() > 0 && temp_val > 0) {

            int odd_ele = odd_count.top().first;
            if(odd_ele==1){
                return false;
            }
            if (temp_val >= odd_ele) {
                temp_val -= (odd_ele-1);
                odd_count.push({1,'a'});
                odd_count.pop();
            }
            else {

                odd_count.pop();

                // if((odd_ele - temp_val)%2){

                odd_count.push({ odd_ele - temp_val,'a' });
                // }else{
                //     odd_count.push({ odd_ele - temp_val,'a' });

                // }




                temp_val = 0;


            }

        }
        // cout<<k<<" "<<temp_val<<" "<<endl;

        if(temp_val>0){
            return false;
        }






    }
    if(k>0){
        return false;
    }else{
        return true;
    }

}


int ps(string& str, int k) {

    unordered_map<char, int>h;
    for (int i = 0;i < str.length();i++) {
        h[str[i]]++;
    }

    priority_queue<pci>odd_count, even_count;
    for (auto itr : h) {
        if (itr.second % 2) {
            odd_count.push({ itr.second,itr.first });
        }
        else {
            even_count.push({ itr.second,itr.first });

        }
    }

   
    int s=1;
    int e=(str.length()/k) + 1;
    // cout<<s<<" "<<e<<endl;
    int ans=1;

    while(s<=e){
        int mid=(s+e)/2;
        // bool x=false;
        bool x=check_if_we_can_assign(odd_count,even_count,k,mid);
        // cout<<s<<" "<<e<<" "<<mid<<" "<<x<<endl;
        if(x==true){
            ans=mid;
            s=mid+1;

        }else{
            e=mid-1;
        }

    }

    return ans;




}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout<<ps(s,k)<<endl;;
    }



    return 0;
}
