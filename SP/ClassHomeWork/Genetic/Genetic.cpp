# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <iomanip>
# include <cmath>
# include <ctime>
# include <cstring>
#include <math.h>
# include "Genetic.hpp"





//������Ⱥ�ڴ棬���ж��1���Ƿ�����һ�������������
struct Individual Population[GROUP_SCALE + 1];   

X_Range  XnRange[N_VARS] = { { -5, 5}, {-5, 5} };

double Best_Ave_Fitness = -1;

///�Ŵ�����--����
//�н���Ȩ�����и������н���
void crossover(int &seed)
{
    const double a = 0.0;
    const double b = 1.0;
    int mem;
    int one;
    int first = 0;
    double x;

    for (mem = 0; mem < GROUP_SCALE; ++mem)
    {
        x = randT(0.0,1.0);
        //x = r8_uniform_ab(a, b, seed);//�����������

        if (x < P_MATING)// ÿ���鷢�����ν���
        {
            ++first;

            if (first % 2 == 0)//����
            {
                Xover(one, mem, seed);
            }
            else
            {
                one = mem;
            }

        }
    }
    return;
}

//������һ�������ŵ�һ���Ĵ������Ż���Ŀ��
void elitist()
{
    int i;
    double best;
    int best_mem;
    double worst;
    int worst_mem;

    best = Population[0].Fitness;
    worst = Population[0].Fitness;

    for (i = 0; i < GROUP_SCALE - 1; ++i)// �ҵ����ŵ�һ��������һ��
    {
        if (Population[i + 1].Fitness < Population[i].Fitness)
        {

            if (best <= Population[i].Fitness)
            {
                best = Population[i].Fitness;
                best_mem = i;
            }

            if (Population[i + 1].Fitness <= worst)
            {
                worst = Population[i + 1].Fitness;
                worst_mem = i + 1;
            }

        }
        else
        {

            if (Population[i].Fitness <= worst)
            {
                worst = Population[i].Fitness;
                worst_mem = i;
            }

            if (best <= Population[i + 1].Fitness)
            {
                best = Population[i + 1].Fitness;
                best_mem = i + 1;
            }

        }

    }

//���ڵ�ǰ��������ֵ�Ĵ��������ǰ������ֵС����һ������һ����ֵ���Ÿ���ȡ����ǰ����������
//������
    if (Population[GROUP_SCALE].Fitness <= best)// ������һ������ֵ ʹ�Լ���Ϊ��һ������һ������ֵ
    {
        for (i = 0; i < N_VARS; i++)
        {
            Population[GROUP_SCALE].Xn[i] = Population[best_mem].Xn[i];
        }
        Population[GROUP_SCALE].Fitness = Population[best_mem].Fitness;
    }
    else// ��һ��������ֵ�����ڵ�ǰ��һ���Ͱѵ�ǰ��һ�������ֵ��Ϊ��һ��������ֵ
    {
        for (i = 0; i < N_VARS; i++)
        {
            Population[worst_mem].Xn[i] = Population[GROUP_SCALE].Xn[i];
        }
        Population[worst_mem].Fitness = Population[GROUP_SCALE].Fitness;
    }
    return;
}
//������Ӧ��ֵ
void evaluate()
{
    int member;
    int i;
    double x[N_VARS + 1];

    for (member = 0; member < GROUP_SCALE; member++)
    {
        for (i = 0; i < N_VARS; i++)
        {
            x[i + 1] = Population[member].Xn[i];
        }
        // ��Ӧֵ����--1
		/*Population[member].Fitness = (6.452*(x[1]+0.125*x[2])*pow((cos(x[1])-cos(2*x[2])),2))/sqrt(0.8+pow((x[1]-4.2),2)+2*pow((x[2]-7),2))+3.226*x[2];*/
        Population[member].Fitness = 1.0 / (20.0 + x[1] * x[1] + x[2] * x[2] - 10.0 * (cos(2 * PI * x[1]) + cos(2 * PI * x[2])));
    }
    return;
}

double round(double val)

{
	return (val>0.0)? floor(val+0.5):ceil(val-0.5);

}

