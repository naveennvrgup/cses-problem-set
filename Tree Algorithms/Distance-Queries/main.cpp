#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;

const ll mx = 1e9 + 7;

int n,q;
vector<int> callstk,depth;
vector<vector<int>> ances, adj;

void build(int node, int parent, int lvl){
    int cn=callstk.size();
    depth[node]=lvl;
    
    for(int i=1;i<=cn;i*=2){
        ances[node].push_back(callstk[cn-i]);
    }

    callstk.push_back(node);
    for(auto child: adj[node]){
        if(child==parent)continue;
        build(child,node,lvl+1);
    }
    callstk.pop_back();
}

int find_k_ances(int a, int k){
    while(k){
        int i=log2(k);
        if(i>=ances[a].size())return -1;
        a=ances[a][i];
        k-=1<<i;
    }
    return a;
}

int find_common(int a, int b){
    if(a==b)return a;
    
    for(int i=20;i>=0;i--){
        int c=find_k_ances(a,1<<i);
        int d=find_k_ances(b,1<<i);
        if(c!=-1 && c!=d){
            a=c;
            b=d;
        }
    }
    
    return find_k_ances(a,1);
}


void solve() {
    cin>>n>>q;
    adj.assign(n+1,vector<int>());
    ances.assign(n+1,vector<int>());
    depth.assign(n+1,0);

    for(int i=2;i<=n;i++){
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    };


    build(1,0,1);
    for(int i=0;i<q;i++){
        int a, b;
        cin>>a>>b;

        int ad=depth[a],bd=depth[b];
        if(ad>bd){
            swap(a,b);
            swap(ad,bd);
        }

        b=find_k_ances(b,bd-ad);
        int lca=find_common(a,b);
        int dlca=depth[lca];
        int ans=ad+bd-dlca*2;
        cout<<ans<<endl;
    }
}

int main() {
    FASTIO
    solve();

//    int t;
//    cin>>t;
//    while(t--)solve();

    return 0;
}