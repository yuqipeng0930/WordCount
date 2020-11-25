#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;

class WordCount
{
public:
    vector <string> content;
    int rows, length, words, sentence;
    string a;                          //ָ�-w\-c\-s
    string b;                          //�ļ�����·��

    WordCount(string a, string b);     //���г�ʼ���� 
    void Count();              //���м��� 
    void Output(string a);    //������ 
};
WordCount::WordCount(string a, string b)
{
    words = 0, rows = 0, sentence = 0,length = 0;
    ifstream inFile(b, ios::in);
    if (inFile)
    {
        cout << "File opened successfully." << endl;
        string line;
        while (getline(inFile, line))
        {
            content.push_back(line);
            rows++;
            length = length + line.length();
        }
    }
    else
    {
        cout << "File doesn't exist." << endl;
    }
    inFile.close();
}

void WordCount::Count()
{
    string line;
    unsigned int i, k, flag = 0;
    for (i = 0; i < rows; i++)
    {
        line = content[i];
        for (k = 0; k < line.length(); k++)
        {
            if (line[k] == ' ')
            {
                words++;
            }
            else if (line[k] == '.' || line[k] == '?' || line[k] == '!')
            {
                sentence++;
            }
        }
    }
}
void WordCount::Output(string a)
{
    if (a == "-w")                             //�ж���Ҫ���������
    {
        cout << "The number of words is :" << words + rows  << endl;
    }
    else if (a == "-c")
    {
        cout << "The number of characters is:" << length << endl;
    }
    else if (a == "-s")
    {
        cout << "The number of sentences is:" << sentence << endl;
    }

    else
    {
        cout << "Please enter the correct command. " << endl;
    }
}