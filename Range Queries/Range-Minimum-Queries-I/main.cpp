#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(NULL);
 
typedef long long ll;
typedef pair<ll, ll> pll;
 
const ll mx = 1e9 + 7;
 
class ST{
    vector<int> t;
public:
    ST(int n){
        t.assign(4*n,INT_MAX);
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        build(arr, 1, 0, n-1);
    }
 
    void build(vector<int> &a, int v, int tl, int tr){
        if(tl==tr){
            t[v]=a[tl];
        }else{
            int tm=(tl+tr)/2;
            build(a,v*2,tl,tm);
            build(a,v*2+1,tm+1,tr);
            t[v]=min(t[v*2],t[v*2+1]);
        }
    }
 
    int findmin(int v, int tl, int tr, int l, int r){
        if(l>r)return INT_MAX;
        if(l==tl && r==tr)return t[v];
        int tm=(tl+tr)/2;
        auto res= min(
            findmin(v*2,tl,tm,l,min(r,tm)),
            findmin(v*2+1,tm+1,tr,max(l,tm+1),r)
        );
        // printf("%d,%d = %d\n",l+1,r+1,res);
        return res;
    }
 
 
};
 
void solve() {
    ll n,q;
    cin>>n>>q;
 
    auto st=new ST(n);
 
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<st->findmin(1,0,n-1,l-1,r-1)<<endl;
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
