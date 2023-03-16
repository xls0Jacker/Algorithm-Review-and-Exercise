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

int R, N;// 范围 点的数目
int x[NMAX];// 点的位置

bool vis[NMAX];// 点的标记情况

// O(n^2)
void solve(){
  sort(x, x + N);
  int i = 0;// 最近未标记点的位次
  int num = 0;// 标记的点数
  while(i != N) {
    int s = x[i++];// 最近的未标记起点
    while(i < N and x[i] <= R + s)
      i++;
    int p = x[i - 1];// s 的 R 范围内最远点
    while(i < N and x[i] <= R + p)
      i++;// 找下一个最近的未标记起点
    num++;
  }
  cout << num << endl;
}

int main(){
  frep;
  while(cin >> R >> N){
    if(R == -1 and N == -1){
      break;
    }
    memset(x, 0, sizeof(x));
    rep(0, i, N){
      cin >> x[i];
    }
    solve();
  }
  frepC;
  sys;
  return 0;
}