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
 
const ll s=5e3+5;
ll n,m;
vll e(s,vl(3));
vl d(s,-inf);

void printit(){
    for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    cout<<endl;
}

void solve(){
    cin>>n>>m;

    for(int i=0;i<m;i++){
        cin>>e[i][0]>>e[i][1]>>e[i][2];
    }

    d[1]=0;

    for(int k=0;k<n;k++){
        vl temp=d;
        for(int i=0;i<m;i++){
            if(d[e[i][0]]==-inf)continue;
            temp[e[i][1]]=max(temp[e[i][1]],d[e[i][0]]+e[i][2]);
        }
        d=temp;
        // printit();
    }

    int last=d[n];
    for(int k=0;k<n;k++){
        vl temp=d;
        for(int i=0;i<m;i++){
            if(d[e[i][0]]==-inf)continue;
            if(temp[e[i][1]]<d[e[i][0]]+e[i][2])temp[e[i][1]]=inf;
        }
        d=temp;
        // printit();
    }

    if(inf==d[n])cout<<-1<<endl;
    else cout<<d[n]<<endl;
}

int main() {
    FASTIO
    solve();
 
//    int t;
//    cin>>t;
//    while(t--)solve();
 
    return 0;
}