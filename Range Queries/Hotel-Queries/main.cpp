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
        t.assign(n*4, 0);
 
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
 
        build(1, 0, n-1, arr);
    }
 
    void build(int i, int tl, int tr, vector<int> &arr){
        if(tl==tr)t[i]=arr[tl];
        else{
            int tm=(tl+tr)/2;
            build(i*2, tl, tm, arr);
            build(i*2+1, tm+1, tr, arr);
            t[i]=max(t[i*2],t[i*2+1]);
        }
    }
 
    void sub(int i, int tl, int tr, int l, int r,int pos, int val){
        if(tl==tr)t[i]-=val;
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm)sub(i*2,tl,tm, l,min(r,tm), pos,val);
            else sub(i*2+1,tm+1,tr,max(l,tm+1),r,pos,val);
            t[i]=max(t[i*2],t[i*2+1]);
        }
    }
 
    int findmax(int i, int tl, int tr, int val){
        if(tl==tr)return t[i]>=val ? tl: -1;
        else{
            if(t[i]<val)return -1;
            int tm=(tl+tr)/2;
            if(t[i*2]>=val)return findmax(i*2,tl,tm,val);
            return findmax(i*2+1,tm+1,tr,val);
        }
    }
};
 
void solve() {
    ll n,q;
    cin>>n>>q;
 
    auto st=new ST(n);
 
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
 
        int idx=st->findmax(1,0,n-1,x);
        if(idx==-1){
            cout<<0<<" ";
            continue;
        }
        st->sub(1,0,n-1,0,n-1,idx,x);
        cout<<idx+1<<" ";
    }
    cout<<endl;
}
 
int main() {
    // FASTIO
    solve();
 
//    int t;
//    cin>>t;
//    while(t--)solve();
 
    return 0;
}