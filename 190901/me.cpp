#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//输入： 
//N  M  苹果树的棵树  疏果操作的轮数  
//接下来N行 每行 M+1个整数 对应：0：原来果树上苹果的个数 轮疏果的个数 为负整数或0  

//输出：在一行内 空格分隔。 
// T：最后一轮执行后，树上剩余的苹果总数
//k ：疏果最多的苹果树编号 如果有相同的，输出最小编号， 
//P：该树的疏果个数

//检查点：
//M和N均小于等于1k.可以使用图方法存储
//值小于10**6，可以使用Int,但是求其和，建议ll 
 

//思路：
//  由于题目要求的特点，可以在线处理，而不必等待全部数据。 
//  设置allSum 加所有的输入，输出为T。
//  设置shuguoMax 减当前行的疏果输入 记录最大疏果数量输出为P 设置record 记录当前树的标号. 输出为k。 

//用ll没太大的坏处，不是吗？ 、

//一遍过，题目还是很简单的。 
int main(){
	int N,M;
	cin>>N>>M;
	long long allSum=0;
	long long shuguoMax=0;
	int record=-1; 
	for(int i=1;i<=N;i++){
		long long thisTreeSum;
		cin>>thisTreeSum;
		allSum+=thisTreeSum; 
		int shuguoSum=0;
		for(int k=1;k<=M;k++){
			int thisScoop;
			cin>>thisScoop;
			shuguoSum-=thisScoop;
			allSum+=thisScoop;
		}
		if(shuguoSum>shuguoMax){
			shuguoMax=shuguoSum;
			record=i;
		}
	}
	cout<<allSum<<" "<<record<<" "<<shuguoMax<<endl;
	
	
	return 0;
} 
