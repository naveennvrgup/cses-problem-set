#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(NULL);
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;
 
const ll mx = 1e9 + 7;
 
void solve() {
    int r,c;
    cin>>r>>c;
 
    vector<vector<char>> arr(r,vector<char>(c));
    vector<vector<vector<int>>> m(r,vector<vector<int>>(c,{-2,-2,-2}));
 
    vector<int> a,b;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='A')a={i,j};
            if(arr[i][j]=='B')b={i,j};
        }
    } 
 
    queue<vector<int>> q;
    q.push({a[0],a[1],0,-1,-1});
 
    while(!q.empty()){
        auto curr=q.front();
        auto x=curr[0];
        auto y=curr[1];
        auto l=curr[2];
        q.pop();
 
        if(x<0 || y<0 || x>=r || y>=c)continue;
        if(arr[x][y]=='#')continue;
        if(m[x][y][0]!=-2)continue;
        m[x][y]={curr[3],curr[4],l};
 
        q.push({x+1,y,l+1,x,y});
        q.push({x-1,y,l+1,x,y});
        q.push({x,y+1,l+1,x,y});
        q.push({x,y-1,l+1,x,y});
    }
 
    auto ans=m[b[0]][b[1]];
    if(ans[0]==-2){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        cout<<ans[2]<<endl;
        string res="";
        int cx=b[0];
        int cy=b[1];
        while(cx!=-1){
            auto temp=m[cx][cy];
            int x=temp[0];
            int y=temp[1];
            if(cx==x+1 && cy==y)res+="D"; 
            if(cx==x-1 && cy==y)res+="U"; 
            if(cx==x && cy==y+1)res+="R"; 
            if(cx==x && cy==y-1)res+="L"; 
            cx=x;
            cy=y;
        }
        cout<<string(res.rbegin(),res.rend())<<endl;
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