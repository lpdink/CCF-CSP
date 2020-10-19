//绝了，怎么写都过不了，吐了...
//说好的签到题呢...
//别人只写了30行，丢人...直接看人家的。
#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
        int x,y;
        char type;
        int answer;
        Node(int x,int y,char type);
        Node();
};

Node::Node(int xx,int yy,char ttype){
    x=xx;y=yy;type=ttype;
}
Node::Node(){}

int main(){
	int stringNum=0;
	string stringList[1000];
    int n,m;
    cin>>n>>m;
    Node* NodeList[n];
    for(int nn=0;nn<n;nn++){
        int tx,ty;
        char ttype;
        cin>>tx>>ty>>ttype;
        Node* newNode=new Node(tx,ty,ttype);
        NodeList[nn]=newNode;
    }
    
    
    
    for(int mm=0;mm<m;mm++){
        int th0,th1,th2;
        cin>>th0>>th1>>th2;
        int lable=1;
        for(int nn=0;nn<n;nn++){
            int answer=th0+th1*NodeList[nn]->x+th2*NodeList[nn]->y;
            NodeList[nn]->answer=answer; 
        }
        for(int nn=1;nn<n;nn++){
            if(NodeList[nn]->type==NodeList[0]->type){
                if(NodeList[nn]->answer*NodeList[0]->answer>0){
				continue;}
                else
                {
                	stringList[stringNum]="No";
                	stringNum+=1;
                    lable=0;
                    break;
                }}
            else
            {
                if(NodeList[nn]->answer*NodeList[0]->answer<0){
				continue;}
                else
                {
                    stringList[stringNum]="No";
                	stringNum+=1;
                    lable=0;
                    break;
                }
                
            }
            
    	}
    	if(lable==1){
		stringList[stringNum]="Yes";
                	stringNum+=1;}
}

		for(int i=0;i<stringNum;i++){
			cout<<stringList[i]<<endl;
		}
}
