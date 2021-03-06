#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;

const ll mx = 1e9 + 7;

const int s=2e5+5;
int n,q;
vector<ll> arr, val(s), start(s), finish(s);
vector<vector<ll>> adj(s);

class ST{
    vector<ll> t;
    int n;
public:
    ST(vector<ll> arr){
        n=arr.size();
        t.assign(n*4,0);
        build(1,0,n-1);
    }

    void build(int i, int tl, int tr){
        if(tl==tr)t[i]=arr[tl];
        else{
            int tm=(tl+tr)/2;
            build(i*2,tl,tm);
            build(i*2+1,tm+1,tr);
            t[i]=t[i*2]+t[i*2+1];
        }
    }

    ll sum(int i, int tl, int tr, int l, int r){
        if(l>r)return 0;

        if(tl==l && tr==r)return t[i];
        else {
            int tm=(tl+tr)/2;
            return sum(i*2,tl,tm,l,min(r,tm))+sum(i*2+1,tm+1,tr,max(l,tm+1),r);
        }
    }

    void update(int i, int tl, int tr, int pos, int val){
        if(tl==tr)t[i]=val;
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm)update(i*2,tl,tm,pos,val);
            else update(i*2+1,tm+1,tr,pos,val);
            t[i]=t[i*2]+t[i*2+1];
        }
    }
};

void dfs(int node, int parent){
    static int counter=-1;

    start[node]=++counter;
    arr.push_back(val[node]);

    for(auto child: adj[node]){
        if(child==parent)continue;
        dfs(child,node);
    }

    finish[node]=counter+1;
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

    dfs(1,0);
    auto st=new ST(arr);

    for(int i=0;i<q;i++){
        ll type;
        cin>>type;
        if(type==1){
            ll i,x;
            cin>>i>>x;
            st->update(1,0,n-1,start[i],x);
        }else{
            ll i;
            cin>>i;
            cout<<st->sum(1,0,n-1,start[i],n-1)-st->sum(1,0,n-1,finish[i],n-1)<<endl;
        }
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