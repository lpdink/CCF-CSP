#include<iostream>
using namespace std;

//思路：
//在循环外对1和最后分别处理
 
int main(){
	int n;
	int p1,p2,p3;
	cin>>n;
	cin>>p1>>p2;
	cout<<(p1+p2)/2<<" ";
	for(int i=0;i<n-2;i++){
		cin>>p3;
		cout<<(p1+p2+p3)/3<<" ";
		if(i!=n-3){
		p1=p2;
		p2=p3;}
	} 
	cout<<(p2+p3)/2<<endl;
	
	
	
	return 0;
} 
