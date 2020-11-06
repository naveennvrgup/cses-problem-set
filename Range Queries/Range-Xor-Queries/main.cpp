#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(NULL);
 
typedef long long ll;
typedef pair<ll, ll> pll;
 
const ll mx = 1e9 + 7;
 
 
 
void solve() {
    int n,q;
    cin>>n>>q;
 
    vector<int> arr(n+1);
    for(int i=0;i<n;i++){
        cin>>arr[i+1];
        arr[i+1]^=arr[i];
    }
 
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<(arr[r]^arr[l-1])<<endl;
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