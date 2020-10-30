#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//n处垃圾，i处的坐标是xi,yi  整数
//要求十字中心可以作为垃圾处
//对每个垃圾处，四个对角有几处有垃圾，即得几分。 
//统计五种得分的垃圾处个数

//输入
//n
//坐标  n行 保证不一致

//思路：避免使用二维数组， 采用类似压缩矩阵的方法，时间换空间。 
//忘记保存刚才得了50分的了...大致思路是用矩阵存储整个点阵，问题在于声明10**9的二维数组不实际。 

//注意声明long long  

 /*测试数据 
 7
1 2
2 1
0 0
1 1
1 0
2 0
0 1
*/
// 00100


int main(){
	int n;
	cin>>n;
	long long xArray[1002]={0},yArray[1002]={0};
	long long x,y;
	long long xk,yk;
	int numOfKinds[5]={0};
	for(int i=0;i<n;i++){
		cin>>x>>y;
		xArray[i]=x;
		yArray[i]=y;
	}
	for(int i=0;i<n;i++){
		bool isDump=false;
		x=xArray[i];y=yArray[i];
		int flag=4;
		for(int k=0;k<n;k++){
			xk=xArray[k];yk=yArray[k];
			if( (x-1==xk) && (y==yk) )flag--;
			if( (x+1==xk) && (y==yk) )flag--;
			if( (x==xk) && (y-1==yk) )flag--;
			if( (x==xk) && (y+1==yk) )flag--;
		}
		if(flag==0)isDump=true;
		//if(dArray[x-1][y]&&dArray[x+1][y]&&dArray[x][y-1]&&dArray[x][y+1])isDump=true;
		
		if(isDump){
			//int thisKind=dArray[x-1][y-1]+dArray[x-1][y+1]+dArray[x+1][y-1]+dArray[x+1][y+1];
			int thisKind=0;
			for(int k=0;k<n;k++){
			xk=xArray[k];yk=yArray[k];
			if( (x-1==xk) && (y-1==yk) )thisKind++;
			if( (x+1==xk) && (y-1==yk) )thisKind++;
			if( (x-1==xk) && (y+1==yk) )thisKind++;
			if( (x+1==xk) && (y+1==yk) )thisKind++;
			}
			numOfKinds[thisKind]++;
		}
	}
	
	for(int i=0;i<5;i++){
		cout<<numOfKinds[i]<<endl;
	}
	
	
	return 0;
} 
