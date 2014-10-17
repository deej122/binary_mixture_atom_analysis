#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>

using namespace std;

//generate random number to represent size of matrix
int N = rand()%12;

//this function creates an NxN matrix representing our binary mixture
//A = 1
//B = -1

void binaryMixture()
{
	cout << "N: " << N << '\n';
	//create our matrix
	int mix[N][N];
	//columns of size N
	for (int i = 0; i < N; i++)
	{
		//rows of size N
		for (int j = 0; j < N; j++)
		{
			//if atom is a zero, generate random number (-1 or 1) again, until it doesn't equal 0
			do	
			{
				mix[i][j] = rand()%3 + (-1);
			} while (mix[i][j] == 0);
		}
	}
	
	//print out matrix
	for(int k = 0; k < N; k++)
	{
		//evenly space columns
		for(int m = 0; m < N; m++)
		{
			cout << setw(5) << mix[k][m];
		}
		//break after each row for structure
		cout << endl;
	}
}

int main()
{
	//call function to generate random NxN matrix of -1's and 1's
	binaryMixture();
}
