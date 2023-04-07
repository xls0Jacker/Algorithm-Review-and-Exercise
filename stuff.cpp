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

int V, E;// 顶点数 边数

struct edge{
  int from, to, cost;// 当前结点 指向结点 边权
};

vector<edge> G[VMAX];// 每个顶点 i 的边集

void add_edge(int x,int y, int z) {
  G[x].push_back({x, y, z});
}

vector<int> Ans;// 存储结果
bool used[VMAX];// 当前结点是否访问过

// void bfs(int s) {// 初始结点
//   queue<int> que;// 存放已经加入的结点
//   Ans.push_back(s);
//   used[s] = true;
//   que.push(s);
//   while(!que.empty()){
//     int u = que.front();
//     que.pop();
//     rep(0, i, G[u].size()) {
//       if(G[u][i].cost != 0 and !used[G[u][i].to]) {
//         Ans.push_back(G[u][i].to);
//         que.push(G[u][i].to);
//         used[G[u][i].to] = true;
//       }
//     }    
//   }
// }

// int prime[MAX_N];//第i个素数 //prime[0] = 2
// bool is_prime[MAX_N];//is_prime[i]为true时表示i为素数
// int sieve(int n){//O(nloglogn)
//     int p=0;//素数的个数
//     Rep(0,i,n) is_prime[i]=true;
//     is_prime[0]=is_prime[1]=false;
//     Rep(2,i,n){
//         if(is_prime[i]){
//             prime[p++]=i;
//             for(int j=i*2;j<=n;j+=i) is_prime[j]=false;
//         }
//     }
//     return p;
// }

void solve(){
  // vector<int> Ans = discover(100);
  // rep(0, i, Ans.size()) {
  //   cout << Ans[i] << " ";
  // }
  // cout << endl;
}

int main(){
  frep;
  // cin >> V >> E;
  // int x, y, z;// 当前结点 指向结点 边权 (临时量)
  // rep(0, i, E) {
  //   cin >> x >> y >> z;
  //   add_edge(x, y, z);
  // }
  solve();
  frepC;
  sys;
  return 0;
}