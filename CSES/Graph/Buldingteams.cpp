#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define BIT(x, i) (1 & ((x) >> (i)))
#define OFF(x, i) ((x) ^ (1 << (i)))
#define ON(x, i) ((x) | (1 << (i)))
#define CNT(x) __builtin_popcountll(x)
#define file(name) \
    freopen(name ".inp", "r", stdin); \
    freopen(name ".out", "w", stdout);
#define faster \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); \
    cout.tie(0);
const int maxn = 1e5+4;
vector<int> a[maxn];
int ans[maxn], check[maxn], n ,m;
bool found = true;
void solve(int u, int g){
    check[u] = 1;
    ans[u] = g;
    for (int v : a[u]){
        if(check[v] == false) solve(v, (g == 2) ? 1 : 2);
        else if(check[v] == true && ans[v] == ans[u]){
            found = false;
            return;
        }
    }
}
 
int main(){
    faster;
    cin >> n >> m;
    for (int i = 1;i <= m;i++){
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    int group = 1;
    for (int i =1 ;i <= n ;i++){
        if(check[i] == false){
            solve(i, group);
        }
        if(found == false){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    for (int i = 1; i <= n ;i++) cout << ans[i] << ' ';

    return 0;
} 