#include<iostream>
using namespace std;

//��Ŀ������
//С����ѧ���⣬��ǰһ��Ļ����ϣ�����ʵʱ��ã�������Ҫ�ƶϡ�

//���룺
//r,y,g
//n ��·���� ���̵���Ŀ
//n�У�ÿ�У�
//k��t
//k:0 ��· 1������ʱ��� ��t��2������ʱ�Ƶƣ���t��3������ʱ�̵ƣ���t

//�����
//�ؼ�ʱ��

//���㣺
//t������10**6,n������10**5
//������������theTime����Ϊlonglong 

//˼·��
//��ǰһ��Ļ����ϣ����Ӹ��º������޸Ĵ�ʱ��k��t���ɡ� 
//��Ȼ����ʵʱ���� 

//OT�ˣ�90�֣���֣���һ���������������⡣ 
void upDateKAndT(int r,int y,int g,long long theTime,int& k,int& thisTime){
	//˼·�Ǽ���theTime��ʱ�䣬Ϊ0ʱȡk��������thisTime��
	//���ձ�������ȡ���0�룬���ǻƵ�y�롣 
	if(k==0)return;
	bool first=true;
	while(true){
		if(first){
			if(theTime-thisTime>0){
				theTime-=thisTime;
				k--;
				if(k==0)k=3;
			}
			else {
				thisTime-=theTime;
				return;
			}
			first=false;
		}
		
		if(k==1){
			if(theTime-r>0){
				theTime-=r;
				k=3;
			}
			else{
				thisTime=r-theTime;
				return;
			}
		}
		if(k==2){
			if(theTime-y>0){
				theTime-=y;
				k=1;
			}
			else{
				thisTime=y-theTime;
				return;
			}
		}
		if(k==3){
			if(theTime-g>0){
				theTime-=g;
				k=2;
			}
			else{
				thisTime=g-theTime;
				return;
			}
		}
	} 
}

int main(){
	int r,y,g,n;
	cin>>r>>y>>g>>n;
	long long theTime=0; 
	for(int i=0;i<n;i++){
		int k,thisTime;
		cin>>k>>thisTime;
		upDateKAndT(r,y,g,theTime,k,thisTime);
		if(k==0)theTime+=thisTime;
		if(k==1)theTime+=thisTime;
		if(k==2)theTime+=thisTime+r; 
	} 
	cout<<theTime<<endl;
	
	
	
	
	return 0;
} 
