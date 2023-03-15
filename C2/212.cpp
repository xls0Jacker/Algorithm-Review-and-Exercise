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
const int NMAX = 1e5 + 5;// 稍微大一点

int n;// 工作数目

typedef pair<int, int> P;
P f[NMAX];// 起始时间和结束时间

bool cmp(P x, P y){
  return x.second < y.second;
}

void solve(){
  sort(f, f + n, cmp);// 按照最早结束排序
  int Mnum = 1;// 最大工作数（第一个必选）
  int Timet = f[0].second;// 当前工作的结束时间
  int i = 0;// 工作位次
  while(i != n){
    i++;
    if(f[i].first > Timet){
      Mnum++;
      Timet = f[i].second;
    }
  }
  cout << Mnum << endl;
}

int main(){
  frep;
  while(cin >> n){
    memset(f, 0, sizeof(f));
    rep(0, i, n){
      cin >> f[i].first >> f[i].second;
    }
    solve();
  }
  frepC;
  sys;
  return 0;
}