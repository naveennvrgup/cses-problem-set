#include <iostream>
 
using namespace std;
typedef long long ll;
 
const ll mx = 1e9 + 7;
 
ll pow(ll a, ll b) {
    if (b == 0)return 1;
    ll temp = pow(a, b / 2);
    if (b % 2)return ((temp * temp) % mx * a) % mx;
    else return (temp * temp) % mx;
}
 
void solve() {
    ll a, b;
    cin >> a >> b;
 
    cout << pow(a, b) << endl;
}
 
 
int main() {
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++)solve();
 
    return 0;
}