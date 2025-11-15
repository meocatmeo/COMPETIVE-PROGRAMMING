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
 
char a[10][10];
bool row[10], col[10], dia1[40], dia2[40]; // dia1[i+j] , dia2[i-j+7]
int res ;
bool isValid(int x, int y){
    return x >= 1 && x <= 8 && y >= 1 && y <= 8 && a[x][y] != '*';
}
void backtrack(int row){
    if(row == 9){
        res++;
        return;
    }
    for (int i = 1; i <= 8; i++){
        if(a[row][i] == '*') continue;
        if(col[i] || dia1[row + i] || dia2[row - i + 7]) continue;
        col[i] = dia1[row + i] = dia2[row - i + 7] = 1;
        backtrack(row + 1);
        col[i] = dia1[row + i] = dia2[row - i + 7] = 0;
    }
}

int main(){
    faster;
    for (int i = 1; i <= 8 ; i++){
        for (int j = 1; j <= 8; j++){
            cin >> a[i][j];
        }
    }
    backtrack(1);
    cout << res;
    return 0;
}