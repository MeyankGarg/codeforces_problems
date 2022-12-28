#include <bits/stdc++.h>            
using namespace std;

#define ll long long int           
#define pii pair<int,int>    
#define pb push_back      
int mod = 1e9 + 7;


void update_seg_tree(vector<bool>& seg_tree, vector<int>& cor, int node, int val, int i, int j, int index) {
    // base case
    if (i == j) {
        cor[i] += val;
        seg_tree[node] = (cor[i] > 0);
        // cout<<i<<" -> "<<node<<" -> "<<seg_tree[node]<<endl;
        return;
    }

    // recursive case
    int mid = (i + j) / 2;
    if (index <= mid) {
        update_seg_tree(seg_tree, cor, 2 * node, val, i, mid, index);
    }
    else {
        update_seg_tree(seg_tree, cor, 2 * node + 1, val, mid + 1, j, index);
    }
    seg_tree[node] = seg_tree[2 * node] & seg_tree[2 * node + 1];


}

int return_querry(vector<bool>& seg_tree, vector<int>& cor, int i, int j, int s, int e, int index) {
    // i,j -> querry
    // s,e -> cor
    // excludsive
    if (e < i || j < s) {
        return 1;
    }
    // totally inclusive
    if (s>=i && e<=j) {
        return seg_tree[index];
    }

    //    partially

    int mid = (s + e) / 2;
    bool x1 = return_querry(seg_tree, cor, i, j, s, mid, 2 * index);
    bool x2 = return_querry(seg_tree, cor, i, j, mid + 1, e, 2 * index + 1);
    // cout<<i<<" "<<j<<" "<<s<<" "<<e<<" "<<index<<" -> "<<x1<<" "<<x2<<endl;
    return  x1 & x2;




}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int q;
    cin >> q;
    // multiset<int>x_cor,y_cor;
    vector<int>x_cor(n + 2, 0), y_cor(n + 2, 0);
    vector<bool>seg_tree_x(4 * n, false);
    vector<bool>seg_tree_y(4 * n, false);



    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;

            // x_cor[x]++;
            // y_cor[y]++;
            update_seg_tree(seg_tree_x, x_cor, 1, 1, 1, n, x);
            update_seg_tree(seg_tree_y, y_cor, 1, 1, 1, n, y);


        }
        else if (t == 2) {
            int x, y;
            cin >> x >> y;

            // x_cor[x]--;
            // y_cor[y]--;
            update_seg_tree(seg_tree_x, x_cor, 1, -1, 1, n, x);
            update_seg_tree(seg_tree_y, y_cor, 1, -1, 1, n, y);

        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            // for (int i = x1;i <= x2;i++) {
            //     cout << x_cor[i] << " ";
            // }
            // cout << endl;

            // for (int i = y1;i <= y2;i++) {
            //     cout << y_cor[i] << " ";
            // }
            // cout << endl;

            if (return_querry(seg_tree_x, x_cor, x1, x2, 1, n, 1) || return_querry(seg_tree_y, y_cor, y1, y2, 1, n, 1)) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }







        }
    }



    return 0;
}
