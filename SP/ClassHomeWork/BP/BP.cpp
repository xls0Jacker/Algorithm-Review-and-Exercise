#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <time.h>
#include <stdlib.h> 
#include <algorithm>

using namespace std;

#define train_cycle 2000	//训练周期为1000 
#define train_step 0.3		//训练步长
#define train_num 10		//训练数字数量
#define table_len 9			//表格长
#define table_wid 7			//表格宽
#define max_lim 0.9			//输出最大临界值	
#define min_lim 0.1			//输出最小临界值
#define input_num 63		//输入层神经元数
#define hidden_num 30		//隐层神经元数
#define output_num 10		//输出层神经元数

#define disturb 0.1  //数字模糊的程度

struct input_neurons {
	//	double inp;
	double outp;
	double w[hidden_num];
}input_n[input_num];

struct hidden_neurons {
	double inp;
	double outp;
	double w[output_num];
}hidden_n[hidden_num];

struct output_neurons {
	double inp;
	double outp;
}output_n[output_num];

//训练数据
bool trainData[train_num][table_len][table_wid] = {
	0,0,0,0,0,0,0,		//真实数字0
	0,1,1,1,1,1,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,		//0
	0,0,0,0,0,0,0,		//1
	0,0,0,1,0,0,0,
	0,0,1,1,0,0,0,
	0,0,0,1,0,0,0,
	0,0,0,1,0,0,0,
	0,0,0,1,0,0,0,
	0,0,0,1,0,0,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,		//1
	0,0,0,0,0,0,0,		//2
	0,1,1,1,1,1,0,
	0,0,0,0,0,1,0,
	0,0,0,0,0,1,0,
	0,1,1,1,1,1,0,
	0,1,0,0,0,0,0,
	0,1,0,0,0,0,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,		//2
	0,0,0,0,0,0,0,		//3
	0,1,1,1,1,1,0,
	0,0,0,0,0,1,0,
	0,0,0,0,0,1,0,
	0,0,0,1,1,1,0,
	0,0,0,0,0,1,0,
	0,0,0,0,0,1,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,		//3
	0,0,0,0,0,0,0,		//4
	0,1,0,0,0,0,0,
	0,1,0,0,0,0,0,
	0,1,0,0,1,0,0,
	0,1,1,1,1,1,0,
	0,0,0,0,1,0,0,
	0,0,0,0,1,0,0,
	0,0,0,0,1,0,0,
	0,0,0,0,0,0,0,		//4
	0,0,0,0,0,0,0,		//5
	0,1,1,1,1,1,0,
	0,1,0,0,0,0,0,
	0,1,0,0,0,0,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,1,0,
	0,0,0,0,0,1,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,		//5
	0,0,0,0,0,0,0,		//6
	0,1,1,1,1,1,0,
	0,1,0,0,0,0,0,
	0,1,0,0,0,0,0,
	0,1,1,1,1,1,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,		//6
	0,0,0,0,0,0,0,		//7
	0,1,1,1,1,1,0,
	0,0,0,0,0,1,0,
	0,0,0,0,1,0,0,
	0,0,0,1,0,0,0,
	0,0,1,0,0,0,0,
	0,1,0,0,0,0,0,
	0,1,0,0,0,0,0,
	0,0,0,0,0,0,0,		//7
	0,0,0,0,0,0,0,		//8
	0,1,1,1,1,1,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,
	0,1,1,1,1,1,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,		//8
	0,0,0,0,0,0,0,		//9
	0,1,1,1,1,1,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,1,0,
	0,0,0,0,0,1,0,
	0,0,0,0,0,1,0,
	0,0,0,0,0,0,0		//9
};
bool testData[train_num][table_len][table_wid] = {
	0,0,0,0,0,0,0,		//0
	0,1,1,0,1,1,0,
	0,1,0,0,0,0,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,		//0
	0,0,0,0,0,0,0,		//1
	0,0,0,1,0,0,0,
	0,0,0,1,0,0,0,
	0,0,0,0,0,0,0,
	0,0,0,1,0,0,0,
	0,0,0,1,0,0,0,
	0,0,0,1,0,0,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,		//1
	0,0,0,0,0,0,0,		//2
	0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,
	0,0,0,0,0,1,0,
	0,1,0,1,1,1,0,
	0,1,0,0,0,0,0,
	0,1,0,0,0,0,0,
	0,0,1,1,1,1,0,
	0,0,0,0,0,0,0,		//2
	0,0,0,0,0,0,0,		//3
	0,1,1,0,1,1,0,
	0,0,0,0,0,1,0,
	0,0,0,0,0,1,0,
	0,0,0,1,1,1,0,
	0,0,0,0,0,1,0,
	0,0,0,0,0,1,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,		//3
	0,0,0,0,0,0,0,		//4
	0,1,0,0,0,0,0,
	0,1,0,0,0,0,0,
	0,1,0,0,1,0,0,
	0,0,1,1,1,1,0,
	0,0,0,0,0,0,0,
	0,0,0,0,1,0,0,
	0,0,0,0,1,0,0,
	0,0,0,0,0,0,0,		//4
	0,0,0,0,0,0,0,		//5
	0,1,1,1,1,0,0,
	0,1,0,0,0,0,0,
	0,1,0,0,0,0,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,1,0,
	0,0,0,0,0,0,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,		//5
	0,0,0,0,0,0,0,		//6
	0,1,0,1,1,1,0,
	0,1,0,0,0,0,0,
	0,1,0,0,0,0,0,
	0,1,1,1,1,0,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,		//6
	0,0,0,0,0,0,0,		//7
	0,1,0,1,1,1,0,
	0,0,0,0,0,1,0,
	0,0,0,0,1,0,0,
	0,0,0,1,0,0,0,
	0,0,1,0,0,0,0,
	0,1,0,0,0,0,0,
	0,1,0,0,0,0,0,
	0,0,0,0,0,0,0,		//7
	0,0,0,0,0,0,0,		//8
	0,1,0,1,1,1,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,0,0,
	0,1,1,1,1,1,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,		//8
	0,0,0,0,0,0,0,		//9
	0,1,1,1,0,1,0,
	0,1,0,0,0,1,0,
	0,0,0,0,0,1,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,1,0,
	0,0,0,0,0,1,0,
	0,0,0,0,0,1,0,
	0,0,0,0,0,0,0		//9
};


