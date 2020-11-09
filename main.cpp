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

const int s=2e5+5;

ll n,m;
vlll adj(s);
vl dis(s),vis(s);
priority_queue<vl,vll,greater<vl>> pq;

void solve(){
    cin>>n>>m;

    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    pq.push({0,1});
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        ll node=curr[1];
        ll cdis=curr[0];

        if(vis[node])continue;
        vis[node]=1;
        dis[node]=cdis;

        for(auto child: adj[node]){
            if(vis[child[0]])continue;
            pq.push({cdis+child[1],child[0]});
        }
    }

    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
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