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

vl color(s);
vll adj(s);

bool bfs(int root){
    queue<ll> q;
    q.push(root);
    color[root]=1;

    while(!q.empty()){
        auto curr=q.front();
        q.pop();

        for(auto child: adj[curr]){
            if(color[child]){
                if(color[child]==color[curr]){
                    return false;
                }
            }else{
                q.push(child);
                color[child]=3-color[curr];
            }
        }
    }
    return true;
}

void solve() {
    ll n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!color[i]){
            if(!bfs(i)){
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }



    for(int i=1;i<=n;i++)cout<<color[i]<<" ";
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