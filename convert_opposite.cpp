/*
 * Author: Srikanth Peetha
 * About: Convert the string to opposite case (lower case <-> upper case)
*/


#include<iostream>
using namespace std;

void convertOpposite(string &line)
{
	int len = line.length();
	int i = 0;
	
	cout << line << endl;
	int lower, upper;

	//for(i=0; i<len; i++)
	while(i<len)
	{
		upper = 0;

		if(line[i]>='a' && line[i]<='z')
		{
			//string is lower-case. Convert to upper-case
			line[i] = line[i] - 32;
			upper = 1;
			
			//the above IF statement will convert the charecter from lower case to upper case. If we do not make "upper" variable as 1, then the next IF statement will convert the charecter to lower case again.
		}
		
		if(line[i]>='A' && line[i]<='Z' && upper == 0)
		{
			//string is upper-case. Convert to lower-case
			line[i] = line[i] + 32;
		}
		
		else
			line[i] = line[i]; //leave the spaces untouched
		
		i += 1;
	}
			cout << "\n";
		cout << line << endl;

}

int main()
{
	string str1 = "hOw ArE yOU dOiNg";
	string str2 = "HOW ARE YOU DOING";
	string str3 = "how are you doing";
	//calling the function
	
	convertOpposite(str1);
	//convertOpposite(str2);
	//convertOpposite(str3);
	

	return 0;
}
