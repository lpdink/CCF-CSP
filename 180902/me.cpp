#include<iostream>
using namespace std;

//题目分析
//要求两个人共同装车的时间之和

//输入：
//n 时间段数量
//接下来n行，小h装车的ai,bi（时间点，描述了时间段）
//再下来n行，小w装车的ci,di（时间点，描述了时间段）

//输出：
//一行，一个正整数，两人可以聊多久。

//检查点
// 求和声明成ll即可 

//思路：
// 一个隐含条件：
// 各组时间不相交，且递增。
// 使用下标遍历法
// 声明数组hpre,haft,wpre,waft，存储所有值。
// 声明sumTime 为long long记录总和
// 声明下表h,w从0开始，分别遍历h和w。 

//判断条件
// 相加有两种可能：
//  hpre>=wpre &&hpre<waft|| wpre>=hpre && wpre<haft
// 相加结束后，谁作为收尾的时间点，谁+1； 

//20分，检查点不完全通过...
//问题在哪呢，所有的情况应该都考虑了呀..
 

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
