#include<iostream>
#include<stdlib.h>
using namespace std;

//v 在index维度上的取值是vindex  Index从1开始 
//稀疏向量  存储(index,value)
//如  [(4,5),(7,-3),(10,1)]
 
 //输入
 //n  a  b  维度 两个向量非0值的个数
 // 2-a+1行 u的系数表示  每行： index -value
 // a+2行到a+b+1行 v 的系数表示 index-value
 // 输出一个整数 表示u和v的内积。 


//思路：定义四个数组，v的索引，u的索引，v的值，u的值
//用 m 索引数组u，用n索引数组v，比较相同位置的索引是否一样大。
//如果是，则theSum加上值的乘积，否则：
//如果m索引到的大于n索引到的，则n增加，循环这个过程。 
 
 //结果不全对，只得到60分，相较于直接申请，使用malloc申请空间是必要的。 
 //不全对的原因在于：theSum的值可能非常大，你必须使用long long来声明它。 
  
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
