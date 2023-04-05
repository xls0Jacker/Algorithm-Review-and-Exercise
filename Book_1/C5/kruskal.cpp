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
const int VMAX = 1005;// 稍微大一点
const int EMAX = 10005;// 稍微大一点

//**************************************
//*并查集
//**************************************
int par[VMAX];// 父亲结点的编号
int _rank[VMAX];// 树的高度

// 初始化
/// 将父节点设为自己 高度设为 0
void Init(int n) {// n 为结点的数目
  rep(0, i, n) {
    par[i] = i;
    _rank[i] = 0;
  }
}

// 找到 x 结点的根
int find(int x) {
  if(par[x] = x) {// 自己是父节点
    return x;
  } else {
    return par[x] = find(par[x]);// 不断向上检索
  }
}

// 将两不同集合的结点加入同一个集合（谁加谁取决于谁的深度更大）
void unite(int x, int y) {
  x = find(x);// 分别找到两结点的根节点
  y = find(y);
  if(x == y) {// 两者的根节点相同 说明本来就属于同一个集合
    return;
  }
  // 当两者根节点不同时 遵循从深度小的向深度大的连边的规则
  if(_rank[x] < _rank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if(_rank[x] == _rank[y]) {// 当两者深度相同时，为了保持深度小的向深度大的连边 将深度应该较大的 x 深度加一
      _rank[x]++;
    }
  }
}

// 判断结点 x 和 y 是否处于同一个集合
bool same(int x, int y) {
  return find(x) == find(y);// 比较两者的根节点是否相同
}

//************************************
//*最小生成树
//************************************

int V, E;// 顶点数 边数

// 为什么需要当前结点 u ？因为利用并查集的方法需要判断当前结点和指向结点是否处于同一集合
struct edge{
  int u, v, cost;// 当前结点 指向结点 边权
};

// 为什么不使用 vector 的二维数组了？因为在 kruskal 算法中只需要知道全局最短的边就可以了，不需要知道顶点的信息
edge es[EMAX];

// 按照全局边权从小到大的顺序排序
bool cmp(edge a, edge b) {
  return a.cost < b.cost;
}

// 返回值为最小的生成树的边权之和
int kruskal() {
  sort(es, es + E, cmp);// 按照边权从小到大排序
  int res = 0;// 最小生成树的边权之和
  Init(V);// 初始化并查集

  // 对每一条边判断当前结点和指向结点是否在同一个集合中，不同则加入且更新 res
  rep(0, i, E) {
    if(!same(es[i].u, es[i].v)){
      unite(es[i].u, es[i].v);
      res += es[i].cost;
    }
  }
  return res;
}

void solve(){

}

int main(){
  frep;

  solve();
  frepC;
  sys;
  return 0;
}