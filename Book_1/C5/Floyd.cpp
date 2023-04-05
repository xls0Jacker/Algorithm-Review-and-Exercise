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
// 以下顶点和边数的实际值依据题目要求进行改写
const int VMAX = 105;// 稍微大一点
const int EMAX = 1005;// 稍微大一点
const int INF = 1e9 + 7;

int d[VMAX][VMAX][VMAX];// 只使用 0 ~ k 顶点和 i， j 顶点时的 i 到 j 的最短路径
int V;// 顶点数

void warshall_floyd() {
  rep(0, k, V) {
    rep(0, i, V) {
      rep(0, j, V) {
        d[k][i][j] = min(d[k - 1][i][j], d[k - 1][i][k] + d[k - 1][k][j]);
      }
    }
  }
}

void solve(){
  warshall_floyd();
}

int main(){
  frep;
  
  solve();
  frepC;
  sys;
  return 0;
}