#include"iostream"
#include<string.h>
using namespace std;
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
typedef long long ll;
const int NMAX = 105;

int t;// 样例数目
int n;// 每个样例中所走的步数

typedef pair<int, int> P;// 点坐标
P p[NMAX];

int cun;// 样本次序

/*
  题目要求：
  给出任意一个多边形（顶点为格点） 求出其内部格点的数目 其边上格点的数目 其面积
  解决思路：
    对于其边上的格点数目：
      我们可以利用多边形顶点为格点的特性 对于每一条边 通过 gcd(dx, dy) + 1 获得边上的格点数目
      但是需要注意的是 此时计算的数目会比原计划多上 1 所以直接 gcd(dx, dy) 即可
    对于多边形的面积 利用向量积计算即可
    对于其内部格点的数目 在已知其上两结果后利用 Pick 定理进行求解
*/

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

int area(P a, P b) {
  return a.first * b.second - a.second * b.first;
}

void solve(){
  // 初始化
  int num = 0, sum = 0;// 边上格点数目 面积
  Rep(1, i, n) {
    num += gcd(abs(p[i].first - p[i - 1].first), abs(p[i].second - p[i - 1].second));
    sum += area(p[i], p[i - 1]);
  }
  if(sum < 0) {
    sum = -sum;
  }
  cun++;
  cout << "Scenario #" << cun << ":" << endl;
  printf("%d %d %.1f", (sum - num + 2) / 2, num, sum * 0.5);
  cout << endl;
  cout << endl;
}

int main(){
  frep;
  cin >> t;
  while(t--) {
    memset(p, 0, sizeof p);
    // p[0].first = 0, p[1].second = 0;
    cin >> n;
    int x, y;
    Rep(1, i, n) {
      cin >> x >> y;
      p[i].first = x + p[i - 1].first;
      p[i].second = y + p[i - 1].second;
    }
    solve();
  }
  frepC;
  sys;
  return 0;
}