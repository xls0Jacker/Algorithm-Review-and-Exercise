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
const int NMAX = 355;// 稍微大一点
const int MMAX = 125;// 稍微大一点

int N, M;// 格子数目 卡牌数目
int a[NMAX];// 每个格子上的数值
int f[MMAX];// 卡牌数字

int x[4];// 每个数值的数目
int dp[MMAX][MMAX][MMAX][MMAX];// 表示 1 2 3 4 各选 i j k l 张时的最大权值

void solve(){
  // 初始化
  dp[0][0][0][0] = a[0];
  int npos = 0;// 当前位置
  // 状态转移
  Rep(0, i, x[0]) {
    Rep(0, j, x[1]) {
      Rep(0, k, x[2]) {
        Rep(0, l, x[3]) {
          npos = 1 * i + 2 * j + 3 * k + 4 * l;
          if(i != 0) {// 防止越界
            dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l] + a[npos]);
          }
          if(j != 0) {// 防止越界
            dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l] + a[npos]);
          }
          if(k != 0) {// 防止越界
            dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k - 1][l] + a[npos]);
          }
          if(l != 0) {// 防止越界
            dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k][l - 1] + a[npos]);
          }
        }
      }
    }
  }
  cout << dp[x[0]][x[1]][x[2]][x[3]] << endl;
}

int main(){
  frep;
  cin >> N >> M;
  rep(0, i, N) {
    cin >> a[i];
  }
  rep(0, i, M) {
    cin >> f[i];
    if(f[i] == 1) {
      x[0]++;
    } else if(f[i] == 2){
      x[1]++;
    } else if(f[i] == 3) {
      x[2]++;
    } else {
      x[3]++;
    }
  }
  solve();
  frepC;
  sys;
  return 0;
}