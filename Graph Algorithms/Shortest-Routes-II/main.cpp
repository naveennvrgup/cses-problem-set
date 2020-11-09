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
 
const int s=501;
const ll inf=1e18;
 
ll n,m,q;
vll adj(s,vl(s,inf));
 
void solve(){
    cin>>n>>m>>q;
 
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a][b]=min(adj[a][b],c);
        adj[b][a]=min(adj[b][a],c);
    }
 
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(adj[i][j]==inf)cout<<"x ";
    //         else cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
 
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
 
    for(int i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        if(a==b)cout<<0<<endl;
        else if(adj[a][b]>=inf)cout<<-1<<endl;
        else cout<<adj[a][b]<<endl;
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