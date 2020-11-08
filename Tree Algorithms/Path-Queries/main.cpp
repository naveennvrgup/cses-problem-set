#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;

const ll mx = 1e9 + 7;

const int s=2e5+5;
int n,q;
vector<ll> arr, psum(s), val(s), start(s), finish(s);
vector<vector<ll>> adj(s);

class ST{
    vector<ll> t;
    int n;
public:
    ST(vector<ll> arr){
        n=arr.size();
        t.assign(n*4,0);
    }


    ll sum(int i, int tl, int tr, int pos){
        if(tl==tr)return t[i];
        else {
            int tm=(tl+tr)/2;
            if(pos<=tm)return t[i]+sum(i*2,tl,tm,pos);
            else return t[i]+sum(i*2+1,tm+1,tr,pos);
        }
    }

    void update(int i, int tl, int tr, int l, int r, ll val){
        if(l>r)return;

        if(l==tl && tr==r)t[i]+=val;
        else{
            int tm=(tl+tr)/2;
            update(i*2,tl,tm,l,min(r,tm),val);
            update(i*2+1,tm+1,tr,max(l,tm+1),r,val);
        }
    }
};

void dfs(int node, int parent, ll sum){
    static int counter=-1;
    
    psum[node]=sum+val[node];
    start[node]=++counter;

    for(auto child: adj[node]){
        if(child==parent)continue;
        dfs(child,node, psum[node]);
    }

    finish[node]=counter;
}


void solve() {
    cin>>n>>q;

    for(int i=1;i<=n;i++)cin>>val[i];
    for(int i=2;i<=n;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0,0);
    arr.assign(n,0);
    auto st=new ST(arr);

    for(int i=0;i<q;i++){
        ll type;
        cin>>type;
        if(type==1){
            ll i,x; 
            cin>>i>>x;
            st->update(1,0,n-1,start[i],finish[i],x-val[i]);
        }else{
            ll i;
            cin>>i;
            cout<<st->sum(1,0,n-1,start[i])+psum[i]<<endl;
        }
    }
    
}

// --------------------------------
// shows WA for half the TC
// --------------------------------
int main() {
    FASTIO
    solve();

//    int t;
//    cin>>t;
//    while(t--)solve();

    return 0;
}