#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;

class WordCount
{
public:
    vector <string> content;
    int rows, length, words, sentence, commentline, flag, blankline;
    string a;                          //指令：-w\-c\-s\cl\-bl\-tl
    string b;                          //文件具体路径

    WordCount(string a, string b);     //进行初始处理 
    void Count();              //进行计数 
    void Output(string a);    //输出结果 
};
WordCount::WordCount(string a, string b)
{
    words = 0, rows = 0, sentence = 0, commentline = 0, flag = 0, blankline = 0, length = 0;
    ifstream inFile(b, ios::in);
    if (inFile)
    {
        cout << "File opened successfully." << endl;
        string line;
        while (getline(inFile, line))
        {
            content.push_back(line);
            rows++;
            if (line.length() == 0)
            {
                blankline++;
            }
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
            else if ((line[k] == '/') && ((line[k + 1] == '/') || (line[k + 1] == '*')))
            {
                flag = 1;
            }
            else if ((line[k] == '/') || (line[k] == '*') && (line[k + 1] == '/'))
            {
                flag = 0;
                commentline++;
            }

        }
        if (flag == 1)
        {
            commentline++;
        }
    }
}
void WordCount::Output(string a)
{
    if (a == "-w")                             //判断需要输出的内容
    {
        cout << "The number of words is :" << words + rows - blankline - commentline << endl;
    }
    else if (a == "-c")
    {
        cout << "The number of characters is:" << length << endl;
    }
    else if (a == "-s")
    {
        cout << "The number of sentences is:" << sentence << endl;
    }
    else if (a == "-cl")
    {
        cout << "The number of comment lines is:" << commentline << endl;
    }
    else if (a == "-bl")
    {
        cout << "The number of blank lines is:" << blankline << endl;
    }
    else if (a == "-tl")
    {
        cout << "The number of Total sentence lines is:" << rows << endl;
    }
    else
    {
        cout << "Please enter the correct command. " << endl;
    }
}


