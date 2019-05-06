#include<iostream>
#include<cstring>
using namespace std;

void GenAllStrFromPatternUtil(char *str,int len,char *res, int index)
{
    if(len == index)
    {
	cout << res << endl;
	return;
    }

    if(str[index] == '?')
    {
        res[index] = '0';
        GenAllStrFromPatternUtil(str,len,res,index+1);
        res[index] = '1';	
        GenAllStrFromPatternUtil(str,len,res,index+1);
    }
    else
    {
        res[index] = str[index];
        GenAllStrFromPatternUtil(str,len,res,index+1);
    }
}

void GenAllStrFromPattern(char str[])
{
    //cout << "Given Pattern : " << str << endl;
    int len = strlen(str)+1;
    //cout << "len : " << len << endl;
    char *res = new char[len];
    res[len-1] = '\0';
    GenAllStrFromPatternUtil(str,len,res,0);
}

int main()
{
    char str[] = "1??0?101";
    GenAllStrFromPattern(str);
    return 0;
}

