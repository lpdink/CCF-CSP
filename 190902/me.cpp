#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//输入
//N 苹果树的个数
// 下面N行 每行：
// 之后数字的个数m  统计苹果总数m1  之后m-1个 每项：
// 若为正数 说明小明重新统计了该树的苹果个数
// 若为0/负数 进行了疏果 

//输出
// T：苹果树上剩余的苹果总数
// D：发生苹果掉落的苹果树的棵树
// E：连续三棵树发生苹果掉落情况的组数。 
//注：苹果树是环形的
//输出部分结果可以得到部分分数。

//检查点：
// N《1000 m（执行操作的次数）的最大值也1000
 // 苹果最大个数10**6，统计和最好long long
 
//思路：
//T，在每行结束后更新
//thisSum,判断thisloop，为正则替换，其他则相加。thisloop迭代m。
//thisSum,判断thisloop，相等则继续，不等则d加一，设置dflag，对于当前树不再增加。
//设置dropArray，存储掉落苹果的树的编号。
//遍历dropArray，按要求检查，对E++； 
/*测试数据：
4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0
*/
//结果：
// 222 1 0
 
//一遍过，就这？ 

int main(){
	long long T=0;
	int D=0,E=0,N;
	cin>>N;
	int dropArray[1001]={0};
	
	for(int i=1;i<=N;i++){
		int m;
		cin>>m;
		bool dflag=true;
		long long thisSum=0;
		for(int k=0;k<m;k++){
			int thisloop;
			cin>>thisloop;
			if(k==0)thisSum=thisloop;
			if(thisloop>0){
				if((thisSum!=thisloop)&&dflag){
				D++;
				dflag=false;
				dropArray[i]=1;
				}
				thisSum=thisloop;
			}
			else{
				thisSum+=thisloop;
			}
		}
		T+=thisSum;
	}
	
	//E 数组最大索引是N
	for(int i=1;i<=N;i++){
		if(i==N){
			if(dropArray[i]&&dropArray[1]&&dropArray[2])E++;
		}
		else if(i==N-1){
			if(dropArray[i]&&dropArray[i+1]&&dropArray[1])E++;
		}
		else{
			if(dropArray[i]&&dropArray[i+1]&&dropArray[i+2])E++;
		}
	}
	
	cout<<T<<" "<<D<<" "<<E<<endl;
	
	
	return 0;
} 
