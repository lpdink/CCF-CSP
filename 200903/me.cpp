// Q 问题数目
// M 输入个数 N 器件数量（意味着接下来有n行）
// 器件行的格式：  命令 输入个数  输入来源 I为直接输入 O为对应标号的器间输出
// S：测试输入行数
// S行测试输入
// 输出个数 输出标号
#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int questionNum,inputNum,elementNum,eachInputNum,testNum,returnOutputNum;
    string command,input1,input2;
    cin>>questionNum;
    cin>>inputNum>>elementNum;
    int answerArray[elementNum]={0};
    for(int qn=0;qn<questionNum;qn++){
        for(int en=0;en<elementNum;en++){
            cin>>command>>eachInputNum;
            int args[eachInputNum]={0};
            for(int inp=0;inp<eachInputNum;inp++){

            }
        }
    }
}