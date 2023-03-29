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
const int NMAX = 1e6 + 5;// 稍微大一点

int n, W;
int w[NMAX], v[NMAX];
int ans;

void dfs(int i, int j, int sum) {// 物品位次 当前背包容量 返回当前价值
  if(i == n) {
    ans = max(sum, ans);
    return;
  }
  if(j < w[i]) {
    dfs(i + 1, j, sum);
  } else {
    dfs(i + 1, j, sum);
    dfs(i + 1, j - w[i], sum + v[i]);
  }
}

void solve(){
  dfs(0, W, 0);
  cout << ans << endl;
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