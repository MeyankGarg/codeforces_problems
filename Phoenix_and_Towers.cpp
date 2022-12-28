#include <bits/stdc++.h>

#include <iostream>
#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define py cout << 'Y'<<'E'<<'S'<<endl;
#define pn cout << 'N'<<'O'<<endl;
#define pii pair<ll,ll>
#define pdd pair<lld,lld>
#define vr(v) v.begin(), v.end()
#define Meyank ios_base::sync_with_stdio(false);
#define Garg cin.tie(NULL);
#define huehue cout.tie(NULL);
#define modulo 1e9+7
using namespace std;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
bool sorta(const pair<int, int>& a, const pair<int, int>& b) { return (a.second < b.second); }
bool sortd(const pair<int, int>& a, const pair<int, int>& b) { return (a.second > b.second); }
string decToBinary(int n) {
    string s = "";
    int i = 0;
    while (n > 0) {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
ll binaryToDecimal(string n) {
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1') dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
bool isPowerOfTwo(int n) {
    if (n == 0) return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x) {
    if (x >= 0) {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
ll moduloMultiplication(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        b >>= 1;
    }
    return res;
}
ll powermod(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void ps(vector<int>& v, int m, int x) {
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    for (int i = 1;i <= m;i++) {
        pq.push({ 0,i });
    }
    vector<pii>temp;
    for (int i = 0;i < v.size();i++) {
        temp.pb({ v[i],i });
    }
    sort(vr(temp));
    // for (auto itr : temp) {
    //     cout << itr.first << " " << itr.second << endl;;
    // }
    // cout << endl;
    for (int i = 0;i < v.size();i++) {
        pii p = pq.top();
        pq.pop();
        // cout << "before\n";
        // cout<<temp[i].first<<" -> "<<temp[i].second<<endl;
        // cout << p.first << " " << p.second << " " << v[temp[i].second] << endl;

        v[temp[i].second] = p.second;


        p.first += temp[i].first;

        pq.push({ p.first,p.second });
        // cout << "after\n";

        // cout << p.first << " " << p.second << " " << v[temp[i].second] << endl;
        // cout << endl;

    }
    int ele = pq.top().first;
    int ele2 = ele;
    while (pq.size() > 0) {
        ele2 = pq.top().first;
        // cout<<ele2<<" -> ";
        pq.pop();

    }
    // cout<<endl;

    if(abs(ele2-ele) > x){
        pn;
        return;
    }

    py;
    for (auto itr : v) {
        cout << itr << " ";
    }
    cout << endl;

}

int main() {
    Meyank Garg huehue;
    ll t;
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;
        vector<int>v(n);
        for (int i = 0;i < n;i++) {
            cin >> v[i];
        }
        ps(v, m, x);



    }
    return 0;
}