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
const int NMAX = 1e5 + 1;

int n;

struct pos{
  double x, y;
}v[NMAX];// 点集

int stk[NMAX];// 记录栈内元素的编号

bool cmp(pos a, pos b) {
  if(a.x == b.x) {
    return a.y < b.y;
  } else {
    return a.x < b.x;
  }
}

pos GetVec(pos a, pos b) {
  return {b.x - a.x, b.y - a.y};
}

double Cross(pos a, pos b) {
  return a.x * b.y - a.y * b.x;
}

bool Side(pos a, pos b) {
  if(Cross(a, b) > 0) {
    return true;
  } else {
    return false;
  }
} 

double Len(pos a, pos b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void solve(){
  sort(v + 1, v + n + 1, cmp);
  int tp = 0;// 栈内元素的数目 tp 始终为栈顶
  stk[++tp] = 1, stk[++tp] = 2;
  Rep(3, i, n) {// 求解上凸壳
    pos uu = GetVec(v[stk[tp - 1]], v[stk[tp]]);
    pos vv = GetVec(v[stk[tp]], v[i]);
    while(!Side(uu, vv)) {
      if(tp == 1) {
        break;
      }
      tp--;
      uu = GetVec(v[stk[tp - 1]], v[stk[tp]]);
      vv = GetVec(v[stk[tp]], v[i]);
    }
    stk[++tp] = i;
  }
  int tmp = tp;
  stk[++tp] = n, stk[++tp] = n - 1;
  Per(1, i, n - 2) {
    pos uu = GetVec(v[stk[tp - 1]], v[stk[tp]]);
    pos vv = GetVec(v[stk[tp]], v[i]);
    while(!Side(uu, vv)) {
      if(tp == tmp + 1) {
        break;
      }
      tp--;
      uu = GetVec(v[stk[tp - 1]], v[stk[tp]]);
      vv = GetVec(v[stk[tp]], v[i]);
    }
    stk[++tp] = i;
  }
  double ans = 0;
  Rep(1, i, tp - 1) {// 这其中有两个最右侧的一个点 但是计算距离时不需要考虑（为 0）
    ans += Len(v[stk[i]], v[stk[i + 1]]);
  }
  printf("%.2lf\n", ans);
}

int main(){
  frep;
  cin >> n;
  double x, y;
  Rep(1, i, n) {
    cin >> v[i].x >> v[i].y;
  }
  solve();
  frepC;
  sys;
  return 0;
}