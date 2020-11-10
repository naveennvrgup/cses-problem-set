#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll>  vl;
typedef vector<vl>  vll;
typedef vector<vll>  vlll;
typedef vector<char> vc;
typedef vector<vc> vcc;
const ll mx = 1e9 + 7;
const ll inf=1e18;

const int s=2e5+5;
vl from1(s),ton(s),vis(s);
vlll adj(s),adj2(s);
vll edges;
ll n,m;
priority_queue<vl,vll,greater<vl>> pq;

void solve(){
    cin>>n>>m;

    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj2[b].push_back({a,c});
        edges.push_back({a,b,c});
    }

    pq.push({0,1});
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        auto x=curr[1];
        auto l=curr[0];

        if(vis[x])continue;
        vis[x]=1;
        from1[x]=l;

        for(auto child: adj[x]){
            if(vis[child[0]])continue;
            pq.push({child[1]+l,child[0]});
        }
    }

    vis.assign(s,0);
    pq.push({0,n});
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        auto x=curr[1];
        auto l=curr[0];

        if(vis[x])continue;
        vis[x]=1;
        ton[x]=l;

        for(auto child: adj2[x]){
            if(vis[child[0]])continue;
            pq.push({child[1]+l,child[0]});
        }
    }

    ll ans=inf;
    for(auto x:edges){
        ans=min(ans,from1[x[0]]+x[2]/2+ton[x[1]]);
        // printf("%lld,%lld => %lld+%lld+%lld = %lld\n",x[0],x[1],from1[x[0]],x[2]/2,ton[x[1]],from1[x[0]]+x[2]/2+ton[x[1]]);
    }

    cout<<ans<<endl;
}


int main() {
    FASTIO
    solve();
 
//    int t;
//    cin>>t;
//    while(t--)solve();
 
    return 0;
}