//必须尽快复习C++基本数据结构和操作.尤其是涉及数组、指针、高维数组、类、对象
//以及复杂数据结构作为函数参数与返回值的情况。

//运用面向对象逐级抽象可以做，但是应该怎么判断LOOP？
//通过设置最大深度似乎可以，但是多次栈调用是否会超出内存限制？
//此外，面向对象需要抽象的次数太多了，缺乏一种有效的手段直接得到值。

//下面的代码不完善。
#include<iostream>
#include<string>
using namespace syd;
const int maxn=1e3;

class Element{
    public:
        string func;
        int inputNum;
        string inputArray[maxn];
        int answer=-100;
        Element(string func,int inputNum,string * inputArray);
}
Element::Element(string func,int inputNum,string *inputArray){
    func=func;inputNum=inputNum;inputArray=inputArray;
}
int getAND(Element element,int* inputArray){
    int answer=element.inputArray
    for(int k=0)
}
int getOR(Element element,int* inputArray){}
int getXOR(Element element,int* inputArray){}
int getNAND(Element element,int* inputArray){}
int getNOR(Element element,int* inputArray){}

void getAnswer(Element element,int* inputArray){
    if(element.func=="NOT")element.answer=~getNum(element.inputArray[0],inputArray);
    else if(element.func=="AND")element.answer=getAND(element,inputArray);
    else if(element.func=="OR")element.answer=getOR(element,inputArray);
    else if(element.func=="XOR")element.answer=getXOR(element,inputArray);
    else if(element.func=="NAND")element.answer=getNAND(element,inputArray);
    else if(element.func=="NOR")element.answer=getNOR(element,inputArray);
}

void getAnswers(Element* elements,int* inputArray,int N){
    for(int n=0;n<N;n++){
       getAnswer(elements[n],int* inputArray);
    }
}

int main(){
    int questionNum;
    cin>>questionNum;
    for(int qn=0;qn<questionNum;qn++){
        int M,N;//M表示电路的输入，N表示器间的数量,接下来的N行，每行描述一个器间
        //FUNC K Lk;
        cin>>M>>N;
        Element elements[N];
        for(int n=0;n<N;n++){
            string func;
            int K;
            cin>>func>>K;
            string inputArray[maxn]="";
            for(int k=0;k<K;k++){
                cin>>inputArray[k];
            }
            elements[n]=new Element(func,K,inputArray);
        }
        int S;//测试次数
        cin>>S;
        int inputArray[S][M];
        for(int s=0;s<S;s++){
            for(int m=0;m<M;m++){
                cin>>inputArray[s][m];
            }
        }
        
        getAnswers(elements,inputArray,N);

    }

    return 0;
}