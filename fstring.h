/*part of interface about string;
 *it follow the function simply ,no complex situation exist;
 *so it should be modify before you use it;
 *overflow problem is need to be solved;
 */
#ifndef FSTRING
#define FSTRING

#include <string>
#include <vector>
#include <iostream>

using namespace std;

extern bool stringToBoolValid;
extern bool stringToIntValid;
extern bool stringToDoubleValid;

//split the string with delim,default delim is ' '
bool split(vector<string>& ,const string str,const char delim=' ');
//convert string to int
int stringToInt(const string& );
//convert string to double
double stringToDouble(const string& );
//convert string to bool
bool stringToBool(const string& );
//print current time of this system
bool printSystemTime(ostream& output=cout);

#endif //FSTRING