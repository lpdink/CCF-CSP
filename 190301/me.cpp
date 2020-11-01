#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

#define MAX 100000000

//题目描述
//n个整数构成的数据，可能升序、可能降序、可能存在重复数据
//求最大、最小、中位数，按照从大到小输出

//输入
//n
//n个有序整数 

//输出
//对于整数，输出整数
//若为分数，输出四舍五入保留1位小数的结果。 

//检查点 n<=10**5 可以直接声明？ 
//测试数据小于等于10**7，可以Int. 

//思路：
//最大最小可以在线处理
// 设置数组array保留所有的值。
// 判断n是奇数/偶数？若为奇数，中位数返回n/2即可。
// 若为偶数，取n/2-1 和n/2之和/2。且判断n/2-1和n/2是否一个奇数，一个偶数
// 如果是，令中位数+1返回。  

//奇怪...只有80分，问题在哪呢？
//题目看错了，它要求四舍五入保留一位小数，不是到整数。 
//此外，对于double num=(num1+num2)/2，如果num1和num2都是整型的，你不能期待num是浮点数计算的结果，必须修改2为2.0.

//现在没有问题了。
//当然，由于输入序列的有序性，可以在判定序列状态后直接返回最大/最小值，可以优化算法
//但是何必呢，通过就好啦/笑 
int main(){
	int theMax=-MAX,theMin=MAX;
	int array[100000]={0};
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int thisNum;
		cin>>thisNum;
		if(thisNum>theMax)theMax=thisNum;
		if(thisNum<theMin)theMin=thisNum;
		array[i]=thisNum;
	}
	
	//theMed
	if(n%2==1){
		int theMed=array[n/2];
		printf("%d %d %d\n",theMax,theMed,theMin);
	}
	else{
		int num1=array[n/2-1];
		int num2=array[n/2];
		if((num1%2==1&&num2%2==0)||(num1%2==0&&num2%2==1)){
			double theMed=(num1+num2)/2.0;
			printf("%d %.1f %d\n",theMax,theMed,theMin);
		}
		else{
			int theMed=(num1+num2)/2;
			printf("%d %d %d\n",theMax,theMed,theMin);
		}
	}
	
	
	
	
	return 0;
}
