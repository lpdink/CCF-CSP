#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//问题描述
//小明上学问题，当年做过这道题目，真是令人怀念啊
//遇到红灯和黄灯要等待，红灯等待剩余时间，黄灯等待剩余时间+红灯最大时间 
//绿灯的剩余时间是无用的 
 
//输入：
// r,y,g 红，黄，绿灯的最长时间
// n 经过的路段数+见到的红绿灯数目
// 接下来的N行
// k=0为道路，直接加后面的时间 
// k=1为红灯 直接加后面的时间
// k=2为黄灯 加后面的时间，再加r
// k=3为绿灯，忽视。

//输出
//小明上学的时间t

//检查点：
//rgy：10**6， n<=100，无需考虑范围

//思路：
//按照输入中描述的思路。 

//评价：
//白给，兴许是当年需要人脑编译 

int main(){
	int r,y,g,n;
	cin>>r>>y>>g;
	cin>>n;
	int theTime=0;
	for(int i=0;i<n;i++){
		int k;
		int thisTime;
		cin>>k;
		cin>>thisTime;
		if(k==0) theTime+=thisTime;
		if(k==1) theTime+=thisTime;
		if(k==2) theTime+=thisTime+r;
	}
	cout<<theTime<<endl;
	
	
	
	return 0;
} 
