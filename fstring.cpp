#include "fstring.h"
#include <time.h>
#include <math.h>

//definition
bool stringToBoolValid=true;
bool stringToIntValid=true;
bool stringToDoubleValid=true;

//分割字符串函数
bool split(vector<string>& vecStr,const string str,const char delim)
{//如果所需要要转化的字符串为空，则直接返回
	if(str.empty())
		return false;
	size_t i=0;
	string subStr;
	subStr.clear();
	while(i<str.size())
	{
		if(str[i]==delim)
		{
			if(!subStr.empty())
				vecStr.push_back(subStr);
			subStr.clear();
		}
		else
		{
			subStr+=str[i];
		}
		++i;
	}
	vecStr.push_back(subStr);
	return true;
}

int stringToInt(const string& str)//转化成整数
{
	if(str.empty())
	{
		stringToIntValid=false;
		return 0;
	}
	int returnInt(0);
	bool flagPlusMinus=0;
	size_t i=0;
	if(str[0]=='+')
	{
		i++;
	}
	else if(str[0]=='-')
	{
		i++;
		flagPlusMinus=1;
	}
	for(;i<str.size();++i)
	{
		if(str[i]<'0' || str[i]>'9')
		{
			stringToIntValid=false;
			returnInt=0;
			return returnInt;
		}
		returnInt=returnInt*10+str[i]-'0';
	}//如果只有一个正号或负号，输出也是零
	
	if(flagPlusMinus)
		returnInt*=(-1);
	return returnInt;
}

double stringToDouble(const string& str)//转化成浮点数
{
	if(str.empty())
	{
		stringToDoubleValid=false;
		return 0;
	}
	double returnDouble(0);
	size_t i=0;
	size_t flag=2000;
	int NumPoint=0;//小数点出现次数
	int decimalNum(0);
	bool flagPlusMinus=0;
	if(str[0]=='+')
	{
		i++;
	}
	else if(str[0]=='-')
	{
		i++;
		flagPlusMinus=1;
	}
	for(;i<str.size();++i)
	{
		if(str[i]=='.')
		{
			if(NumPoint>1)
			{
				stringToDoubleValid=true;
				returnDouble=0;
				return returnDouble;
			}
			flag=i;
			continue;
		}
		else if(str[i]<'0' || str[i]>'9')
		{
			stringToDoubleValid=true;
			returnDouble=0;
			return returnDouble;
		}
		
		if(i>flag)
		{
			decimalNum++;
		}
		returnDouble=returnDouble*10+str[i]-'0';
	}
	for(int t=0;t<decimalNum;++t)
		returnDouble/=10;

	if(flagPlusMinus)
		returnDouble*=(-1);
	return returnDouble;
}

bool stringToBool(const string& str)//String to Bool
{
	if(str.size()>1 || str.empty())
	{
		stringToBoolValid=false;
		return 0;
	}
	if(str=="1")
		return 1;
	else
		return 0;	
}

bool printSystemTime(ostream& output)
{
	time_t currentTime=time(0);
	struct tm* currentTimeStruct=localtime(&currentTime);
	output<<"系统当前时间："<<1900+currentTimeStruct->tm_year<<"."<<
		currentTimeStruct->tm_mon+1<<"."<<currentTimeStruct->tm_mday<<"  "<<
		currentTimeStruct->tm_hour<<":"<<currentTimeStruct->tm_min<<":"<<
		currentTimeStruct->tm_sec<<endl;
	return true;
}