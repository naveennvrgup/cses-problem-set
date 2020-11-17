#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;

const ll mx = 1e9 + 7;


void solve(){
    ll n;
    cin>>n;

    ll pos=n*(n+1)/2;
    if(pos%2){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    pos/=2;

    vector<ll> a,b;
    for(int i=n;i>=1;i--){
        if(pos-i>=0){
            b.push_back(i);
            pos-=i;
        }else a.push_back(i);
    }

    cout<<a.size()<<endl;
    for(auto x: a)cout<<x<<" ";
    cout<<endl<<b.size()<<endl;
    for(auto x:b)cout<<x<<" ";
    cout<<endl;
}




int main() {
    FASTIO
    solve();

//    int t;
//    cin>>t;
//    while(t--)solve();

    return 0;
}
