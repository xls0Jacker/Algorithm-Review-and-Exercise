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
const int MMAX = 105;

int T, n;

vector<queue<int>> v;

int stk[MMAX];
int guide[MMAX];

int ANS1[MMAX];
int ANS2[MMAX];

void solve(){
  bool f = false;// f 输出第二行 t 不输出第二行
  // 处理 1
  Rep(1, i, n) {
    if(v[i].size() == 0) {
      // if(f)
      //   cout << " " << v[i].front();
      // cout << v[i].front();
      // Nq.push_back(v[i].front());
      // v[i].pop();
      continue;
    }
    if(v[i].size() == 1) {// 无依赖项
      ANS1[i] = 1;// 无依赖项第一天开始
    }
  }
  // 处理 2
  Rep(1, i, n) {
    if(v[i].size() == 2) {// 有依赖项(最多一项)
      int sum = 0;// 两项事务的时间和
      queue<int> q = v[i];
      sum += q.front();
      q.pop();
      ANS1[i] = 1;
      ANS1[]
      sum += q.front();
      q.pop();
      if(sum > T) {// 不输出最晚开始时间
        f = true;
      }

    }
  }
}

int main(){
  frep;
  cin >> T >> n;
  v.resize(n);
  v.clear();
  int temp;
  Rep(1, i, n) {
    cin >> stk[i];
  }
  Rep(1, i, n) {
    cin >> temp;
    if(stk[i] == 0) {
      v[i].push(temp);
    } else {
      v[stk[i]].push(temp);
    }
  }
  solve();
  frepC;
  sys;
  return 0;
}