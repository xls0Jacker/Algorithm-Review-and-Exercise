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
const int MMAX = 55;// 稍微大一点
const int NMAX = 55;// 稍微大一点

int m, n;// 矩阵大小
int f[MMAX][NMAX];// 好心程度

int dp[MMAX + NMAX][NMAX][NMAX];// 两张纸条当前走的步数
                    // 其中一张纸条的横坐标 另一张纸条的横坐标

// 特别的 当坐标值为 -1 时，代表其未访问过

void solve(){
  for (int k = 1; k < m + n; k++) {
    for (int i = 1; i <= m and i <= k; i++) {
      for (int j = 1; j <= m and j <= k; j++) {
        dp[k][i][j] = max({dp[k - 1][i - 1][j], 
          dp[k - 1][i][j - 1], dp[k - 1][i - 1][j - 1],
            dp[k - 1][i][j]});
        if(i == j) {
          dp[k][i][j] += f[i][k - i + 1];// 路径重复时只加一次
        } else {
          dp[k][i][j] += f[i][k - i + 1] + f[j][k - j + 1];
        }
      }
    }
  }
  cout << dp[n + m - 1][m][m] << endl;
}

int main(){
  frep;
  cin >> m >> n;
  Rep(1, i, m) {
    Rep(1, j, n) {
      cin >> f[i][j];
    }
  }
  solve();
  frepC;
  sys;
  return 0;
}