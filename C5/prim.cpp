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
const int VMAX = 1e3 + 5;// 稍微大一点
const int EMAX = 1e6 + 5;// 稍微大一点
const int INF = 1e9 + 7;

int V, E;// 顶点数 边数
int mincost[VMAX];// 集合 X 中到点 u 的最小边权值
bool vis[VMAX];// 顶点 u 是否在集合 X 中

typedef pair<int, int> P;// 集合 X 到点 u 的最小边权值 顶点 u (V \ X 中)

struct edge{
  int to, cost;// 结点 v 边权
};

vector<edge> G[EMAX];// 边集

int prim(){
  fill(mincost, mincost + V, INF);
  fill(vis, vis + V, false);
  mincost[0] = 0;// 默认从 0 号顶点开始
  int res = 0;// 最小生成树的数值初始化

  priority_queue<P, vector<P>, greater<P>> que;// 默认按照 first 从小到大排序
  while(que.empty() != true) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if(mincost[v] < p.first) {// 在其他点过程中已经被松弛，队列中是旧节点
      continue;
    }
    vis[v] = true;// 将点 v 加入集合 X
    rep(0, i, G[v].size()) {
      edge e = G[v][i];
      if(!vis[e.to] and mincost[e.to] > e.cost) {
        res += e.cost;
        if(mincost[e.to] != INF) {// 集合 V \ X 中结点 mincost[e.to] 一定为 INF（不为则代表已经加入过 X 集合了）
          res -= e.cost;
        }
        mincost[e.to] = e.cost;
        que.push(P(mincost[e.to], e.to));
      }
    }
  }
}

void solve(){
  int ans = prim();
}

int main(){
  frep;
  
  solve();
  frepC;
  sys;
  return 0;
}