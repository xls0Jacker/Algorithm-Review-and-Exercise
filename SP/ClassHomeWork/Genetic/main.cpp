#include <iostream>
#include "Genetic.hpp"
#include "math.h"

extern Individual Population[GROUP_SCALE + 1];
extern double Best_Ave_Fitness;

int main()
{
    int Xnration;
    int i;
    int seed = 123456789;

    //showTime();
    initGroup(seed);// 初始化种群
    evaluate();// 计算适应值
    selectBest();

    for (Xnration = 0; Xnration < MAX_GENS; Xnration++)// 迭代 代数
    {
        selector(seed);// 选择
        crossover(seed);// 交叉
        mutate(seed);// 变异
        report(Xnration);// 输出结果
        evaluate();// 计算新的适应度
        elitist();// 选择最好的基因替代最差的
    }

    cout << "\n";
    cout << "  Best member after " << MAX_GENS << " Xnrations:\n";
    cout << "\n";

    for (i = 0; i < N_VARS; i++)
    {
        cout << "  X(" << i + 1 << ") = " << Population[GROUP_SCALE].Xn[i] << "\n";
		//cout << "  fit  = " << cos(Population[GROUP_SCALE].Xn[i])<< "\n";

    }
    cout << "\n";
    cout << "  Best Fitness = " << Population[GROUP_SCALE].Fitness << "\n";

    cout << "\n";
    cout << "  Best Ave_Fitness = " << Best_Ave_Fitness << "\n";

    //showTime();
    system("pause");
    return 0;
}