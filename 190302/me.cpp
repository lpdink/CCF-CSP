#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

//��ʮ�ĵ�����
//��Ŀ����
//һ����Ϸ��4��1-9�����ֺ�3�������������ɣ�ע������˳��
//����������

//���룺
//n ��Ŀ����
//2-n+1�� ÿ�У�
//�������������Ķ�ʮ�ĵ�����

//�����
//����ÿ����Ϸ�����Ϊ24�����Yes���������No.

//���㣺
// n==100�����迼����������

//˼·��
//�ѵ����ڿ������ȼ�...
//����N�Σ�ÿ��cin num1-4  oper1-3;
//Ȼ����ʵ���������ֻ��Ϊ���࣬+=��x/���ֱ���0��1���룬���ֻ��8�ֶ���...
//���Ա����ƽ�...

//���ߣ�������������������У�����������������ȼ����Ƿ��ǵݼ��ģ�����ǣ�˳����㡣
//������ǣ���ֻ��010 001 011 101 ����������ٱ����ƽ⼴�ɡ� 

//ʹ��˼·���� 

//һ���������Ŀ�й����ġ�
 
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
		//���鴴������ѭ�����û�������أ� û�У�Ӧ�����Զ��ͷŵġ� 
		int operArray[3]={0};
		int num1,num2,num3,num4;
		char oper1,oper2,oper3;
		cin>>num1>>oper1>>num2>>oper2>>num3>>oper3>>num4;
		if(oper1=='x'||oper1=='/')operArray[0]=1;
		if(oper2=='x'||oper2=='/')operArray[1]=1;
		if(oper3=='x'||oper3=='/')operArray[2]=1;
		
		
		if(operArray[0]>=operArray[1]&&operArray[1]>=operArray[2]){
			//˳��ִ��
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
