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
const int NMAX = 2 * 1e4 + 5;// 稍微大一点

int n;// 行数
int L[NMAX], R[NMAX];// 每一行线的左端点和右端点

// 有缺陷 无法处理到达两端距离相等的线段
void solve(){
  int sum = 0;
  int npos = 1;
  Rep(1, i, n) {
    if(abs(L[i] - npos) <= abs(R[i] - npos)) {// 离左端点更近
      sum += abs(L[i] - npos) + (R[i] - L[i]);// 当前位置到线段最近端点的距离 + 线段长度
      npos = R[i];// 更新位置到远端点
      sum++;// 到下一行
    } else if(abs(L[i] - npos) <= abs(R[i] - npos)) {// 离右端点更近 
      sum += abs(R[i] - npos) + (R[i] - L[i]);// 当前位置到线段最近端点的距离 + 线段长度
      npos = L[i];// 更新位置到远端点
      sum++;// 到下一行
    } 
  }
  sum--;// 处理 i = n 时继续向下一行的错误
  sum += n - npos;// 最后到终点
  cout << sum << endl;
}

int main(){
  frep;
  cin >> n;
  Rep(1, i, n) {
    cin >> L[i] >> R[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}