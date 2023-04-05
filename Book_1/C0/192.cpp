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
const int NMAX = 105;// 稍微大一点

int n;// 棍子的数目
int a[NMAX];// 棍子的长度

// O(n^3)
void solve(){
  sort(a, a + n);
  int MAXC = 0;// 最大三角形周长
  Per(0, i, n - 1){
    int MAXL = a[i];// 当前的最长长度

    // 从最短的两个棍子判断约束条件 成立则换长度更长的棍子
    rep(0, j, i - 1){
      int MINL_1 = a[j];
      int MINL_2 = a[j + 1];

      // 约束条件
      if(MINL_1 + MINL_2 > MAXL){
        MAXC = max(MAXC, MINL_1 + MINL_2 + MAXL);// 更新最大周长
      }
    }
  }
  cout << MAXC << endl;
}

int main(){
  frep;
  cin >> n;
  rep(0, i, n){
    cin >> a[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}