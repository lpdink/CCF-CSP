#include<iostream>
using namespace std;

//��Ŀ����
//Ҫ�������˹�ͬװ����ʱ��֮��

//���룺
//n ʱ�������
//������n�У�Сhװ����ai,bi��ʱ��㣬������ʱ��Σ�
//������n�У�Сwװ����ci,di��ʱ��㣬������ʱ��Σ�

//�����
//һ�У�һ�������������˿����Ķ�á�

//����
// ���������ll���� 

//˼·��
// һ������������
// ����ʱ�䲻�ཻ���ҵ�����
// ʹ���±������
// ��������hpre,haft,wpre,waft���洢����ֵ��
// ����sumTime Ϊlong long��¼�ܺ�
// �����±�h,w��0��ʼ���ֱ����h��w�� 

//�ж�����
// ��������ֿ��ܣ�
//  hpre>=wpre &&hpre<waft|| wpre>=hpre && wpre<haft
// ��ӽ�����˭��Ϊ��β��ʱ��㣬˭+1�� 

//20�֣����㲻��ȫͨ��...
//���������أ����е����Ӧ�ö�������ѽ..
 

int main(){
	long long sumTime=0;
	int n;
	cin>>n;
	int hpre[n]={0},haft[n]={0},wpre[n]={0},waft[n]={0};
	
	for(int i=0;i<n;i++){
		cin>>hpre[i]>>haft[i];
	}
	for(int i=0;i<n;i++){
		cin>>wpre[i]>>waft[i];
	}
	
	int h=0;int w=0;
	while(h<n&&w<n){
		if(haft[h]<=wpre[w]){
			h++;
			continue;
		}
		if(waft[w]<=hpre[h]){
			w++;
			continue;
		}
		
		if(hpre[h]>=wpre[w]&&hpre[h]<waft[w]){
			if(haft[h]<=waft[w]){
				sumTime+=haft[h]-hpre[h];
				h++;
			}
			else{
				sumTime+=waft[w]-hpre[h];
				w++;
			}
			continue;
		}
		else if(wpre[w]>=hpre[h]&&wpre[w]<haft[w]){
			if(haft[h]<=waft[w]){
				sumTime+=haft[h]-wpre[w];
				h++;
			}
			else{
				sumTime+=waft[w]-wpre[w];
				w++;
			}
			continue;
		}
		
		cout<<
		break;
	}
	cout<<sumTime<<endl;
	
} 
