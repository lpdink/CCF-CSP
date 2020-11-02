#include<iostream>
using namespace std;

//题目描述：
//小明放学问题，在前一题的基础上，不是实时获得，而是需要推断。

//输入：
//r,y,g
//n 道路段数 红绿灯数目
//n行，每行：
//k，t
//k:0 道路 1：出发时红灯 且t，2：出发时黄灯，且t，3：出发时绿灯，且t

//输出：
//回家时间

//检查点：
//t不超过10**6,n不超过10**5
//考虑最大情况，theTime声明为longlong 

//思路：
//在前一题的基础上，增加更新函数，修改此时的k和t即可。 
//依然可以实时处理。 

//OT了，90分，奇怪，第一次遇到这样的问题。 
void upDateKAndT(int r,int y,int g,long long theTime,int& k,int& thisTime){
	//思路是减掉theTime的时间，为0时取k，并更新thisTime；
	//按照保留，即取红灯0秒，而非黄灯y秒。 
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
