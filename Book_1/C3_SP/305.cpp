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
const int NMAX = 1e6 + 5;// 稍微大一点

int N;// 当前数值
// 2^0 ~ 2^19  20 个数
int f[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};

int counter;// 方案数的计数器

void solve(){
  
  cout << counter << endl;
}

int main(){
  frep;
  while(cin >> N) {
    solve();
  }
  frepC;
  sys;
  return 0;
}