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
const int INF = 1e9 + 7;

int N, M;// 迷宫大小
char F[NMAX][MMAX];// 迷宫地图

// 方向向量
int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0};

int sx, sy;// 起点坐标
int fx, fy;// 终点坐标
typedef pair<int, int> P;// 当前位置
int dis[NMAX][MMAX];// 当前位置离起点距离

int bfs(){
  // 初始化
  rep(0, i, N){
    rep(0, j, M){
      dis[i][j] = INF;
    }
  }
  queue<P> Q;
  Q.push(P{sx, sy});
  dis[sx][sy] = 0;

  while(Q.size()){
    P res = Q.front();
    Q.pop();
    if(res.first == fx and res.second == fy){
      break;
    }
    rep(0, i, 4){
      // 位移方向
      int dx = x[i];
      int dy = y[i];
      // 位移后的位置
      int nx = res.first + dx;
      int ny = res.second + dy;
      if(nx >= 0 and nx < N and ny >= 0 and ny < M 
      and F[nx][ny] != '#' and dis[nx][ny] == INF){
        Q.push(P{nx, ny});
        dis[nx][ny] = dis[res.first][res.second] + 1;
      }
    }
  }
  return dis[fx][fy];
}

void solve(){
  cout << bfs() << endl;
}

int main(){
  frep;
  cin >> N >> M;
  rep(0, i, N){
    rep(0, j, M){
      cin >> F[i][j];
      // 找到初始坐标和终点坐标
      if(F[i][j] == 'S'){
        sx = i;
        sy = j;
      }
      if(F[i][j] == 'G'){
        fx = i;
        fy = j;
      }
    }
  }
  solve();
  frepC;
  sys;
  return 0;
}