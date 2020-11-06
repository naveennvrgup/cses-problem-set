#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;

const ll mx = 1e9 + 7;

int n,q;
vector<int> callstk,depth,start,finish;
vector<vector<int>> ances, adj;

void build(int node, int lvl){
    static int counter=0;
    int cn=callstk.size();
    depth[node]=lvl;
    
    counter++;
    start[node]=counter;

    for(int i=1;i<=cn;i*=2){
        ances[node].push_back(callstk[cn-i]);
    }

    callstk.push_back(node);
    for(auto child: adj[node]){
        build(child,lvl+1);
    }
    callstk.pop_back();

    
    counter++;
    finish[node]=counter;
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
    start.assign(n+1,0);
    finish.assign(n+1,0);
    depth.assign(n+1,0);

    for(int i=2;i<=n;i++){
        int temp;
        cin>>temp;

        adj[temp].push_back(i);
    };


    build(1,1);
    string s="";
    for(int i=0;i<q;i++){
        int a, b;
        cin>>a>>b;

        int ad=depth[a],bd=depth[b];
        if(ad>bd){
            swap(a,b);
            swap(ad,bd);
        }

        b=find_k_ances(b,bd-ad);

        // cout<<find_common(a,b)<<endl;
        s+=to_string(find_common(a,b))+"\n";
    }
    printf("%s",s.c_str());
}

int main() {
    FASTIO
    solve();

//    int t;
//    cin>>t;
//    while(t--)solve();

    return 0;
}