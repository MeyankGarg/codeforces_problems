#include <bits/stdc++.h>            
using namespace std;

#define ll long long int           
#define pii pair<int,int>    
#define pb push_back      
int mod = 1e9 + 7;

void updation(vector<ll>&seg_tree,vector<ll>&v,int s,int e,int node,int index){
    // base case
    if(s==e){
        v[s]++;
        seg_tree[node]=v[s];
        return;
    }

    // recursive case
    int mid=(s+e)/2;
    if(index<=mid){
        updation(seg_tree,v,s,mid,2*node,index);
    }else{
        updation(seg_tree,v,mid+1,e,2*node+1,index);
    }
    seg_tree[node]=seg_tree[2*node]+seg_tree[2*node+1];



}

int return_intersection(vector<ll>&seg_tree,vector<ll>&v,int s,int e,int node,int i,int j){
    // out of bounds
    if(i>e || j<s){
        return 0;
    }

    // toally overlap

    if(s>=i && e<=j){
        return seg_tree[node];
    }
    // partial overlap

    int mid=(s+e)/2;
    return return_intersection(seg_tree,v,s,mid,2*node,i,j)+return_intersection(seg_tree,v,mid+1,e,2*node+1,i,j);
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<ll>nodes(n+2,0);
        vector<ll>seg_tree(4*n,0);
        ll ans=0;
        for(int i=0;i<n;i++){
            
            ll x=return_intersection(seg_tree,nodes,1,n,1,v[i],n);
            updation(seg_tree,nodes,1,n,1,v[i]);
            // for(int i=1;i<=n;i++){
            //     cout<<nodes[i]<<" ";
            // }
            // cout<<endl;
            // cout<<x<<endl<<endl;
            ans+=x;

        }
        cout<<ans<<endl;

    }



    return 0;
}
