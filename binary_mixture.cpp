#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>

using namespace std;

//generate random number to represent size of matrix
int N = rand()%12;

//create our vector, V, of known ECI values
int V[3] = {20, 10, 5};

//this function creates an NxN matrix representing our binary mixture
//sig(A) = 1
//sig(B) = -1

void binaryMixture()
{
	cout << "N: " << N << endl;
	cout << "System: " << endl;
	//create our matrix
	int mix[N][N];
	//columns of size N
	for (int i = 0; i < N; i++)
	{
		//rows of size N
		for (int j = 0; j < N; j++)
		{
			//if sig(atom) is a zero, generate random number again, until it doesn't equal 0 (= -1, 1)
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

	//print out ECI values
	cout << "V: " << endl;
	for(int i = 0; i < 3; i++)
	{
		cout << V[i] << endl;
	}
}