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
const int NMAX = 5e5 + 1;
const int INF = 0x3f3f3f3f;

int n;

struct pos {
  int x, y;
};

pos v[NMAX];
int stk[NMAX];

pos Get_Vec(pos a, pos b) {
  return {b.x - a.x, b.y - a.y};
}

double Cross(pos a, pos b) {
  return a.x * b.y - a.y * b.x;
}

ll CCross(pos a, pos b, pos c) {// 计算 c 到线段 ab 的三角形面积（平行四边形面积也可以 同底 面积越大距离越远）
  pos uu = Get_Vec(c, a);
  pos vv = Get_Vec(c, b);
  return abs(Cross(uu, vv));
}

double Len(pos a, pos b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

ll LLen(pos a, pos b) {
  return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

bool cmp(pos a, pos b) {
  if(a.x == b.x) {
    return a.y < b.y;
  } else {
    return a.x < b.x;
  }
}

void solve(){
  if(n == 2) {
    cout << LLen(v[1], v[2]) << endl;
  }
  sort(v + 1, v + n + 1, cmp);
  int tp = 0;
  stk[++tp] = 1;
  stk[++tp] = 2;
  Rep(3, i, n) {
    pos uu = Get_Vec(v[stk[tp - 1]], v[stk[tp]]);
    pos vv = Get_Vec(v[stk[tp]], v[i]);
    while(Cross(uu, vv) < 0.0) {
      if(tp == 1) {
        break;
      }
      tp--;
      uu = Get_Vec(v[stk[tp - 1]], v[stk[tp]]);
      vv = Get_Vec(v[stk[tp]], v[i]);
    }
    stk[++tp] = i;
  }
  int tmp = tp;
  stk[++tp] = n;
  stk[++tp] = n - 1;
  Per(1, i, n - 2) {
    pos uu = Get_Vec(v[stk[tp - 1]], v[stk[tp]]);
    pos vv = Get_Vec(v[stk[tp]], v[i]);
    while(Cross(uu, vv) < 0.0) {
      if(tp == 1 + tmp) {
        break;
      }
      tp--;
      uu = Get_Vec(v[stk[tp - 1]], v[stk[tp]]);
      vv = Get_Vec(v[stk[tp]], v[i]);
    }
    stk[++tp] = i;
  }
  // 测试
  // double ans = 0;
  // Rep(1 ,i, tp - 1) {
  //   ans += Len(v[stk[i]], v[stk[i + 1]]);
  // }
  // printf("%.2lf\n", ans);
  ll ans = -INF;
  int j = 2;
  stk[++tp] = 1;// 保证能取到最后一条线段
  Rep(1, i, tp - 1) {
    while(CCross(v[stk[i]], v[stk[i + 1]], v[stk[j]]) < CCross(v[stk[i]], v[stk[i + 1]], v[stk[j + 1]])) {
      j++;
      if(j > tp) {
        j = 1;
      }
    }
    ll tmp = max(LLen(v[stk[i]], v[stk[j]]), LLen(v[stk[i + 1]], v[stk[j]]));
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}

int main(){
  frep;
  cin >> n;
  Rep(1, i, n) {
    cin >> v[i].x >> v[i].y;
  }
  solve();
  frepC;
  sys;
  return 0;
}