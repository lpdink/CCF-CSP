#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

//���˴�1��ʼ���� ��������7����7�ı��������������
//����n�Ǳ���n��������Ϸ����������������������
//���ĸ��������Ĵ���
//n�����һ����λ���� 

//˼·��
//����count��¼�Ѿ����˶�����
//����nowNum��1��ʼ�������ӣ�ʹ��whileѭ������ countС��nʱѭ��������ʱ������
//��������output�洢�ĸ��˵������� 
//�ж�nowNum�Ƿ���7�ı��������ߺ���7.

//7�ı�����
//%7�����Ϊ0.

//����7��
//�ɼ��㣬����ʮλ�Ͱ�λ��������ֶ������ǣ�>10 <100; >100 


//�����
//�������ж�һ������һ���ͦϸ�ĵ���... 
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
	int flag=0;//��ǰ��˭�ˣ� 
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
