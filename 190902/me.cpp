#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//����
//N ƻ�����ĸ���
// ����N�� ÿ�У�
// ֮�����ֵĸ���m  ͳ��ƻ������m1  ֮��m-1�� ÿ�
// ��Ϊ���� ˵��С������ͳ���˸�����ƻ������
// ��Ϊ0/���� ��������� 

//���
// T��ƻ������ʣ���ƻ������
// D������ƻ�������ƻ�����Ŀ���
// E����������������ƻ����������������� 
//ע��ƻ�����ǻ��ε�
//������ֽ�����Եõ����ַ�����

//���㣺
// N��1000 m��ִ�в����Ĵ����������ֵҲ1000
 // ƻ��������10**6��ͳ�ƺ����long long
 
//˼·��
//T����ÿ�н��������
//thisSum,�ж�thisloop��Ϊ�����滻����������ӡ�thisloop����m��
//thisSum,�ж�thisloop������������������d��һ������dflag�����ڵ�ǰ���������ӡ�
//����dropArray���洢����ƻ�������ı�š�
//����dropArray����Ҫ���飬��E++�� 
/*�������ݣ�
4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0
*/
//�����
// 222 1 0
 
//һ��������⣿ 

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
	
	//E �������������N
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
