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
const int NMAX = 25;// 稍微大一点

int n, k;// 数字的数目 部分和
int f[NMAX];// 数字的数值

// O(2^n)
/// 每次选择或不选择第 i 位数字值
// i 为数字下标 sum 为当前部分和
bool dfs(int i, int sum){
  // 终止条件
  if(i == n){
    return sum == k;
  }
  if(dfs(i + 1, sum + f[i]) and sum + f[i] <= k){// 选择第 i 位数字值
    return true;
  }
  if(dfs(i + 1, sum)){// 不选择第 i 位数字值
    return true;
  }
  return false;
}

void solve(){
  if(dfs(0, 0) == true){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

int main(){
  frep;
  while(cin >> n){
    memset(f, 0, sizeof(f));// 格式化数组
    rep(0, i, n){
      cin >> f[i];
    }
    cin >> k;
    solve();
  }
  frepC;
  sys;
  return 0;
}