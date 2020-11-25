#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(int argc, char* argv[])                 //读取cmd命令 Project1.exe -w D ://test1.txt
{
   
    int i; 
    int Rows = 0,length, words = 1, sentence = 0;//行数,长度，词数，句子数
    string article;
    string sum;                                   
    string a = argv[1];                          //指令：-w\-c\-s
    string b = argv[2];                          //文件具体路径
    ifstream inFile(b, ios::in);                 //读取文件
    if (inFile) 
    { 
        cout << "file open successful" << endl;
        while (getline(inFile, article))
        {
            sum = sum + article;                 //将多行句子连在一起
            Rows++;                       
        }
        inFile.close();
        length = sum.length();
        for (i = 0; i < length; i++)
        {
            if (sum[i] == ' ')
            {
                words++;
            }
            else if (sum[i] == '.' || sum[i] == '?' || sum[i] == '!')
            {
                sentence++;
            }
        }
        if (a == "-w")
        {
            cout << "The number of words is :" << words+Rows-1 << endl;
        }
        else if(a == "-c")
        {
            cout << "The number of characters is:" << length+Rows-1 << endl;
        }
        else if (a == "-s")
        {
            cout << "The number of sentences is:" << sentence << endl;
        }
    }
    else
    {
        cout << "file doesn't exist"  <<endl;
    }
    return 0;
}