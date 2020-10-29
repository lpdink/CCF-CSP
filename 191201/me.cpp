#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

//四人从1开始报数 遇到含有7或是7的倍数的情况跳过。
//输入n是报了n个数后游戏结束（不计入跳过的数）
//求四个人跳过的次数
//n最多是一个百位数。 

//思路：
//设置count记录已经报了多少数
//设置nowNum从1开始不断增加，使用while循环，当 count小于n时循环（等于时跳出）
//设置数组output存储四个人的跳过。 
//判断nowNum是否是7的倍数，或者含有7.

//7的倍数：
//%7，结果为0.

//含有7：
//由检查点，考虑十位和百位的情况，分段依据是：>10 <100; >100 


//结果：
//编译运行都一遍过，我还是挺细心的嘛... 
bool multiOrContain7(int nowNum){
	if(nowNum%7==0){
		return true;
	}
	
	if(nowNum<10){
		return false;
	}
	else if(nowNum>=10 && nowNum<100){
		int num1=nowNum%10;
		int num10=nowNum/10;
		if(num1==7||num10==7)return true;
		else return false;
	}
	else if(nowNum>=100){
		int num1=nowNum%10;
		int num10=nowNum/10%10;
		int num100=nowNum/100;
		if(num1==7||num10==7||num100==7)return true;
		else return false;
	}
	
	return false;
}
int main(){
	int n;
	cin>>n;
	int count=0,nowNum=1;
	int output[4]={0,0,0,0};
	int flag=0;//当前到谁了？ 
	while(count<n){
		if(multiOrContain7(nowNum)){
			output[flag]++;
		}
		else{
			count++;
		}
		flag++;
		if(flag==4)flag=0; 
		nowNum++;
	} 
	for(int i=0;i<4;i++){
		cout<<output[i]<<endl;
	}
	
	
	return 0;
}
