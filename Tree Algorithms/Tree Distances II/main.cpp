#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(NULL);
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;
 
const ll mx = 1e9 + 7;
 
int n;
vector<vector<ll>> adj;
vector<ll> pans,pn,ans;
 
void subsum(ll node, ll parent){
    for(auto child: adj[node]){
        if(child==parent)continue;
        subsum(child,node);
        pans[node]+=pans[child]+pn[child];
        pn[node]+=pn[child];
    }
    pn[node]++;
}
 
void sum(ll node, ll parent, ll par_sum, ll par_n){
    auto kids=adj[node];
    auto klen=kids.size();
    
    vector<ll> prefix_sum(klen),suffix_sum(klen),prefix_n(klen), suffix_n(klen);
    for(int i=0;i<klen;i++){
        if(kids[i]==parent)continue;
        prefix_sum[i]=pans[kids[i]];
        suffix_sum[i]=pans[kids[i]];
 
        prefix_n[i]=pn[kids[i]];
        suffix_n[i]=pn[kids[i]];
    }
 
    for(int i=1;i<klen;i++){
        prefix_sum[i]+=prefix_sum[i-1];
        prefix_n[i]+=prefix_n[i-1];
    }
    for(int i=klen-2;i>=0;i--){
        suffix_sum[i]+=suffix_sum[i+1];
        suffix_n[i]+=suffix_n[i+1];
    }
 
    for(int i=0;i<klen;i++){
        if(kids[i]==parent)continue;
 
        ll kid_sum=par_sum;
        kid_sum+=i==0?0:prefix_sum[i-1];
        kid_sum+=i==klen-1?0:suffix_sum[i+1];
 
        ll kid_n=par_n;
        kid_n+=i==0?0:prefix_n[i-1];
        kid_n+=i==klen-1?0:suffix_n[i+1];
 
        sum(kids[i],node, kid_sum + kid_n, kid_n+1);
    }
    ans[node]=par_sum+par_n;
    if(klen){
        ans[node]+=prefix_n.back()+prefix_sum.back();
    }
}
 
void solve() {
    cin>>n;
 
    adj.assign(n+1,vector<ll>());
    pans.assign(n+1,0);
    pn.assign(n+1,0);
    ans.assign(n+1,0);
    
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    subsum(1,0);
    sum(1,0,0,0);
 
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