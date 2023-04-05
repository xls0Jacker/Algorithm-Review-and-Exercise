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
const int NMAX = 1005;// 稍微大一点

int n;// 顶点的个数
vector<int> G[NMAX];// 每一顶点和其相邻子节点（邻接表）

int color[NMAX];// 每个顶点的颜色

bool dfs(int u,int c){// 当前顶点 当前顶点的颜色
  color[u] = c;// 当前节点染色
  rep(0, i, G[u].size()){
    if(color[G[u][i]] == c){
      return false;
    }
    if(color[G[u][i]] == 0 and !dfs(G[u][i], -c)){// 未染色且不能染色为另一颜色
      return false;
    }
  }
  return true;// 全染色
}

// 从第一个顶点开始dfs， 与其子节点相邻同色；其子节点未染色则染色未反颜色（定颜色为 1 or -1）
void solve(){
  if(dfs(0, 1)){// 默认第一个顶点颜色为 1
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

int main(){
  frep;
  cin >> n;
  int x, y; // 顶点 相邻子节点
  while(cin >> x >> y){
    // 无向图
    G[x].push_back(y);
    G[y].push_back(x);
  }
  solve();
  frepC;
  sys;
  return 0;
}