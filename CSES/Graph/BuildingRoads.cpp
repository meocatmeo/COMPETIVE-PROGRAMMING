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
 
const int maxn = 1e5+5;
vector<int> vt[maxn];
vector<int> res;
int vis[maxn], n , m;
void dfs(int u){
    if(vis[u]) return;;
    vis[u] = 1;
    for (int v : vt[u]){
        dfs(v);
    }
}

int main(){
    faster;
    cin >> n >> m;
    for (int i = 1; i <= m ;i++){
        int u, v;
        cin >> u >> v;
        vt[u].pb(v);
        vt[v].pb(u);
    }   
    for (int i = 1;i <= n;i++){
        if(!vis[i]){
            res.pb(i);
            dfs(i);
        }
    }
    cout << res.size() - 1 << '\n';
    for (int i = 1;i < res.size(); i++){
        cout << res[i-1] << ' ' << res[i] << '\n';
    }
    return 0;
}