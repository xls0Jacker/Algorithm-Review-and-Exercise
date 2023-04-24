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
const int NMAX = 1e5 + 1;

int n;

struct pos
{
  double x, y;
};

pos v[NMAX];   //存入的所有的点
pos stk[NMAX]; //凸包中所有的点

double xx, yy;

bool cmp1(pos a, pos b) //排序找第一个点
{
  if (a.y == b.y)
    return a.x < b.x;
  else
    return a.y < b.y;
}

double Cross(pos a, pos b, pos c) //计算叉积 (AB X AC)
{
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

double Len(pos a, pos b) //计算距离
{
  return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

bool cmp2(pos a, pos b) //极角排序另一种方法，速度快
{
  if (atan2(a.y - yy, a.x - xx) != atan2(b.y - yy, b.x - xx))
    return (atan2(a.y - yy, a.x - xx)) < (atan2(b.y - yy, b.x - xx));
  return a.x < b.x;
}

void solve()
{
  if (n == 1)
    printf("%.2lf\n", 0.00);
  else if (n == 2)
    printf("%.2lf\n", Len(v[0], v[1]));
  else
  {
    // memset(stk, 0, sizeof(stk));
    sort(v, v + n, cmp1);
    stk[0] = v[0];
    xx = stk[0].x;
    yy = stk[0].y;
    sort(v + 1, v + n, cmp2); // cmp2是更快的，cmp更容易理解
    stk[1] = v[1];            //将凸包中的第两个点存入凸包的结构体中
    int top = 1;              //最后凸包中拥有点的个数
    rep(2, i, n)
    {
      while (i >= 1 && Cross(stk[top - 1], stk[top], v[i]) < 0) //对使用极角排序的i>=1有时可以不用，但加上总是好的
        top--;
      stk[++top] = v[i]; //控制<0或<=0可以控制重点，共线的，具体视题目而定。
    }
    double s = 0;
    // for(i=1; i<=top; i++)//输出凸包上的点
    // cout<<stk[i].x<<" "<<stk[i].y<<endl;
    Rep(1, i, top) //计算凸包的周长
      s += Len(stk[i - 1], stk[i]);
    s += Len(stk[top], v[0]); //最后一个点和第一个点之间的距离
    /*s+=2*PI*L;
    int ans=s+0.5;//四舍五入
    printf("%d\n",ans);*/
    printf("%.2lf\n", s);
  }
}

int main()
{
  frep;
  cin >> n;
  rep(0, i, n)
  {
    cin >> v[i].x >> v[i].y;
  }
  solve();
  frepC;
  sys;
  return 0;
}