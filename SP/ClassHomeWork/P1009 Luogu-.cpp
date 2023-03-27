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

int dp[MMAX][NMAX][MMAX][NMAX];// 表示小渊纸条到达 (i, j)
            // ，同时小轩纸条到达 (k, l) 时的最大好心度之和

void solve(){
  Rep(1, i, m) {
    Rep(1, j, n) {
      Rep(1, k, m) {
        Rep(1, l, n) {
          if(i == k and j == l) {// 两个点重合
              continue;
          }
          dp[i][j][k][l] =
            max({dp[i][j - 1][k - 1][l],
              dp[i][j - 1][k][l - 1],
                dp[i - 1][j][k][l - 1],
                  dp[i - 1][j][k - 1][l]}) +
                           f[i][j] + f[k][l];
        }
      }
    }
  }
  cout << dp[m][n - 1][m - 1][n] << endl;
}

int main(){
  frep;
  // 输入
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