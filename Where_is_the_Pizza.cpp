#include <bits/stdc++.h>            
using namespace std;

#define ll long long int           
#define pii pair<int,int>    
#define pb push_back      
int mod = 1e9 + 7;

// return if any node is their which is present in v3

bool if_any_visited_node(int src,unordered_map<int,int>&h,vector<int>&visited){
   
    visited[src]=2;
    // if(visited[h[src]]!=2){
    //     bool x= if_any_visited_node(h[src],h,visited);

    // }
    
    if(visited[h[src]]==1){
        if_any_visited_node(h[src],h,visited);

       
        return true;
    }else if(visited[h[src]]==0) {

        return  if_any_visited_node(h[src],h,visited);

    }
    return false;


}


ll ps(vector<int>&v1,vector<int>&v2,vector<int>&v3){
    int n=v1.size();
    unordered_map<int,int>h;
    // unordered_map<int,bool>visited;
    vector<int>visited(n+3,0);
    for(int i=0;i<n;i++){
        h[v1[i]]=v2[i];
        if(v3[i]!=0){
            visited[v3[i]]=true;
        }
    }
    // 0-> unvisited
    // 1->visited in v3
    // 2->represent visted during trivarsal
    ll ans=1;
    for(int i=1;i<=n;i++){
        if(visited[i]==0 && h[i]!=i){
            bool x=if_any_visited_node(i,h,visited);
            if(x==false){
                ans*=2;
                ans=ans%mod;
            }
        }
    }

    return ans;


    

   

}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v1(n);
        for(int i=0;i<n;i++){
            cin>>v1[i];
        }
         vector<int>v2(n);
        for(int i=0;i<n;i++){
            cin>>v2[i];
        }
         vector<int>v3(n);
        for(int i=0;i<n;i++){
            cin>>v3[i];
        }

        cout<<ps(v1,v2,v3)<<endl;;
        

    }


    return 0;
}
