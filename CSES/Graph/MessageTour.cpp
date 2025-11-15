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

const int maxn = 2e5+5;
int dis[maxn], n, m, par[maxn];
vector<int> a[maxn];

void bfs(int u){
    reset(dis, -1);
    queue<int> q;
    dis[u] = 0;
    q.push(u);
    while(q.size()){
        int u = q.front();
        q.pop();
        for (int v : a[u]){
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
} 

void trace(){
    vector<int> path;
    int end = n;
    while(end != 0){
        path.pb(end);
        end = par[end];
    }
    reverse(all(path));
    cout << path.size() << '\n';
    for (auto p : path) cout << p << ' ';

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
    bfs(1);
    if(dis[n] == -1) cout << "IMPOSSIBLE";
    else {
        trace();
    }
    return 0;
} 