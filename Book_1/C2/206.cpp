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

int T;// 测试数据数
int C[6];// 每种硬币的数目（默认面额从大到小）
int A;// 总和

int f[6] = {500, 100, 50, 10, 5, 1};// 面额

void solve(){
  int i = -1;// 当前硬币位次
  int num = 0;// 当前使用硬币数
  while(i != 6){
    i++;
    int nnum = A / f[i];// 需要的硬币数
    if(nnum == 0)// 剩余空间不足
      continue;
    if(C[i] - nnum > 0){// 当前硬币数目足够
      num += nnum;
      A -= nnum * f[i];
    } else {// 当前硬币数目不足
      num += C[i];
      A -= C[i] * f[i];
    }
  }
  cout << num << endl;
}

int main(){
  frep;
  cin >> T;
  while(T--){
    memset(C, 0, sizeof(C));// 规格化
    Per(0, i, 5){
      cin >> C[i];
    }
    cin >> A;
    solve();
  }
  frepC;
  sys;
  return 0;
}