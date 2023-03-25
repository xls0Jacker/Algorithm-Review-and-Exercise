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
const int NMAX = 1e3 + 5;// 稍微大一点
const int EMAX = 1e6 + 5;// 稍微大一点
const int INF = 1e9 + 7;

int V, E;// 顶点数 边数
int cost[NMAX][NMAX];// 点 u 到点 v 的距离
int d[NMAX];// 从起点 s 到点 v 的距离

struct edge{
  int to, cost;// 边指向的顶点 边的花费
};

vector<edge> G[EMAX];// 所有顶点边的集合

typedef pair<int, int> P;// 到当前顶点的距离 当前顶点编号

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P>> que;// 默认按照 first 进行排序
  // 初始化
  d[s] = 0;
  que.push(P(0, s));

  while(que.empty() != true) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if(d[v] < p.first)
      continue;// 已经在其他点的过程中更新过一次，队列中存储的是老的顶点
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
} 

void solve(){
  // 初始化
  fill(d, d + V, INF);
  int s = 0;// 假设初始点为 0
  int f;// 终点
  dijkstra(s);
  cout << d[f] << endl;
}

int main(){
  frep;
  
  solve();
  frepC;
  sys;
  return 0;
}