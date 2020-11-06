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
 
        build(1,0,n-1,arr);
    }
 
    void build(int i, int tl, int tr, vector<int> &arr){
        if(tl==tr)t[i]=arr[tl];
        else{
            int tm=(tl+tr)/2;
            build(i*2,tl,tm,arr);
            build(i*2+1,tm+1,tr,arr);
            t[i]=min(t[i*2],t[i*2+1]);
        }
    }
 
    int findmin(int i, int tl, int tr, int l, int r){
        if(l>r)return INT_MAX;
        if(l==tl && r==tr)return t[i];
 
        int tm=(tl+tr)/2;
        return min(
            findmin(i*2,tl,tm,l,min(tm,r)), 
            findmin(i*2+1,tm+1,tr,max(tm+1,l),r)
        );
    }
 
    void update(int i, int tl, int tr, int pos, int val){
        if(tl==tr)t[i]=val;
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm)update(i*2,tl,tm,pos,val);
            else update(i*2+1,tm+1,tr,pos,val);
            t[i]=min(t[i*2],t[i*2+1]);
        }
    }
};
 
void solve() {
    ll n,q;
    cin>>n>>q;
 
    auto st=new ST(n);
 
    for(int i=0;i<q;i++){
        int t,a,b;
        cin>>t>>a>>b;
        if(t==1){
            st->update(1,0,n-1,a-1,b);
        }else{
            cout<<st->findmin(1,0,n-1,a-1,b-1)<<endl;
        }
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