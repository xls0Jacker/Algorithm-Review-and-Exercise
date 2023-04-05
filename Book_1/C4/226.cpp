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
const int NMAX = 2 * 1e4 + 5;// 稍微大一点

int N;// 加油站数目
int L, P;// 终点位置 初始油量

typedef pair<int, int> Pii;
Pii AB[NMAX];// 加油站距离终点位置 加油量 

priority_queue<int> Atr;// 可加油量（默认从大到小） 

bool cmp(Pii A, Pii B) {
  return A.first < B.first;
}

void solve(){
  rep(0, i, N){
    AB[i].first = L - AB[i].first;
  }
  sort(AB, AB + N, cmp);
  AB[N].first = L;// 等价最后一个加油站的位置
  int S = 0;// 车的起点位置
  int i = 0;// 下一个加油点位次
  int p = P;// 当前油量
  int s = S;// 当前位置
  int num = 0;// 加油次数
  while(s < L) {
    if(s + p >= AB[i].first){// 可达下一个加油站
      Atr.push(AB[i].second);
      p -= AB[i].first - s;
      s = AB[i].first;
      i++;
    } else {// 不可达下一个加油站
      if(Atr.size() == 0) {
        cout << -1 << endl;
        return;
      }
      p += Atr.top();
      Atr.pop();
      num++;
    }
  }
  cout << num << endl;
}

int main(){
  frep;
  cin >> N;
  rep(0, i, N) {
    cin >> AB[i].first >> AB[i].second;
  }
  cin >> L >> P;
  solve();
  frepC;
  sys;
  return 0;
}