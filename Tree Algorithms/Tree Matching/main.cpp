#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(NULL);
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;
 
const ll mx = 1e9 + 7;
 
void dfs(int i, int p, vector<vector<int>> &adj, vector<vector<int>> &dp){
    static int count=0;
    // cout<<++count<<" "<<i<<endl;
    int son=0;
    for(auto child: adj[i]){
        if(child==p)continue;
        dfs(child,i,adj,dp);
        dp[i][0]+=max(dp[child][0],dp[child][1]);
    }
 
    for(auto child: adj[i]){
        if(child==p)continue;
        dp[i][1]=max(dp[i][1],dp[i][0]+1+dp[child][0]-max(dp[child][0],dp[child][1]));
    }
}
 
void solve() {
    int n;
    cin>>n;
 
    vector<vector<int>> adj(n+1),dp(n+1,vector<int>(2,0));
 
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    int root=1;
    dfs(root, 0, adj,dp);
 
    cout<<max(dp[root][0],dp[root][1])<<endl;
}
 
int main() {
    // FASTIO
    solve();
 
//    int t;
//    cin>>t;
//    while(t--)solve();
 
    return 0;
}