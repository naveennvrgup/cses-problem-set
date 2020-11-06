#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(NULL);
 
typedef long long ll;
typedef pair<ll, ll> pll;
 
const ll mx = 1e9 + 7;
 
int node,mheight;
 
void dfs(int root, int parent,int height, vector<vector<int>> &adj){
    if(height>mheight){
        mheight=height;
        node=root;
    }
 
    for(auto child: adj[root]){
        if(child!=parent)dfs(child,root,height+1,adj);
    }
}
 
void solve() {
    int n;
    cin>>n;
 
    vector<vector<int>> adj(n+1);
 
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    mheight=0;
    dfs(1,0,1,adj);
    mheight=0;
    dfs(node,0,0,adj);
    cout<<mheight<<endl;
}
 
int main() {
    // FASTIO
    solve();
 
//    int t;
//    cin>>t;
//    while(t--)solve();
 
    return 0;
}