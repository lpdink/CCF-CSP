//一遍过，CCF不过如此...（开心~
#include<iostream>
using namespace std;

int judgeStay(int* array,int t,int k,int xl,int yd,int xr,int yu){
    int tempk=k;
    for(int i=0;i<t;i++){
        int x=array[2*i];
        int y=array[2*i+1];
        if(x>=xl && x<=xr && y>=yd && y<=yu){
            tempk--;
        }
        else
        {
            tempk=k;
        }

        if(tempk==0){
            return 1;
        }
    }
    return 0;
}

int judgePass(int* array,int t,int k,int xl,int yd,int xr,int yu){
    for(int i=0;i<t;i++){
        int x=array[2*i];
        int y=array[2*i+1];
        if(x>=xl && x<=xr && y>=yd && y<=yu){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n,k,t,xl,yd,xr,yu;
    int xj,yj;
    int passBy=0;
    int stay=0;
    cin>>n>>k>>t>>xl>>yd>>xr>>yu;
    for(int i=0;i<n;i++){
        int array[2*t]={0};
        for(int j=0;j<t;j++){
            cin>>xj>>yj;
            array[2*j]=xj;
            array[2*j+1]=yj;
        }
        stay+=judgeStay(array,t,k,xl,yd,xr,yu);
        passBy+=judgePass(array,t,k,xl,yd,xr,yu); 

    }
    cout<<passBy<<endl<<stay;
    return 0;
}
