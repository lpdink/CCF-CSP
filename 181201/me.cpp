#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//��������
//С����ѧ���⣬�������������Ŀ���������˻��
//������ƺͻƵ�Ҫ�ȴ�����Ƶȴ�ʣ��ʱ�䣬�ƵƵȴ�ʣ��ʱ��+������ʱ�� 
//�̵Ƶ�ʣ��ʱ�������õ� 
 
//���룺
// r,y,g �죬�ƣ��̵Ƶ��ʱ��
// n ������·����+�����ĺ��̵���Ŀ
// ��������N��
// k=0Ϊ��·��ֱ�ӼӺ����ʱ�� 
// k=1Ϊ��� ֱ�ӼӺ����ʱ��
// k=2Ϊ�Ƶ� �Ӻ����ʱ�䣬�ټ�r
// k=3Ϊ�̵ƣ����ӡ�

//���
//С����ѧ��ʱ��t

//���㣺
//rgy��10**6�� n<=100�����迼�Ƿ�Χ

//˼·��
//����������������˼·�� 

//���ۣ�
//�׸��������ǵ�����Ҫ���Ա��� 

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