//�������ε������
int i4_uniform_ab(int a, int b, int &seed)
{
    int c;
    const int i4_huge = 2147483647;
    int k;
    float r;
    int value;

    if (seed == 0)
    {
        cerr << "\n";
        cerr << "I4_UNIFORM_AB - Fatal error!\n";
        cerr << "  Input value of SEED = 0.\n";
        exit(1);
    }
    //��֤aС��b
    if (b < a)
    {
        c = a;
        a = b;
        b = c;
    }

    k = seed / 127773;
    seed = 16807 * (seed - k * 127773) - k * 2836;

    if (seed < 0)
    {
        seed = seed + i4_huge;
    }

    r = (float)(seed)* 4.656612875E-10;
    //
    //  Scale R to lie between A-0.5 and B+0.5.
    //
    r = (1.0 - r) * ((float)a - 0.5)
        + r   * ((float)b + 0.5);
    //
    //  Use rounding to convert R to an integer between A and B.
    //
    value = round(r);//��������
    //��֤ȡֵ��Խ��
    if (value < a)
    {
        value = a;
    }
    if (b < value)
    {
        value = b;
    }

    return value;
}

//��ʼ����Ⱥ����
void initGroup(int &seed)// �˴�δ���� seed

{
    int i;
    int j;
    // double lbound;
    // double ubound;
    // 
    //  initGroup variables within the bounds 
    //
    for (i = 0; i < N_VARS; i++)// �� x �� y
    {
        //input >> lbound >> ubound;

        for (j = 0; j < GROUP_SCALE; j++)
        {
            Population[j].Fitness = 0;
            Population[j].ReFitness = 0;
            Population[j].SumFitness = 0;
            Population[j].Xn[i] = randT(XnRange[i].Lower, XnRange[i].Upper);
            //Population[j].Xn[i] = r8_uniform_ab(XnRange[i].Lower, XnRange[i].Upper, seed);
        }
    }

    return;
}


//��ѡ�����ֵ����������Ⱥ��������һ��λ��
void selectBest()// ֱ���ҳ���Ӧֵ���� ��������
{
    int cur_best;
    int mem;
    int i;

    cur_best = 0;

    for (mem = 0; mem < GROUP_SCALE; mem++)
    {
        if (Population[GROUP_SCALE].Fitness < Population[mem].Fitness)
        {
            cur_best = mem;
            Population[GROUP_SCALE].Fitness = Population[mem].Fitness;
        }
    }

    for (i = 0; i < N_VARS; i++)
    {
        Population[GROUP_SCALE].Xn[i] = Population[cur_best].Xn[i];
    }

    return;
}

//�������
void mutate(int &seed)// seed ��ʱû����
{
    const double a = 0.0;
    const double b = 1.0;
    int i;
    int j;
    double lbound;
    double ubound;
    double x;

    for (i = 0; i < GROUP_SCALE; i++)
    {
        for (j = 0; j < N_VARS; j++)
        {
            //x = r8_uniform_ab(a, b, seed);
            x = randT(a, b);// �������ͻ�����
            if (x < P_MUTATION)// ����ͻ��
            {
                lbound = XnRange[j].Lower;// ���������½�
                ubound = XnRange[j].Upper;// ���������Ͻ�
                Population[i].Xn[j] = randT(lbound, ubound);// ����Ϊһ�������ڵ����ֵ
                //Population[i].Xn[j] = r8_uniform_ab(lbound, ubound, seed);
            }
        }
    }

    return;
}

//ģ�庯�����������ɸ��������ϵ���������
template<typename T>
T randT(T Lower, T Upper)
{// YEs��
    return rand() / (double)RAND_MAX *(Upper - Lower) + Lower;
}

//����С�������
double r8_uniform_ab(double a, double b, int &seed)// �������̶�û�õ���

{
    int i4_huge = 2147483647;
    int k;
    double value;

    if (seed == 0)
    {
        cerr << "\n";
        cerr << "R8_UNIFORM_AB - Fatal error!\n";
        cerr << "  Input value of SEED = 0.\n";
        exit(1);
    }

    k = seed / 127773;
    seed = 16807 * (seed - k * 127773) - k * 2836;

    if (seed < 0)
    {
        seed = seed + i4_huge;
    }

    value = (double)(seed)* 4.656612875E-10;

    value = a + (b - a) * value;

    return value;
}

