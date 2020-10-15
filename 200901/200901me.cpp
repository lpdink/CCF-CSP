#include<iostream>
using namespace std;

int main(){
    int addr[2001]={0};
    int dis[1001]={0};
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    for(int i=0;i<n;i++){
        scanf("%d%d",&addr[i],&addr[i+1000]);
    }

    for(int i=0;i<n;i++){
        dis[i]=(addr[i]-x)*(addr[i]-x)+(addr[i+1000]-y)*(addr[i+1000]-y);

    }
    for(int i=0;i<3;i++){
        int min=100000;
        int lable=-1;
        for(int k=0;k<n;k++){
            if(min>dis[k]){min=dis[k];lable=k;}
        }
        printf("%d\n",lable+1);
        dis[lable]=1000000;
    }
return 0;

}