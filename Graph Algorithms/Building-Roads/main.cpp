#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll>  vl;
typedef vector<vl>  vll;

const ll mx = 1e9 + 7;

const int s=2e5+5;
int n,q;

vl p(s),r(s);

int parent(int a){
    if(p[a]!=a){
        p[a]=parent(p[a]);
    }
    return p[a];
}

void join(ll a, ll b){
    auto pa=parent(a);
    auto pb=parent(b);

    if(r[pa]>r[pb]){
        p[pb]=pa;
    }else if(r[pb]>r[pa]){
        p[pa]=pb;
    }else{
        r[pa]++;
        p[pb]=pa;
    }
}



void solve() {
    ll n,m;
    cin>>n>>m;

    for(int i=0;i<s;i++)p[i]=i;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(parent(a)!=parent(b))join(a,b);
    }

    int k=0;
    vll ans;
    for(int i=2;i<=n;i++){
        if(parent(1)!=parent(i)){
            join(1,i);
            ans.push_back({1,i});
            k++;
        }
    }

    cout<<k<<endl;
    for(auto x: ans)printf("%lld %lld\n",x[0],x[1]);
}

// --------------------------------
// shows WA for half the TC
// --------------------------------
int main() {
    FASTIO
    solve();

//    int t;
//    cin>>t;
//    while(t--)solve();

    return 0;
}