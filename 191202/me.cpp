#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//n��������i����������xi,yi  ����
//Ҫ��ʮ�����Ŀ�����Ϊ������
//��ÿ�����������ĸ��Խ��м��������������ü��֡� 
//ͳ�����ֵ÷ֵ�����������

//����
//n
//����  n�� ��֤��һ��

//˼·������ʹ�ö�ά���飬 ��������ѹ������ķ�����ʱ�任�ռ䡣 
//���Ǳ���ղŵ���50�ֵ���...����˼·���þ���洢��������������������10**9�Ķ�ά���鲻ʵ�ʡ� 

//ע������long long  

 /*�������� 
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
