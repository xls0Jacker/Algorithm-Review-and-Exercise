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
const int MMAX = 105;// 稍微大一点

int N, M;// 园林大小
char F[NMAX][MMAX];// 园林地图

// 方向向量
int x[] = {0, 0, -1, -1, -1, 1, 1, 1};
int y[] = {-1, 1, -1, 0, 1, -1, 0, 1};

/// 将周围水洼全部变成水
// i j 为位次
void dfs(int u, int v){
  F[u][v] = '.';
  rep(0, i, 8){
    // 位移方向
    int dx = x[i];
    int dy = y[i];
    // 位移后位置
    int nx = u + dx;
    int ny = v + dy;
    if(nx < 0 or nx > N or ny < 0 or ny > M or F[nx][ny] != 'W'){
      continue;
    }
    dfs(nx, ny);
  }
}

void solve(){
  int sum = 0;// 统计 dfs 的次数
  rep(0, i, N){
    rep(0, j, M){
      if(F[i][j] == 'W'){
        dfs(i, j);
        sum++;
      }
    }
  }
  cout << sum << endl;
}

int main(){
  frep;
  cin >> N >> M;
  rep(0, i, N){
    rep(0, j, M){
      cin >> F[i][j];
    }
  }
  solve();
  frepC;
  sys;
  return 0;
}