#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int mod = 1e9 + 7;

ll find_distace(ll ax,ll ay,ll bx,ll by){
    ll x=(ax-bx)*(ax-bx) + (ay-by)*(ay-by);

    return x;

}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    ll d1=find_distace(ax,ay,bx,by);
    ll d2=find_distace(bx,by,cx,cy);
    ll d3=find_distace(ax,ay,cx,cy);

    cout<<d1<<" "<<d2<<" "<<d3<<endl;

    long double x1=sqrtl(d1);
    long double x2=sqrtl(d3);

    ll temp=x1*x1;
    cout<<temp<<endl;;
    if(temp==d1){
        cout<<"Adf";
    }
   

    if((ll)x1*x1 != d1){

        x1+=1;
    }
    if(x2*x2!=d3){
        x2+=1;
    }

    cout<<x1<<" "<<x2<<endl;
    
    
    if(d1==d2 && (2*x1)>x2){
        cout<<"YES"<<endl;
    } else{
        cout<<"NO"<<endl;
    }

    return 0;
}
