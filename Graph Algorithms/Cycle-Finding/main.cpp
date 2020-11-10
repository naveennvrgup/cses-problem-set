#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll>  vl;
typedef vector<vl>  vll;
typedef vector<vll>  vlll;
typedef vector<char> vc;
typedef vector<vc> vcc;
const ll mx = 1e9 + 7;
const ll inf=1e18;

const int s=2e5+5;
ll n,m;
vll adj;
vl dis(s), p(s,-1);


void solve(){
    cin>>n>>m;

    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj.push_back({a,b,c});
    }

    ll e;
    for(int i=0;i<n;i++){
        e=-1;
        for(auto x: adj){
            if(dis[x[1]]>dis[x[0]]+x[2]){
                dis[x[1]]=dis[x[0]]+x[2];
                p[x[1]]=x[0];
                e=x[1];
            }
        }
    }

    if(e==-1){
        cout<<"NO"<<endl;
        return;
    }

    for(int i=0;i<n;i++)e=p[e];
    cout<<"YES"<<endl;
    vl ans={e};
    for(auto x=p[e];x!=e;x=p[x]){
        ans.push_back({x});
    }
    ans.push_back(e);
    reverse(ans.begin(),ans.end());

    for(auto x: ans)cout<<x<<" ";
    cout<<endl;

}


int main() {
    FASTIO
    solve();
 
//    int t;
//    cin>>t;
//    while(t--)solve();
 
    return 0;
}