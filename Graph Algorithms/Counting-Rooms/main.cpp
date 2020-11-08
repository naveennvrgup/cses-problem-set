#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const ll mx = 1e9 + 7;
 
int row, col;
 
void dfs(int i, int j, vector<vector<char>> &m) {
    if (i < 0 || j < 0 || i >= row || j >= col)return;
    if (m[i][j] == '#')return;
 
    m[i][j] = '#';
    dfs(i - 1, j, m);
    dfs(i, j - 1, m);
    dfs(i + 1, j, m);
    dfs(i, j + 1, m);
}
 
int main() {
    cin >> row >> col;
 
    vector<vector<char>> m(row, vector<char>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)cin >> m[i][j];
    }
 
    int res = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (m[i][j] == '.') {
                res++;
                dfs(i, j, m);
            }
        }
    }
 
    cout << res << endl;
 
    return 0;
}