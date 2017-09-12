/*
 * Author: Srikanth Peetha
 * About: Rat in a maze problem / Backtracking algorithm
*/

#include <iostream>
using namespace std;

void printarray(int arg1[4][4]) 
{
	int i;
	cout << "\nThe solution matrix is:\n";
	for(i=0;i<4;i++)
	{
		for (int j=0; j<4; j++)
		{
			cout << arg1[i][j] << ", " ;
		}
		cout << "\n";
	}
}

bool checkDest(int a, int b)
{
	if(a==3 && b==3)
	{
		return true;
	}
	else
		return false;
}

int main()
{
	int maze[4][4] = { {1,0,0,0}, {1,1,0,1}, {0,1,0,0}, {1,1,1,1} };
	int sol[4][4] = {}; // Create a 4*4 matrix of ZEROS
	
	int x,y,i,j; //(x,y) for maze & (i,j) for sol
	x = 0;
	y = 0;
	i = 0;
	j = 0;
	
	char cmd = 'F';
	bool dest = false;
	bool chk;
	
	while(dest == false && (i!=3 || j!=3) )
	{	
	   switch(cmd) 
	   {
	    	case 'F' : //move forward
			         sol[i][j] = 1;
					 
					 if(maze[x][y+1] == 1)
			         {
			         	++j;
			         	++y;
			         	
						chk = checkDest(i,j);
			         	if(chk == true)
			         	{
			         		dest = true;
			         		sol[i][j] = 1;
						}
						else
						{
							dest =false;
						   	cmd = 'F';
						}
					 }
					 
					 else //move down
					 {
					 	sol[i][j] = 0;
					 	cmd = 'D';
					 }
	    	break;
	         
	    	case 'D' ://move Downwards
	      			sol[i][j] = 1;
	      			
					if( maze[x+1][y] == 1)
	      			{
	      				++x;
	      				++i;
	      				
	      				chk = checkDest(i,j);
			         	if(chk == true)
			         	{
			         		dest = true;
			         		sol[i][j] = 1;
						}
						else
						{
							dest =false;
						   	cmd = 'F';
						}
					}
					else //move Back
					{
						sol[i][j] = 0;
						--y;
						--j;
						cmd = 'D';
					}
	        break;     
		}
	}
	
	
	if (dest == true)
	{
		cout << "\ndestination reached! ";
		printarray(sol);
	}
	
	if(dest == false && (i==3 || j==3) )
		cout << "\nno path is possible through maze!";
	return 0;
}

