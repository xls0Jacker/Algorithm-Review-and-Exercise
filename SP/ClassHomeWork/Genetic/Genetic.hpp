#ifndef _GENETIC_H_
#define _GENETIC_H_
#include"vector"
using namespace std;

#define  PI    3.14159265358979323846

//�Ŵ��㷨��������Ⱥ��ģ��0~100������ֳ��������������������������ʡ��������
# define GROUP_SCALE    80
# define MAX_GENS       100
# define N_VARS         2
# define P_MATING       0.8
# define P_MUTATION     0.05

struct Individual
{
    double Xn[N_VARS];      //��ű���ֵ������������������
    double Fitness;         //��Ӧֵ
    double ReFitness;       //��Ӧֵ�����ܶ�
    double SumFitness;      //�ۼӷֲ���Ϊ����ת
};
struct X_Range
{
    double Upper;           //�������Ͻ�ȡֵ
    double Lower;           //�������½�ȡֵ
};
// std::vector<float> ave_Fitness;

template<typename T>
T randT(T Lower, T Upper); //��������������������� // �������̶�

void crossover(int &seed); // �Ŵ�����--����
void elitist();        //��������������õĻ���
void evaluate();// ��Ӧֵ����

void initGroup(int &seed);// ��Ⱥ��ʼ��

void selectBest();
void mutate(int &seed);

double r8_uniform_ab(double a, double b, int &seed);
int i4_uniform_ab(int a, int b, int &seed);

void report(int Xnration);
void selector(int &seed);
//void showTime();
void Xover(int one, int two, int &seed);
#endif // !_GENETIC_H_