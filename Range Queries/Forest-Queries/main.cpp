#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(NULL);
 
typedef long long ll;
typedef pair<ll, ll> pll;
 
const ll mx = 1e9 + 7;
 
 
void solve() {
    ll n,q;
    cin>>n>>q;
 
    vector<vector<ll>> arr(n+1,vector<ll>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            if(c=='*')arr[i][j]=1;
        }
    }
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)arr[i][j]+=arr[i][j-1];
    }
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)arr[i][j]+=arr[i-1][j];
    }
 
 
 
    for(int i=0;i<q;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<arr[x2][y2]+arr[x1-1][y1-1]-arr[x1-1][y2]-arr[x2][y1-1]<<endl;
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