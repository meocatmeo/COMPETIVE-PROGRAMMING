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
int n, m;
char a[1005][1005];
int dx[] ={0, 0, 1, -1};
int dy[] ={1, -1, 0, 0};
bool vis[1005][1005];
char dir[] = {'U', 'D', 'R', 'L'};
struct coor{
    int x, y;
};

bool des(int x, int y){
    return (x == n || y == m ) && a[x][y] =='.';
}
bool isValid(int x, int y){
    return (x >= 1 && x <= n && y >= 1 && y <=m) && a[x][y] == '.';
}
void dfs(coor start){

}

int main(){
    faster;
    cin >> n >> m;
    coor start;
    for (int i = 1;i <= n; i++){
        for (int j = 1;j <= m;j++){
            cin >> a[i][j];
            if(a[i][j] =='A') {
                start ={i, j};
            }
        }
    }

    return 0;
}