//期望值
double y[train_num][output_num] = {
	1,0,0,0,0,0,0,0,0,0,	//0的期望值
	0,1,0,0,0,0,0,0,0,0,	//1的期望值
	0,0,1,0,0,0,0,0,0,0,	//2的期望值
	0,0,0,1,0,0,0,0,0,0,	//3的期望值
	0,0,0,0,1,0,0,0,0,0,	//4的期望值
	0,0,0,0,0,1,0,0,0,0,	//5的期望值
	0,0,0,0,0,0,1,0,0,0,	//6的期望值
	0,0,0,0,0,0,0,1,0,0,	//7的期望值
	0,0,0,0,0,0,0,0,1,0,	//8的期望值
	0,0,0,0,0,0,0,0,0,1		//9的期望值
};

//输出存放数组
double ans[output_num];

//sigmoid函数
double sigmoid(double x) {
	return 1 / (1 + exp(-x));
}
//sigmoid导函数
double sigmoid_der(double x) {
	return sigmoid(x)*(1 - sigmoid(x));
}

//tansig函数
double sigmoid0(double x) {
  return 2 / (1 + exp(-2 * x)) - 1;
}

// tansig导函数
double sigmoid_der0(double x) {
  return 4 * exp(-2 * x) / ((1 + exp(-2 * x) + 1) * (1 + exp(-2 * x) + 1));
}

//生成扰动的数字
/*bool *gen_num(int num){
	bool *genData;
	genData=testData[num][table_len][table_wid];
	int i,j;
	for ( i = 0; i < table_len; i++) {
		for (j = 0; j < table_wid; j++) {
			int s=rand()%100;//产生0-100随机数
			if (s<10)
				genData[num][i][j]=0;
		}
	}
	return genData;
}*/

//产生一个[-1,1]的随机数 
double pro_decimal() {
	double r = rand() % 200 - 100;
	double c = r / 100;
	return c;
}
//初始化神经网络各节点权值
void init_w() {
	/*	memset(input_ans, 0, sizeof(input_ans));
		memset(hidden_ans, 0, sizeof(hidden_ans));*/
	int i,j;
	memset(ans, 0, sizeof(ans));
	for (i = 0; i < input_num; i++) {
		for (j = 0; j < hidden_num; j++) {
			input_n[i].w[j] = pro_decimal();
		}
	}
	for (i = 0; i < hidden_num; i++) {
		for (j = 0; j < output_num; j++) {
			hidden_n[i].w[j] = pro_decimal();
		}
	}
	//	cout << "test" << endl;
}

