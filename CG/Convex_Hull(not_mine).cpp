#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

struct point
{
  double x, y;
} p[maxn];

inline point getvec(point a, point b)
{ 
  return (point){(b.x - a.x), (b.y - a.y)};
}

inline double dis(point a, point b)
{
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

inline double xmul(point a, point b)
{
  return a.x * b.y - b.x * a.y;
}

inline bool operator<(const point &a, const point &b)
{
  if (a.x == b.x)
    return a.y < b.y;
  return a.x < b.x;
}

//上面的函数顾名思义就好了。
int n, stck[maxn];// 存储编号信息
int main()
{
  freopen("in.txt", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    scanf("%lf %lf", &p[i].x, &p[i].y);
  }
  sort(p + 1, p + 1 + n);
  double ans = 0;
  int cnt = 0;// 当前入栈元素数目 cun 始终为栈顶元素
  stck[++cnt] = 1, stck[++cnt] = 2;
  for (int i = 3; i <= n; i++)
  {
    point u = getvec(p[stck[cnt - 1]], p[stck[cnt]]);
    point v = getvec(p[stck[cnt]], p[i]);
    while (xmul(u, v) < 0.0)
    { //判断当前连边的方向。
      if (cnt == 1)
        break;
      cnt--;
      u = getvec(p[stck[cnt - 1]], p[stck[cnt]]);
      v = getvec(p[stck[cnt]], p[i]);
    }
    stck[++cnt] = i;
  }
  int tmp = cnt;
  stck[++cnt] = n, stck[++cnt] = n - 1;
  for (int i = n - 2; i >= 1; i--)
  {
    point u = getvec(p[stck[cnt - 1]], p[stck[cnt]]);
    point v = getvec(p[stck[cnt]], p[i]);
    while (xmul(u, v) < 0.0)
    {
      if (cnt == tmp + 1)
        break;
      cnt--;
      u = getvec(p[stck[cnt - 1]], p[stck[cnt]]);
      v = getvec(p[stck[cnt]], p[i]);
    }
    stck[++cnt] = i;
  }
  for (int i = 1; i <= cnt - 1; i++)
  { //其中会有两次n这个点，但是算距离的时候无所谓，自己到自己为0，如果需要输出一下这个凸包的各个点，那么就需要注意。
    ans += dis(p[stck[i]], p[stck[i + 1]]);
  }
  printf("%.2lf\n", ans);
  freopen("CON", "r", stdin);
  system("pause");
  return 0;
}