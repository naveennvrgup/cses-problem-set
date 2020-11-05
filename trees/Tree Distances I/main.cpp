#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(NULL);
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;
 
const ll mx = 1e9 + 7;
 
int n;
vector<vector<int>> adj;
vector<int> depth, ans;
 
void dfs(int node, int parent){
    for(auto child: adj[node]){
        if(child==parent)continue;
        dfs(child,node);
        depth[node]=max(depth[node], 1+depth[child]);
    }
}
 
void util(int node, int parent, int par_ans){
    auto children=adj[node];
    int clen=children.size();
 
    vector<int> suffix(clen,-1),prefix(clen,-1);
 
    for(int i=0;i<clen;i++){
        if(children[i]==parent)continue;
        suffix[i]=depth[children[i]];
        prefix[i]=depth[children[i]];
    }
 
    for(int i=1;i<clen;i++)prefix[i]=max(prefix[i],prefix[i-1]);
    for(int i=clen-2;i>=0;i--)suffix[i]=max(suffix[i],suffix[i+1]);
 
    for(int i=0;i<clen;i++){
        if(children[i]==parent)continue;
 
        int c_ans=max(par_ans,i==0?-1:prefix[i-1]);
        c_ans=max(c_ans, i==clen-1?-1:suffix[i+1]);
        
        util(children[i],node,c_ans+1);
    }    
 
    ans[node]=1+max(par_ans, prefix.empty()?-1:prefix.back());
}
 
 
void solve() {
    cin>>n;
    adj.assign(n+1,vector<int>());
    depth.assign(n+1,0);
    ans.assign(n+1,0);
 
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs(1,0);
    util(1,0,-1);
 
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}
 
int main() {
    // FASTIO
    solve();
 
//    int t;
//    cin>>t;
//    while(t--)solve();
 
    return 0;
}