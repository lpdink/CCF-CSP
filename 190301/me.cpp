#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

#define MAX 100000000

//��Ŀ����
//n���������ɵ����ݣ��������򡢿��ܽ��򡢿��ܴ����ظ�����
//�������С����λ�������մӴ�С���

//����
//n
//n���������� 

//���
//�����������������
//��Ϊ����������������뱣��1λС���Ľ���� 

//���� n<=10**5 ����ֱ�������� 
//��������С�ڵ���10**7������Int. 

//˼·��
//�����С�������ߴ���
// ��������array�������е�ֵ��
// �ж�n������/ż������Ϊ��������λ������n/2���ɡ�
// ��Ϊż����ȡn/2-1 ��n/2֮��/2�����ж�n/2-1��n/2�Ƿ�һ��������һ��ż��
// ����ǣ�����λ��+1���ء�  

//���...ֻ��80�֣����������أ�
//��Ŀ�����ˣ���Ҫ���������뱣��һλС�������ǵ������� 
//���⣬����double num=(num1+num2)/2�����num1��num2�������͵ģ��㲻���ڴ�num�Ǹ���������Ľ���������޸�2Ϊ2.0.

//����û�������ˡ�
//��Ȼ�������������е������ԣ��������ж�����״̬��ֱ�ӷ������/��Сֵ�������Ż��㷨
//���Ǻα��أ�ͨ���ͺ���/Ц 
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
