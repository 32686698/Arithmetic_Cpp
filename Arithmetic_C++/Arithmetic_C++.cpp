
#include "stdafx.h"
#include <string>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <math.h>
using namespace std;
bool* getPrimeNumbers(unsigned int);

void main(int argc, char *argv[])
{
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	while (!file.eof()) 
	{
		getline(file, lineBuffer);
		if (lineBuffer.length() == 0)
			continue; //ignore all empty lines
		else 
		{
			stringstream ss;
			ss<<lineBuffer;
			unsigned long int num ;
			ss>>num;
			ss.clear();
			ss.str("");
			bool * b = getPrimeNumbers(num);

			for (unsigned long int i = 2; i < num; i++) {
				if(!b[i]){
					ss<<i<<",";
				}
			}
			cout <<ss.str().substr(0,ss.str().length()-1)<< endl;
		}
	}
	system("pause");
}

bool* getPrimeNumbers(unsigned int num){
	unsigned long int sq = (int) sqrt(num);
	bool* b = new bool[num+1];
	memset(b,0,num+1);
	for(unsigned long int i=2;i<=sq;i++){
		if(!b[i]){
			for(unsigned long int j = i*2;j<num;j +=i){//能进来的都是合并，至少有i这个因子
				b[j]=true;
			}
		}
	}
	return b;
}

