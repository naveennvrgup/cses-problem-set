#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(NULL);
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;
 
const ll mx = 1e9 + 7;
 
int n,q;
vector<int> callstk;
vector<vector<int>> ances, adj;
 
 
void dfs(int node){
    int n=callstk.size();
    for(int i=1;i<=n;i*=2){
        ances[node].push_back(callstk[n-i]);
    }
    callstk.push_back(node);
    for(auto child: adj[node]){
        dfs(child);
    }
    callstk.pop_back();
}
 
int find(int node, int k){
    if(k==0)return node;
    int i=log2(k);
    if(i>=ances[node].size())return -1;
    return find(ances[node][i],k-(1<<i));
}
 
void solve() {
    cin>>n>>q;
    adj.assign(n+1,vector<int>());
    ances.assign(n+1,vector<int>());
 
    for(int i=2;i<=n;i++){
        int temp;
        cin>>temp;
 
        adj[temp].push_back(i);
    };
 
 
    dfs(1);
 
    for(int i=0;i<q;i++){
        int a, b;
        cin>>a>>b;
        cout<<find(a,b)<<endl;
    }
 
}
 
int main() {
    // FASTIO
    solve();
 
//    int t;
//    cin>>t;
//    while(t--)solve();
 
    return 0;
}