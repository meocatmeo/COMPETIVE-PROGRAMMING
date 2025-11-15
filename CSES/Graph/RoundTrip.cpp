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
vector<int> a[maxn];
int n, m, cy_end, cy_st;
vector<bool> vis;
vector<int> par;
bool dfs(int v, int parr){
    vis[v] = true;
    for (int u : a[v]){
        if(u == parr) continue;
        if(vis[u]){
            cy_end = v;
            cy_st = u;
            return true;
        }
        par[u] = v;
        if(dfs(u, par[u])) return true;
    }
    return false;
}

void find(){
    vis.assign(n +1, false);
    par.assign(n +1, -1);
    cy_st = -1;
    for (int v = 0; v < n; v++){
        if(!vis[v] && dfs(v, par[v]))
            break;
    }
    if(cy_st == -1) cout << "IMPOSSIBLE";
    else {
        vector<int> cycle;
        cycle.pb(cy_st);
        while(cy_end != cy_st){
            cycle.pb(cy_end);
            cy_end = par[cy_end];
        }
        cycle.pb(cy_st);
        cout << cycle.size() << '\n';
        for (int v : cycle) cout << v << ' ';
    }

}

int main(){
    faster;
    cin >> n >> m;
    for (int i = 0 ;i < m ;i++){
        int u, v;
        cin >> u >> v;
        a[v].pb(u);
        a[u].pb(v);
    }
    find();
    return 0;
}