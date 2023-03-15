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
const int NMAX = 55;// 稍微取大一点

int n, m;// 纸片的数目 纸片上的数字和
int f[NMAX]; // 纸片上的数字

// O(n^4)
void solve(){
  rep(0, i, n){
    int a = f[i];
    rep(0, j, n){
      int b = f[j];
      rep(0, k, n){
        int c = f[k];
        rep(0, r, n){
          int d = f[r];
          if(a + b + c + d == m){
            cout << "Yes" << endl;
            return;
          }
        }
      }
    }
  }
  cout << "No" << endl;
}

int main(){
  frep;
  cin >> n >> m;
  rep(0, i, n){
    cin >> f[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}