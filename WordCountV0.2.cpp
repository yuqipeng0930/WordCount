#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(int argc, char* argv[])                 //��ȡcmd���� Project1.exe -w D ://test1.txt
{
   
    int i; 
    int Rows = 0,length, words = 1, sentence = 0;//����,���ȣ�������������
    string article;
    string sum;                                   
    string a = argv[1];                          //ָ�-w\-c\-s
    string b = argv[2];                          //�ļ�����·��
    ifstream inFile(b, ios::in);                 //��ȡ�ļ�
    if (inFile) 
    { 
        cout << "file open successful" << endl;
        while (getline(inFile, article))
        {
            sum = sum + article;                 //�����о�������һ��
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