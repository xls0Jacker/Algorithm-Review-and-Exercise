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
const int NMAX = 1e4 + 1;
const double PI = 3.1415926;

int n;
double a, b, r;

struct pos{
  double x, y;
}v[NMAX];

int stk[NMAX];

double x, y, theta;

int cun;// 点集下标

// pos Rotation(pos p, double t) {
//   return {p.x *cos(t) - p.y *sin(t), p.x *sin(t) + p.y *cos(t)};
// }

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
  return sqrt(pow(b.x - a.x, 2) + pow(a.y - b.y, 2));
}

void solve(){
  // 计算凸包
  sort(v + 1, v + cun + 1, cmp);
  int tp = 0;
  stk[++tp] = 1, stk[++tp] = 2;
  Rep(3, i, cun) {
    pos uu = GetVec(v[stk[tp - 1]] , v[stk[tp]]);
    pos vv = GetVec(v[stk[tp]], v[i]);
    while(!Side(uu, vv)) {
      if(tp == 1) {
        break;
      }
      tp--;
      uu = GetVec(v[stk[tp - 1]] , v[stk[tp]]);
      vv = GetVec(v[stk[tp]], v[i]);
    }
    stk[++tp] = i;
  }
  int tmp = tp;
  stk[++tp] = cun, stk[++tp] = cun - 1;
  Per(1, i, cun - 2) {
    pos uu = GetVec(v[stk[tp - 1]] , v[stk[tp]]);
    pos vv = GetVec(v[stk[tp]], v[i]);
    while(!Side(uu, vv)) {
      if(tp == 1 + tmp) {
        break;
      }
      tp--;
      uu = GetVec(v[stk[tp - 1]] , v[stk[tp]]);
      vv = GetVec(v[stk[tp]], v[i]);
    }
    stk[++tp] = i;
  }
  double ans = 0;
  Rep(1, i, tp - 1) {
    ans += Len(v[stk[i]], v[stk[i + 1]]);
  }
  // ans += 2 * PI * r;
  printf("%.2lf\n", ans);
}

int main(){
  frep;
  cin >> cun;
  double x, y;
  Rep(1, i, cun) {
    cin >> v[i].x >> v[i].y;
  }
  solve();
  frepC;
  sys;
  return 0;
}