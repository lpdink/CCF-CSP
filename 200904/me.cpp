//两点间避开黑洞的最短距离：
//能直连则直连（判断直连是否经过球），否则在球上找两个点，分别到两点恰好相切，求距离，再加上球面曲面距离即可。
//在二维情况下实现，尝试推广到高维，之后方可看Others

//n是维度
//m是m个不在黑洞内的点的个数
//r是黑洞的半径
#include<iostream>
#include<math.h>
using namespace std;

double getDistanceDirectly(int* array1,int* array2,int n){
    double theSum=0;
    for(int i=0;i<n;i++){
        theSum+=pow(array1[i]-array2[i],2); 
    }
    theSum=sqrt(theSum);
    return theSum;
}
//判断是否相交。
bool qIntersect(int* centerArray,int r,int* array1,int* array2,int n){
    return true;
}

double getSumDistance(int* centerArray,int r,int points[100][100],int i,int m,int n){
    double theSum=0;
    for(int k=0;k<m;k++){
        if(k==i){continue;}
        bool intersect=qIntersect(centerArray,r,points[i],points[k],n);
        if(intersect){
            double part1=(double)sqrt(pow(getDistanceDirectly(centerArray,points[k],n),2)-r*r);
            double l1=(double)getDistanceDirectly(centerArray,points[i],n);
            double l2=(double)getDistanceDirectly(centerArray,points[k],n);
            double l3=(double)getDistanceDirectly(points[i],points[k],n);
            double p2=(l1+l2+l3)/2;
            double S=sqrt(p2*(p2-l1)*(p2-l2)*(p2-l3));
            double sina=2*S/l1/l2;
            double a=asin(sina);
            double part2=(double)a*r;
            double part3=(double)sqrt(pow(getDistanceDirectly(centerArray,points[i],n),2)-r*r);
            theSum+=part1+part2+part3;
        }
        else{
            theSum+=getDistanceDirectly(points[i],points[k],n);
        }
    }

    return theSum;
}

int main(){
	int m,n,r;
    cin>>n>>m>>r;
    cout<<n<<m<<r; 
    int centerArray[n]={0};
    for(int i=0;i<n;i++){
        cin>>centerArray[i];
    }
    
    int points[100][100];
    for(int i=0;i<m;i++){
        for(int k=0;k<n;k++){
        	cout<<"kk"<<endl;
            cin>>points[i][k];
        }
    }
    for(int i=0;i<m;i++){
        double thisSumDistance=getSumDistance(centerArray,r,points,i,m,n);
        cout<<thisSumDistance<<endl;
    }


	cout<<"done";

    return 0;
}
