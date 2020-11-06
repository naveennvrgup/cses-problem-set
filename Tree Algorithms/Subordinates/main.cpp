#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(NULL);
 
typedef long long ll;
typedef pair<ll, ll> pll;
 
const ll mx = 1e9 + 7;
 
 
 
int dfs(int root, vector<vector<int>> &adj, vector<int> &sub){
    for(auto x: adj[root]){
        sub[root]+=dfs(x,adj,sub);
    }
    return sub[root]+1;
}
 
 
void solve() {
    int n;
    cin>>n;
 
    vector<vector<int>> adj(n+1);
    vector<int> sub(n+1);
 
    for(int i=2;i<=n;i++){
        int temp;
        cin>>temp;
        adj[temp].push_back(i);
    }
 
    dfs(1,adj,sub);
 
    for(int i=1;i<=n;i++)cout<<sub[i]<<" ";
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