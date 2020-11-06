#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(NULL);
 
typedef long long ll;
typedef pair<ll, ll> pll;
 
const ll mx = 1e9 + 7;
 
 
void solve() {
    ll n,q;
    cin>>n>>q;
 
    vector<ll> fen(n);
    for(int i=0;i<n;i++){
        ll temp;
        cin>>temp;
        for(int j=i;j<n;j=j|(j+1)) fen[j]+=temp;
    }
 
    for(int i=0;i<q;i++){
        ll l,r;
        cin>>l>>r;
 
        ll res=0;
        for(int j=r-1;j>=0;j=(j&(j+1))-1)res+=fen[j];
        for(int j=l-2;j>=0;j=(j&(j+1))-1)res-=fen[j];
 
        cout<<res<<endl;
    }
}
 
int main() {
    // FASTIO
    solve();
 
//    int t;
//    cin>>t;
//    while(t--)solve();
 
    return 0;
}