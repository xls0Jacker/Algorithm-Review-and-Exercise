#include"bits/stdc++.h"
using namespace std;
#define frep freopen("in.txt", "r", stdin)
#define frepC freopen("CON", "r", stdin)
#define sys system("pause")
#define rep(a, i, n) for (int i = a; i < n; i++)
#define Rep(a, i, n) for (int i = a; i <= n; i++)
#define per(a, i, n) for (int i = n; i > a; i--)
#define Per(a, i, n) for (int i = n; i >= a; i--)
typedef long long ll;
const int NMAX = 105;// 稍微大一点

int N, M, S;// 轨道数目 每条轨道上物品的数目 框的最大容量
vector<int> f;// 操作序列
queue<char> A[NMAX];// 轨道物品

void solve(){
  vector<char> Q;// 流水线
  stack<char> L;// 框
  rep(0, i, f.size()){
    if(f[i] != 0){// 不是指令 0
      if(L.size() < S) {// 框没有满
        if(A[f[i] - 1].size() > 0) {// 轨道上有物品
          L.push(A[f[i] - 1].front());// 推入物品
          A[f[i] - 1].pop();
        }
      } else {// 框已经满了
        Q.push_back(L.top());// 框顶推入流水线
        L.pop();
        L.push(A[f[i] - 1].front());// 推入物品
        A[f[i] - 1].pop();
      }
    } else {// 是指令 0
      if(L.size() > 0) {// 框中有物品
        Q.push_back(L.top());// 框顶推入流水线
        L.pop();
      }
    }
  }
  rep(0, i, Q.size()) {
    cout << Q[i];
  }
  cout << endl;
}

int main(){
  frep;
  cin >> N >> M >> S;
  char c;
  rep(0, i, N){
    rep(0, j, M) {
      cin >> c;
      A[i].push(c);
    }
  }
  int temp;
  while(cin >> temp and temp != -1){
    f.push_back(temp);
  }
  solve();
  frepC;
  sys;
  return 0;
}