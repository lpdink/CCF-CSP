#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//���룺 
//N  M  ƻ�����Ŀ���  �������������  
//������N�� ÿ�� M+1������ ��Ӧ��0��ԭ��������ƻ���ĸ��� ������ĸ��� Ϊ��������0  

//�������һ���� �ո�ָ��� 
// T�����һ��ִ�к�����ʣ���ƻ������
//k ���������ƻ������� �������ͬ�ģ������С��ţ� 
//P���������������

//���㣺
//M��N��С�ڵ���1k.����ʹ��ͼ�����洢
//ֵС��10**6������ʹ��Int,��������ͣ�����ll 
 

//˼·��
//  ������ĿҪ����ص㣬�������ߴ��������صȴ�ȫ�����ݡ� 
//  ����allSum �����е����룬���ΪT��
//  ����shuguoMax ����ǰ�е�������� ��¼�������������ΪP ����record ��¼��ǰ���ı��. ���Ϊk�� 

//��llû̫��Ļ����������� ��

//һ�������Ŀ���Ǻܼ򵥵ġ� 
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
