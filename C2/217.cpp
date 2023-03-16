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
const int NMAX = 20005;// 稍微大一点

int n;// 木板的个数
priority_queue<int, vector<int>, greater<int>> L;// 木板的长度(从小到大排)

void solve(){
  ll cost = 0;// 代价
  rep(1, i, n){
    int MIN_1 = L.top();// 获取最短板
    L.pop();
    int MIN_2 = L.top();// 获取次短板
    L.pop();
    cost += MIN_1 + MIN_2;
    L.push(MIN_1 + MIN_2);
  }
  cout << cost << endl;
}

int main(){
  frep;
  cin >> n;
  int temp;
  rep(0, i, n) {
    cin >> temp;
    L.push(temp);
  }
  solve();
  frepC;
  sys;
  return 0;
}