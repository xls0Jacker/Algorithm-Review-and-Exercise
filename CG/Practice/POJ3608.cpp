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
const int NMAX = 1e4 + 1, MMAX = 1e4 + 1;

struct pos {
  double x, y;
};

int N, M;
pos v1[NMAX], v2[NMAX];
int stk1[NMAX], stk2[NMAX];

bool cmp(pos a, pos b) {
  if(a.x == b.x) {
    return a.y < b.y;
  } else {
    return a.x < b.x;
  }
}

pos Get_Vec(pos a, pos b) {
  return {b.x - a.x, b.y - a.y};
}

double Cross(pos a, pos b) {
  return a.x * b.y - a.y * b.x;
}

double CCross(pos a, pos b, pos c) {
  pos uu = Get_Vec(a, c);
  pos vv = Get_Vec(b, c);
  return abs(Cross(uu, vv));
}

// a 到 bc 组成的直线的距离
double LenPL(pos a, pos b, pos c) {
  return fabs(((b.y - c.y) * a.x - (b.x - c.x) * a.y + (b.x * c.y - c.x * b.y)) / sqrt(pow(b.y - c.y, 2) + pow(b.x - c.x, 2)));
}

void solve(){
  // 凸包 1
  sort(v1 + 1, v1 + N + 1, cmp);
  int tp1 = 0;
  stk1[++tp1] = 1;
  stk1[++tp1] = 2;
  Rep(3, i, N) {
    pos uu = Get_Vec(v1[stk1[tp1 - 1]], v1[stk1[tp1]]);
    pos vv = Get_Vec(v1[stk1[tp1]], v1[i]);
    while(Cross(uu, vv) < 0.0) {
      if(tp1 == 1) {
        break;
      }
      tp1--;
      uu = Get_Vec(v1[stk1[tp1 - 1]], v1[stk1[tp1]]);
      vv = Get_Vec(v1[stk1[tp1]], v1[i]);
    }
    stk1[++tp1] = i;
  }
  int tmp = tp1;
  stk1[++tp1] = N, stk1[++tp1] = N - 1;
  Per(1, i, N - 2) {
    pos uu = Get_Vec(v1[stk1[tp1 - 1]], v1[stk1[tp1]]);
    pos vv = Get_Vec(v1[stk1[tp1]], v1[i]);
    while(Cross(uu, vv) < 0.0) {
      if(tp1 == tmp + 1) {
        break;
      }
      tp1--;
      uu = Get_Vec(v1[stk1[tp1 - 1]], v1[stk1[tp1]]);
      vv = Get_Vec(v1[stk1[tp1]], v1[i]);
    }
    stk1[++tp1] = i;
  }
  // 凸包 2
  sort(v2 + 1, v2 + M + 1, cmp);
  int tp2 = 0;
  stk2[++tp2] = 1;
  stk2[++tp2] = 2;
  Rep(3, i, M) {
    pos uu = Get_Vec(v2[stk2[tp2 - 1]], v2[stk2[tp2]]);
    pos vv = Get_Vec(v2[stk2[tp2]], v2[i]);
    while(Cross(uu, vv) < 0.0) {
      if(tp2 == 1) {
        break;
      }
      tp2--;
      uu = Get_Vec(v2[stk2[tp2 - 1]], v2[stk2[tp2]]);
      vv = Get_Vec(v2[stk2[tp2]], v2[i]);
    }
    stk2[++tp2] = i;
  }
  tmp = tp2;
  stk2[++tp2] = M, stk2[++tp2] = M - 1;
  Per(1, i, M - 2) {
    pos uu = Get_Vec(v2[stk2[tp2 - 1]], v2[stk2[tp2]]);
    pos vv = Get_Vec(v2[stk2[tp2]], v2[i]);
    while(Cross(uu, vv) < 0.0) {
      if(tp2 == tmp + 1) {
        break;
      }
      tp2--;
      uu = Get_Vec(v2[stk2[tp2 - 1]], v2[stk2[tp2]]);
      vv = Get_Vec(v2[stk2[tp2]], v2[i]);
    }
    stk2[++tp2] = i;
  }
  // // 测试凸包
  // cout << "#1:" << endl;
  // Rep(1, i, tp1 - 1) {
  //   cout << v1[stk1[i]].x << " " << v1[stk1[i]].y << endl;
  // }
  // cout << "#2:" << endl;
  // Rep(1, i, tp2 - 1) {
  //   cout << v2[stk2[i]].x << " " << v2[stk2[i]].y << endl;
  // }
  double ans = 0x3f3f3f3f3f3f3f3f;
  int j = 2;
  Rep(1, i, tp1 - 1) {
    if(stk1[i] == stk1[i + 1]) {
      continue;
    }
    while(CCross(v1[stk1[i]], v1[stk1[i + 1]], v2[stk2[j - 1]]) <
    CCross(v1[stk1[i]], v1[stk1[i + 1]], v2[stk2[j]])) {
      j--;
      if(j < 1) {
        j = tp1 - 1;
      }
    }
    double temp = min(LenPL(v1[stk1[i]], v1[stk1[i + 1]], v2[stk2[j]]), LenPL(v1[stk1[i]], v1[stk1[i + 1]], v2[stk2[j]]));
    ans = min(ans, temp);
  }
  j = 2;
  Rep(1, i, tp2 - 1) {
    if(stk2[i] == stk2[i + 1]) {
      continue;
    }
    while(CCross(v2[stk2[i]], v2[stk2[i + 1]], v1[stk1[j]]) <
    CCross(v2[stk2[i]], v2[stk2[i + 1]], v1[stk1[j + 1]])) {
      j++;
      if(j > tp2 - 1) {
        j = 0;
      }
    }
    double temp = min(LenPL(v2[stk2[i]], v2[stk2[i + 1]], v1[stk1[j]]), LenPL(v2[stk2[i]], v2[stk2[i + 1]], v1[stk1[j]]));
    ans = min(ans, temp);
  }
  printf("%.5lf\n", ans);
}

int main(){
  frep;
  cin >> N >> M;
  Rep(1, i, N) {
    cin >> v1[i].x >> v1[i].y;
  }
  Rep(1, i, M) {
    cin >> v2[i].x >> v2[i].y;
  }
  solve();
  frepC;
  sys;
  return 0;
}