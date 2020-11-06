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
        t.assign(4*n,0);
    }
 
    void update(int i, int tl, int tr, int l, int r, int diff){
        if(l>r)return;
        
        if(l==tl && r==tr)t[i]+=diff;
        else{
            int tm=(tl+tr)/2;
            update(i*2, tl,tm,l,min(tm,r),diff);
            update(i*2+1,tm+1,tr,max(l,tm+1),r,diff);
        }
    }
 
    ll get(int i, int tl, int tr, int pos){
        if(tl==tr)return t[i];
        else{
            int tm=(tl+tr)/2;
            if(pos<=tm)return t[i]+get(i*2,tl,tm,pos);
            else return t[i]+get(i*2+1,tm+1,tr,pos);
        }
    }
};
 
void solve() {
    ll n,q;
    cin>>n>>q;
 
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
 
    auto st=new ST(n);
 
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t==1){
            int a,b,u;
            cin>>a>>b>>u;
 
            // for(int i=0;i<n;i++)cout<<st->get(1,0,n-1,i)<<" ";
            // cout<<endl;
            
            // printf("%d %d %d\n",a,b,u);
            st->update(1,0,n-1,a-1,b-1,u);
            
            // for(int i=0;i<n;i++)cout<<st->get(1,0,n-1,i)<<" ";
            // cout<<endl<<endl;
        }else{
            int k;
            cin>>k;
            cout<<st->get(1,0,n-1,k-1)+arr[k-1]<<endl;
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