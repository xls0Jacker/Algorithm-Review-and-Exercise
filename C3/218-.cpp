#include"bits/stdc++.h"
using namespace std;
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
typedef long long ll;
const int NMAX = 105;// 稍微大一点
const int WMAX = 1005;// 稍微大一点

int n, W;
int w[NMAX], v[NMAX];
int ans;

int f[NMAX][WMAX];// 记忆化数组

int dfs(int i, int j) {// 物品位次 当前背包容量 返回当前价值
  if(f[i][j] >= 0) {
    return f[i][j];
  }
  if(i == n) {
    ans = 0;
  } else if(j < w[i]){
    dfs(i + 1, j);
  } else {
    ans = max(dfs(i + 1, j), dfs(i + 1, j - w[i]) + v[i]);
  }
  return f[i][j] = ans;
}

void solve(){
  memset(f, -1, sizeof(f));
  cout << dfs(0, W) << endl;
}

int main(){
  frep;
  cin >> n >> W;
  rep(0, i, n) {
    cin >> w[i] >> v[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}