#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;
typedef vector<ll> vl;
typedef vector<vl> vll;

const ll mx = 1e9 + 7;
vector<vector<char>> board(8,vector<char>(8,'.'));
ll res;
vl row(8),col(8),ld(20),fd(20);

void util(int i){
    if(i==8){
        res++;
        return;
    }

    for(int j=0;j<8;j++){
        if(board[i][j]=='*')continue;
        if(row[i] || col[j] || ld[i-j+10] || fd[i+j])continue;

        row[i]=1;
        col[j]=1;
        ld[i-j+10]=1;  
        fd[i+j]=1;
        
        util(i+1);
        
        row[i]=0;
        col[j]=0;
        ld[i-j+10]=0;  
        fd[i+j]=0;
    }
}

void solve(){
    res=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)cin>>board[i][j];
    }

    util(0);
    cout<<res<<endl;
}


int main() {
    FASTIO
    solve();

//    int t;
//    cin>>t;
//    while(t--)solve();

    return 0;
}
