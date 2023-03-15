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

int T; // 数据组数
int L, n; // 杆的长度 蚂蚁的数目
int x[NMAX]; // 蚂蚁的位置

// 数据预处理
void Pre(int j){
  // 将蚂蚁转到一边
  if(x[j] > L/2){// 向上取整？
    x[j] = L - x[j];
  }
}

void solve(){
  sort(x, x + n);
  int MINT = x[n - 1];
  int MAXT = L - x[0];
  cout << MINT << " " << MAXT << endl;
}

int main(){
  frep;
  cin >> T;
  rep(0, i, T){
    cin >> L >> n;
    rep(0, j, n){
      cin >> x[j];
      Pre(j);// 数据预处理
    }
    solve();
  }
  frepC;
  sys;
  return 0;
}