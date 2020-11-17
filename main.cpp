#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;

const ll mx = 1e9 + 7;

ll n;

ll util(ll n){
    ll n2=n*n,nm4=n-4;
    ll res=n2*(n2-1)/2;

    if(n==1)return 0;
    if(n==2)return 6;
    if(n==3)return 28;

    res-=(nm4+2)*(nm4)*4;
    res-=4+nm4*2;
    res-=(nm4+2)*10;

    return res;
}

void solve(){
    cin>>n;

    for(int i=1;i<=n;i++)cout<<util(i)<<endl;

}




int main() {
    FASTIO
    solve();

//    int t;
//    cin>>t;
//    while(t--)solve();

    return 0;
}
