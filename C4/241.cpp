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
const int KMAX = 1e6 + 5;// 稍微大一点

int par[3*KMAX],_rank[3*KMAX];//数组par表示的是父亲的编号 par[x]=x时，x是所在树的根
//并查集的实现
void Init(int n){//初始化
    rep(0,i,n){
        par[i]=i;
        _rank[i]=0;
    }
}

int find(int x){//查询x的根
    if(par[x]==x){
        return x;
    }
    else {
        return par[x]=find(par[x]);
    }
}

void unite(int x,int y){//合并x和y所属的集合
    x=find(x);
    y=find(y);
    if(x==y){//本身就在同一集合
        return;
    }
    //rank不同
    if(_rank[x]<_rank[y]){//rank小的向rank大的连边
        par[x]=y;
    }
    else {
        par[y]=x;
        if(_rank[x]==_rank[y]) _rank[x]++;//x的高度增加
    }
    
}

bool same(int x,int y){//判断x和y是否属于同一集合
    return find(x)==find(y);
}

int N, K;// 动物朋友数目 信息数目
int t[KMAX], x[KMAX], y[KMAX];// 信息类型 动物x编号 动物y编号

void solve(){
  Init(3 * N);
  int num = 0;// 错误信息的数目
  rep(0, i, K) {
    int X = x[i] - 1;
    int Y = y[i] - 1;
    if(X < 0 or Y < 0 or X >= N or Y >= N){//编号不合法
      num++;
      continue;
    }
    if(t[i] == 1){
      if(same(X, Y + N) or same(X, Y + 2*N)){
        num++;
      } else {
        unite(X, Y);
        unite(X + N, Y + N);
        unite(X + 2 * N, Y + 2 * N);
      }
    } else {
      if(same(X, Y) or same(X, Y + 2*N)){
        num++;
      } else {
        unite(X, Y + N);
        unite(X + N, Y + 2 * N);
        unite(X + 2 * N, Y);
      }
    }
  }
  cout << num << endl;
}

int main(){
  frep;
  cin >> N >> K;
  rep(0, i, K) {
    cin >> t[i] >> x[i] >> y[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}