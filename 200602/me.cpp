#include<iostream>
#include<stdlib.h>
using namespace std;

//v ��indexά���ϵ�ȡֵ��vindex  Index��1��ʼ 
//ϡ������  �洢(index,value)
//��  [(4,5),(7,-3),(10,1)]
 
 //����
 //n  a  b  ά�� ����������0ֵ�ĸ���
 // 2-a+1�� u��ϵ����ʾ  ÿ�У� index -value
 // a+2�е�a+b+1�� v ��ϵ����ʾ index-value
 // ���һ������ ��ʾu��v���ڻ��� 


//˼·�������ĸ����飬v��������u��������v��ֵ��u��ֵ
//�� m ��������u����n��������v���Ƚ���ͬλ�õ������Ƿ�һ����
//����ǣ���theSum����ֵ�ĳ˻�������
//���m�������Ĵ���n�������ģ���n���ӣ�ѭ��������̡� 
 
 //�����ȫ�ԣ�ֻ�õ�60�֣������ֱ�����룬ʹ��malloc����ռ��Ǳ�Ҫ�ġ� 
 //��ȫ�Ե�ԭ�����ڣ�theSum��ֵ���ܷǳ��������ʹ��long long���������� 
  
int main(){
	int d,a,b;
	cin>>d>>a>>b;
	int m=0,n=0;
	int *indexU = (int *) malloc (sizeof(int) * 500000);
	int *valueU = (int *) malloc (sizeof(int) * 500000);
	int *indexV = (int *) malloc (sizeof(int) * 500000);
	int *valueV = (int *) malloc (sizeof(int) * 500000);

	for(int i=0;i<a;i++){
		cin>>indexU[i]>>valueU[i];
	}

	for(int k=0;k<b;k++){
		cin>>indexV[k]>>valueV[k];
	}

	
	long long theSum=0;
	while(m<a&&n<b){
		if(indexU[m]==indexV[n]){
			theSum+=valueU[m]*valueV[n];
			m++;
			n++;
		}
		else if(indexU[m]>indexV[n]){
			n++;
		}
		else{
			m++;
		}
	}
	cout<<theSum;
	
	
	
	return 0;
}
