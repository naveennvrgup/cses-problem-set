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

vl vis(s), p(s), lvl(s,s);
vll adj(s);


void solve() {
    ll n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<ll> q;
    q.push(1);
    p[1]=0;
    lvl[1]=1;

    while(!q.empty()){
        auto curr=q.front();
        q.pop();

        if(vis[curr])continue;
        vis[curr]=1;

        for(auto child: adj[curr]){
            if(vis[child])continue;
            if(lvl[child]<=lvl[curr]+1)continue;
            lvl[child]=lvl[curr]+1;
            p[child]=curr;
            q.push(child);
        }
    }

    if(lvl[n]==s){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    cout<<lvl[n]<<endl;
    vl ans;
    int node=n;
    while(node!=0){
        ans.push_back(node);
        node=p[node];
    }

    for(auto itr=ans.rbegin();itr!=ans.rend();itr++)cout<<*itr<<" ";
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