#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

//二十四点问题
//题目描述
//一个游戏由4个1-9的数字和3个四则运算符组成，注意运算顺序。
//除法是整除

//输入：
//n 题目个数
//2-n+1行 每行：
//符合上述描述的二十四点问题

//输出：
//对于每个游戏，结果为24，输出Yes，否则输出No.

//检查点：
// n==100，无需考虑类型问题

//思路：
//难点在于考虑优先级...
//迭代N次，每次cin num1-4  oper1-3;
//然而，实际上运算符只分为两类，+=和x/，分别用0，1编码，情况只有8种而已...
//可以暴力破解...

//或者，将运算符保存在数组中，检查整个数组在优先级上是否是递减的，如果是，顺序计算。
//如果不是，则只有010 001 011 101 四种情况。再暴力破解即可。 

//使用思路二。 

//一遍过，这题目有够烦的。
 
int getOut(int num1,int num2,char oper){
	if(oper=='+')return num1+num2;
	if(oper=='-')return num1-num2;
	if(oper=='x')return num1*num2;
	if(oper=='/')return num1/num2;
	
	return 0;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int outPut=0;
		//数组创建放在循环里，有没有问题呢？ 没有，应该是自动释放的。 
		int operArray[3]={0};
		int num1,num2,num3,num4;
		char oper1,oper2,oper3;
		cin>>num1>>oper1>>num2>>oper2>>num3>>oper3>>num4;
		if(oper1=='x'||oper1=='/')operArray[0]=1;
		if(oper2=='x'||oper2=='/')operArray[1]=1;
		if(oper3=='x'||oper3=='/')operArray[2]=1;
		
		
		if(operArray[0]>=operArray[1]&&operArray[1]>=operArray[2]){
			//顺序执行
			outPut=getOut(getOut(getOut(num1,num2,oper1),num3,oper2),num4,oper3);
		}
		else{
			//010 001 011 101 
			
			//1*2-3/4
			if(operArray[0]==0 && operArray[1]==1 && operArray[2]==0)outPut=getOut(getOut(num1,getOut(num2,num3,oper2),oper1),num4,oper3);
			
			if(operArray[0]==0 && operArray[1]==0 && operArray[2]==1)outPut=getOut(getOut(num1,num2,oper1),getOut(num3,num4,oper3),oper2);
			
			if(operArray[0]==0 && operArray[1]==1 && operArray[2]==1)outPut=getOut(num1,getOut(getOut(num2,num3,oper2),num4,oper3),oper1);
			
			if(operArray[0]==1 && operArray[1]==0 && operArray[2]==1)outPut=getOut(getOut(num1,num2,oper1),getOut(num3,num4,oper3),oper2);
		}
		
		if(outPut==24)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	
	
	
	
	return 0;
	
} 
