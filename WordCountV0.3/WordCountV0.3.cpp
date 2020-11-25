#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include"wc.h"
using namespace std;

int main(int argc, char* argv[])                 //∂¡»°cmd√¸¡Ó Project1.exe -w D://test1.txt
{
    WordCount wc(argv[1], argv[2]);
    wc.Count();
    wc.Output(argv[1]);
}