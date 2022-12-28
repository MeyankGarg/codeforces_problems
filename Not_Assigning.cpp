#include <bits/stdc++.h>            
using namespace std;

#define ll long long int           
#define pii pair<int,int>    
#define pb push_back      
int mod = 1e9 + 7;



bool ps(unordered_map<int, vector<vector<int>>>& h, int color, int src, vector<bool>& visited) {
    // base case

    if (h[src].size() > 2) {
        return false;
    }

    // recursive case


    visited[src]=true;
    // h[src][0][1]=color;
    // h[src][1][1]=color^1;
    // cout<<src<<" -> ";
    // for(auto itr:h[src]){
    //     cout<<itr[0]<<" ";
    // }
    // cout<<endl;
    if (visited[h[src][0][0]] == false) {

        h[src][0][1] = color^1;
        
        
        // visited[h[src][0][0]] = true;

        bool x = ps(h, color^1, h[src][0][0], visited);
        if (x == false) {
            return false;
        }



    }else{
        h[src][0][1] = color;
        color=color^1;

    }
    // color=color^1;

    if (h[src].size()>1 && visited[h[src][1][0]] == false) {
        h[src][1][1] = color;
        // visited[h[src][1][0]] = true;

        bool x = ps(h, color, h[src][1][0], visited);
        if (x == false) {
            return false;
        }



    }else if(h[src].size()>1){
        h[src][1][1] = color;


    }

    return true;



}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, vector<vector<int>>>h;
        vector<vector<int>>ans;
        for (int i = 1;i < n;i++) {
            int u, v;
            cin >> u >> v;
            ans.pb({u,v});
            h[u].pb({ v,0 });
            h[v].pb({ u,0 });
        }

        vector<bool>visited(n+3,false);

        bool x=ps(h,1,1,visited);
        if(x==false){
            cout<<-1<<endl;
        }else{

            // for(auto itr:h){
            //     cout<<itr.first<<" -> ";
            //     for(auto child:itr.second){
            //         cout<<"( "<<child[0]<<" "<<child[1]<<" ) ";
            //     }
            //     cout<<endl;
            // }



            vector<int>color(2,2);
            color[1]=5;

            for(auto itr:ans){
                int u=itr[0];
                int v=itr[1];
                // cout<<u<<" "<<v<<" ";

                if(h[u][0][0]==v){
                    cout<<color[h[u][0][1]]<<" ";
                   
                }else{
                    cout<<color[h[u][1][1]]<<" ";

                }
            }
            cout<<endl;

          
        }

    }


    return 0;
}
