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

vl ans;
vll adj(s);
map<int,int> mem;

bool dfs(int node){
    if(mem.count(node)){
        if(ans.size()-mem[node]>=3){
            vl temp;
            for(int i=mem[node];i<ans.size();i++)temp.push_back(ans[i]);
            ans=temp;
            ans.push_back(node);
            return true;
        }
        return false;
    }
    mem[node]=ans.size();
    ans.push_back(node);

    for(auto child: adj[node]){
        if(dfs(child))return true;
    }
    ans.pop_back();
    return false;
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
        if(!mem.count(i)){
            if(dfs(i)){
                cout<<ans.size()<<endl;
                for(auto x: ans)cout<<x<<" ";
                cout<<endl;
                return;
            }
        }
    }

    cout<<"IMPOSSIBLE"<<endl;
}


int main() {
    FASTIO
    solve();

//    int t;
//    cin>>t;
//    while(t--)solve();

    return 0;
}