//神经网络运行
void NN_run(bool(*NN_input)[table_wid]) {
	//初始化神经网络输入值
    int i,j;
	for (i = 0; i < hidden_num; i++) {
		hidden_n[i].inp = 0;
	}
	for (i = 0; i < output_num; i++) {
		output_n[i].inp = 0;
	}
	//输入数据
	for (i = 0; i < table_len; i++) {
		for (j = 0; j < table_wid; j++) {
			input_n[i*table_wid + j].outp = sigmoid0(NN_input[i][j]);
		}
	}
	//数据传递
	for (i = 0; i < hidden_num; i++) {
		for (j = 0; j < input_num; j++) {
			hidden_n[i].inp += input_n[j].outp*input_n[j].w[i];
		}
	}
	for (i = 0; i < hidden_num; i++) {
		hidden_n[i].outp = sigmoid0(hidden_n[i].inp);
	}
	for (i = 0; i < output_num; i++) {
		for (j = 0; j < hidden_num; j++) {
			output_n[i].inp += hidden_n[j].outp*hidden_n[j].w[i];
		}
	}
	for (i = 0; i < output_num; i++) {
		output_n[i].outp = sigmoid0(output_n[i].inp);
		ans[i] = output_n[i].outp;
		if (ans[i] >= max_lim) ans[i] = 1;
		if (ans[i] <= min_lim) ans[i] = 0;
	}
}

//返回是否训练好
bool if_accomplish() {
	for (int num = 0; num < train_num; num++) {
		NN_run(trainData[num]);
		for (int i = 0; i < output_num; i++) {
			double flag = 0;
			if (i == num)	flag = 1;
			if (ans[i] != flag) {
				return false;
			}
		}
	}
	return true;
}
void BP_study() {
	double d_output[output_num];
	double d_hidden[hidden_num];
	int i,j;
	for (int cycle = 0; cycle < train_cycle; cycle++) {
		if (if_accomplish()) {
			cout << "训练完成啦！！！" << endl;
			cout << "输入层与隐层之间的权值" << endl;
			for (int i = 0; i < input_num; i++) {
				for (int j = 0; j < hidden_num; j++) {
					printf("%.2f ", input_n[i].w[j]);
				}
				cout << endl;
			}
			cout << "隐层与输出层之间的权值" << endl;
			for (i = 0; i < hidden_num; i++) {
				for (j = 0; j < output_num; j++) {
					printf("%.2f ", hidden_n[i].w[j]);
				}
				cout << endl;
			}
			return;
		}
		for (int train_no = 0; train_no < train_num; train_no++) {
			NN_run(trainData[train_no]);
			memset(d_output, 0, sizeof(d_output));
			memset(d_hidden, 0, sizeof(d_hidden));
			//计算输出层误差信号(书P218-8.17b)
			for (i = 0; i < output_num; i++) {
				d_output[i] = sigmoid_der0(ans[i])*(ans[i] - y[train_no][i]);
			}
			//计算隐层误差信号(书P218-8.18b)
			for (i = 0; i < hidden_num; i++) {
				for (j = 0; j < output_num; j++) {
					d_hidden[i] += d_output[j] * hidden_n[i].w[j];
				}
				d_hidden[i] *= sigmoid_der0(hidden_n[i].outp);
			}
			//更新隐层和输出层之间的权重(书P218-8.16b)
			for (i = 0; i < output_num; i++) {
				for ( j = 0; j < hidden_num; j++) {
					hidden_n[j].w[i] -= train_step * d_output[i] * hidden_n[j].outp;
				}
			}
			//更新输入层和隐层之间的权重(书P218-8.16b)
			for (i = 0; i < hidden_num; i++) {
				for ( j = 0; j < input_num; j++) {
					input_n[j].w[i] -= train_step * d_hidden[i] * input_n[j].outp;
				}
			}
		}
	}
	return;
}

//神经网络输出
void NN_print() {
	int x;
	int i,j;
	bool genData[train_num][table_len][table_wid];
	cout << "请在0-9中选择一个要测试的数字输入,输入-1结束:" << endl;
	while (cin >> x && x != -1) {
		for(int n=0;n<train_num;n++){
			for(i=0;i<table_len;i++){
				for(j=0;j<table_wid;j++){
					genData[n][i][j]=trainData[n][i][j];
						double s=((double)(rand()%RAND_MAX))/RAND_MAX;//产生0-1随机数
						if (s<disturb)
							genData[n][i][j]=0;
				}
			}
		}
	int i,j;

	 /*	
	 cout << "输入测试的数据图像为:" << endl;
		for ( i = 0; i < table_len; i++) {
			for (j = 0; j < table_wid; j++) {
				cout << testData[x][i][j] << " ";
			}
			cout << endl;
		}
		*/
		cout << "输入测试的数据图像为:" << endl;
		for ( i = 0; i < table_len; i++) {
			for (j = 0; j < table_wid; j++) {
				cout << genData[x][i][j] << " ";
			}
			cout << endl;
		}
		//NN_run(testData[x]);
		NN_run(genData[x]);
		double max = 0, maxi;
		for (i = 0; i < output_num; i++) {
			cout << "节点" << i << "输出概率为:" << ans[i] << endl;
			if (ans[i] > max) {
				max = ans[i];
				maxi = i;
			}
		}
		cout << "输入图像数字应该为" << maxi << endl << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));
	init_w();
	BP_study();
	NN_print();
}