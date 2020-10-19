#include<iostream>
using namespace std;
const int maxn=1e3;
int x[maxn],y[maxn],z[maxn];
char tp[maxn];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>tp[i];
    }
    int c0,c1,c2;
    while(m--){
        cin>>c0>>c1>>c2;
        for(int i=0;i<n;i++){
            int tmp;
            tmp=c0+c1*x[i]+c2*y[i];
            if(tmp<0)z[i]=-1;
            else z[i]=1;
        }
        bool flag=1;
        for(int i=1;i<n;i++){
            if((tp[i]==tp[0]&&z[i]!=z[0])||(tp[i]!=tp[0]&&z[i]==z[0])){
                flag=0;
                break;
            }
        }
        if(flag)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}