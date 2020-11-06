#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(NULL);
 
typedef long long ll;
typedef pair<ll, ll> pll;
 
const ll mx = 1e9 + 7;
 
class ST{
    vector<ll> t;
    
    public:
    ST(int n){
        t.assign(n*4,0);
 
        vector<ll> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
 
        build(arr,1,0,n-1);
    }
 
    void build(vector<ll> &arr,int i,int tl, int tr){
        if(tl==tr){
            t[i]=arr[tl];
        }else{
            int tm=(tl+tr)/2;
            build(arr,i*2,tl,tm);
            build(arr,i*2+1,tm+1,tr);
            t[i]=t[i*2]+t[i*2+1];
        }
    }
 
    ll sum(int i, int l, int r, int tl, int tr){
        if(l>r)return 0;
 
        if(l==tl && r==tr)return t[i];
        else {
            int tm=(tl+tr)/2;
            return sum(i*2,l,min(r,tm),tl,tm)+sum(i*2+1,max(l,tm+1),r,tm+1,tr);
        }
    }
 
    void update(int i, int tl, int tr,int pos,int v){
        if(tl==tr){
            t[i]=v;
        }else{
            int tm=(tl+tr)/2;
            if(pos>tm)update(i*2+1,tm+1,tr,pos,v);
            else update(i*2,tl,tm,pos,v);
            t[i]=t[i*2]+t[i*2+1];
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
            cout<<st->sum(1,a-1,b-1,0,n-1)<<endl;
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