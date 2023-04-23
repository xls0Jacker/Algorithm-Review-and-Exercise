#ifndef _GENETIC_H_
#define _GENETIC_H_
#include"vector"
using namespace std;

#define  PI    3.14159265358979323846

//遗传算法参数，种群规模（0~100）、繁殖代数、函数变量个数、交叉概率、变异概率
# define GROUP_SCALE    80
# define MAX_GENS       100
# define N_VARS         2
# define P_MATING       0.8
# define P_MUTATION     0.05

struct Individual
{
    double Xn[N_VARS];      //存放变量值（函数有两个变量）
    double Fitness;         //适应值
    double ReFitness;       //适应值概率密度
    double SumFitness;      //累加分布，为轮盘转
};
struct X_Range
{
    double Upper;           //变量的上界取值
    double Lower;           //变量的下界取值
};
// std::vector<float> ave_Fitness;

template<typename T>
T randT(T Lower, T Upper); //产生任意类型随机数函数 // 用于轮盘赌

void crossover(int &seed); // 遗传算子--交叉
void elitist();        //基因保留（保留最好的基因）
void evaluate();// 适应值函数

void initGroup(int &seed);// 种群初始化

void selectBest();
void mutate(int &seed);

double r8_uniform_ab(double a, double b, int &seed);
int i4_uniform_ab(int a, int b, int &seed);

void report(int Xnration);
void selector(int &seed);
//void showTime();
void Xover(int one, int two, int &seed);
#endif // !_GENETIC_H_