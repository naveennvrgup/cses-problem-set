#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll>  vl;
typedef vector<vl>  vll;
typedef vector<char> vc;
typedef vector<vc> vcc;

const ll mx = 1e9 + 7;

const int s=1005;

ll r,c;
string ans;
map<vl,vl>p;
vcc adj(s,vc(s));
queue<vl> m,q;

bool isSafe(vl curr){
    return !(curr[0]<0 || curr[0]>=r || curr[1]<0 || curr[1]>=c);
}

void printit(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}

void printans(int x, int y){
    cout<<"YES"<<endl;

    while(p[{x,y}][0]!=-1){
        auto pc=p[{x,y}];
        int px=pc[0],py=pc[1];

        if(px-x == 1)ans+='U';
        else if(px-x==-1)ans+='D';
        else if(py-y==1)ans+='L';
        else ans+='R';

        x=px;
        y=py;
    }

    cout<<ans.size()<<endl;
    cout<<string(ans.rbegin(),ans.rend())<<endl;
}

void solve() {
    cin>>r>>c;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>adj[i][j];
            if(adj[i][j]=='A')q.push({i,j});
            else if(adj[i][j]=='M')m.push({i,j});
        }
    }
    
    p[q.front()]={-1,-1};

    while(!q.empty() || !m.empty()){
        int qs=q.size(),ms=m.size();

        for(int i=0;i<ms;i++){
            auto curr=m.front();
            m.pop();
            int x=curr[0],y=curr[1];

            if(!(adj[x][y]=='.' || adj[x][y]=='*' || adj[x][y]=='M'))continue;
            adj[x][y]='M';

            for(int a=-1;a<=1;a++){
                for(int b=-1;b<=1;b++){
                    if(abs(a)==abs(b))continue;
                    if(isSafe({x+a,y+b}) && (adj[x+a][y+b]=='.' || adj[x+a][y+b]=='*')){
                        m.push({x+a,y+b});
                    }            
                }
            }
        }

        for(int i=0;i<qs;i++){
            auto curr=q.front();
            q.pop();
            int x=curr[0],y=curr[1];

            if(adj[x][y]!='.' && adj[x][y]!='A')continue;
            if(x==0 || x==r-1 || y==0 || y==c-1){
                printans(x,y);
                return;
            }
            adj[x][y]='*';

            for(int a=-1;a<=1;a++){
                for(int b=-1;b<=1;b++){
                    if(abs(a)==abs(b))continue;
                    if(isSafe({x+a,y+b}) && adj[x+a][y+b]=='.'){
                        q.push({x+a,y+b});
                        p[{x+a,y+b}]={x,y};
                    }            
                }
            }
        }


    }

    cout<<"NO"<<endl;
}


int main() {
    FASTIO
    solve();

//    int t;
//    cin>>t;
//    while(t--)solve();

    return 0;
}