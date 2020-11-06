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
        t.assign(n*4,0);
        build(1,0,n-1);
    }
 
    void build(int i, int tl, int tr){
        if(tl==tr)t[i]=1;
        else{
            int tm=(tl+tr)/2;
            build(i*2,tl,tm);
            build(i*2+1,tm+1,tr);
            t[i]=t[i*2]+t[i*2+1];
        }
    }
 
    int find(int i, int tl, int tr, int l, int r, int val){
        if(tl==tr)return tl;
        else{
            int tm=(tl+tr)/2;
            if(val<=t[i*2])return find(i*2,tl,tm,l,min(r,tm),val);
            return find(i*2+1,tm+1,tr,max(l,tm+1),r,val-t[i*2]);
        }
    }
 
    void del(int i, int tl, int tr, int pos){
        if(tl==tr)t[i]=0;
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm)del(i*2, tl, tm, pos);
            else del(i*2+1,tm+1,tr,pos);
            t[i]=t[i*2]+t[i*2+1];
        }
    }
};
 
 
void solve() {
    ll n;
    cin>>n;
 
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    auto st=new ST(n);
 
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        
        int idx=st->find(1,0,n-1,0,n-1,x);
        // printf("%d %d = %d\n",x,idx,arr[idx]);
        cout<<arr[idx]<<" ";
        st->del(1,0,n-1,idx);
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