//���ÿһ�������Ľ��
void report(int Xnration)
{
    double avg;
    double best_val;
    int i;
    double square_sum;
    double stddev;
    double sum;
    double sum_square;

    if (Xnration == 0)
    {
        cout << "\n";
        cout << "  Xnration       Best            Average       Standard \n";
        cout << "  number           value           Fitness       deviation \n";
        cout << "\n";
    }
    sum = 0.0;
    sum_square = 0.0;

    for (i = 0; i < GROUP_SCALE; i++)
    {
        sum = sum + Population[i].Fitness;
        sum_square = sum_square + Population[i].Fitness * Population[i].Fitness;
    }

    avg = sum / (double)GROUP_SCALE;
    Best_Ave_Fitness = max(Best_Ave_Fitness, avg);
    square_sum = avg * avg * GROUP_SCALE;
    stddev = sqrt((sum_square - square_sum) / (GROUP_SCALE - 1));
    best_val = Population[GROUP_SCALE].Fitness;

    cout << "  " << setw(8) << Xnration
        << "  " << setw(14) << best_val
        << "  " << setw(14) << avg
        << "  " << setw(14) << stddev << "\n";

    return;
}

//ѡ���н���Ȩ�ĸ���
void selector(int &seed)
{
    struct Individual NewPopulation[GROUP_SCALE + 1];//��ʱ�����ѡ�ĺ������
    const double a = 0.0;
    const double b = 1.0;
    int i;
    int j;
    int mem;
    double p;
    double sum;

    sum = 0.0;
    for (mem = 0; mem < GROUP_SCALE; mem++)
    {
        sum = sum + Population[mem].Fitness;
    }
    //��������ܶ�
    for (mem = 0; mem < GROUP_SCALE; mem++)
    {
        Population[mem].ReFitness = Population[mem].Fitness / sum;
    }
    // �����ۼӷֲ���˼�������̷�
    Population[0].SumFitness = Population[0].ReFitness;
    for (mem = 1; mem < GROUP_SCALE; mem++)
    {
        Population[mem].SumFitness = Population[mem - 1].SumFitness +
            Population[mem].ReFitness;
    }
    // ѡ�����Ϊ��һ����ֳ��ѡ������Ŀ����Դ��������̷��İ���֮��
    for (i = 0; i < GROUP_SCALE; i++)
    {
        p = r8_uniform_ab(a, b, seed);
        if (p < Population[0].SumFitness)
        {
            NewPopulation[i] = Population[0];
        }
        else
        {
            for (j = 0; j < GROUP_SCALE; j++)
            {
                if (Population[j].SumFitness <= p && p < Population[j + 1].SumFitness)
                {
                    NewPopulation[i] = Population[j + 1];
                }
            }
        }
    }
    //���º������ 
    for (i = 0; i < GROUP_SCALE; i++)
    {
        Population[i] = NewPopulation[i];
    }
    return;
}

////��ʾϵͳʱ��
//void showTime()
//{
//# define TIME_SIZE 40
//
//    static char time_buffer[TIME_SIZE];
//    const struct tm *tm;
//    size_t len;
//    time_t now;
//
//    now = time(NULL);
//    tm = localtime(&now);
//
//    len = strftime(time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm);
//
//    cout << time_buffer << "\n";
//
//    return;
//# undef TIME_SIZE
//}

//��������Ӵ�
void Xover(int one, int two, int &seed)
{
    int i;
    int point;
    double t;
    //���ѡ�񽻲�㣬����ĵ����Ա�������������Ϊ��λ
    point = randT<int>(0, N_VARS - 1);
    //point = i4_uniform_ab(0, N_VARS - 1, seed);
    //����
    for (i = 0; i < point; i++)
    {
        t = Population[one].Xn[i];
        Population[one].Xn[i] = Population[two].Xn[i];
        Population[two].Xn[i] = t;
    }
    return;
}