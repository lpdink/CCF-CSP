//2020-09-01
//难点在将给出的数据正确保存到数组之中。
#include<iostream>
using namespace std;

int arr[2001]={0};
int dis[1001]={0}; 
int main(void)
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&arr[i],&arr[i+1000]);
	}
	
	for(int i=1;i<=n;i++)
	{
		dis[i]=(arr[i]-x)*(arr[i]-x)+(arr[i+1000]-y)*(arr[i+1000]-y);
	}
	
	for(int i=1;i<=3;i++)//要三个输出，所以循环三次 
	{
		int min=1000000;
		for(int j=1;j<=n;j++)
		{
			if(min>dis[j])
			min=dis[j];
		}
		for(int k=1;k<=n;k++)
		{
			if(dis[k]==min)
			{
				printf("%d\n",k);//输出的是编号
				dis[k]=1000000;
				break;//退出当前循环	
			}	
		}	
	} 
	return 0; 
}