#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <vector>
#include <stdlib.h>

//TO DO:
//JUST CALCULATE TWO NEIGHBORS (IE TOP/BOTTOM) FOR EACH ELEMENT AND THERE WILL BE NO REPEATS
//SEPARATE INTO MULTIPLE FUNCTIONS FOR REUSABILITY
//PASSING IN MATRIX TO FUNCTION specify **int

using namespace std;

//generate random number to represent size of matrix
int A1, B1, C1, D1, A2, B2, C2, D2, A3, B3, C3, D3;
int N = rand()%12;

int total_energies = 0;

//create our vector, V, of known ECI values
int V[3] = {20, 10, 5};

vector<int> first_energies;
vector<int> second_energies;
vector<int> third_energies;

//this function creates an NxN matrix representing our binary mixture
//sig(A) = 1
//sig(B) = -1

void binaryMixture()
{
	cout << "N: " << N << endl;
	cout << "System: " << endl;
	//create our matrix
	//int mix[N][N];
	// or (best way -> create a vector of vectors):
	vector<vector<int> > mix(N, vector<int>(N, 0));
	// or, maybe:
	// int **mix;
	// mix = new int* [N];
	// for(int i = 0; i < N; i++)
	// {
	// 	mix[i] = new int [N];
	// }

	//rows of size N
	for (int i = 0; i < N; i++)
	{
		//columns of size N
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

	//calculate energies and push them into a vector
	for(int x = 0; x < N; x ++)
	{
		for(int y = 0; y < N; y++)
		{
			//Don't use y+1 index if y is last column
			if(y != N-1)
			{
				A1 = mix[x][y+1];

				//Don't use x+1 index if x is also last row
				if(x != N-1)
				{
					A2 = mix[x+1][y+1];
				}
				else
				{
					A2 = 0;
				}

				//Don't use x-1 index if x is also first row
				if(x != 0)
				{
					C2 = mix[x-1][y+1];
				}
				else
				{
					C2 = 0;
				}

			}
			else
			{
				A1 = 0;
			}

			//Don't use y-1 index if y is first column
			if(y != 0)
			{
				B1 = mix[x][y-1];

				//Don't use x+1 index if x is also last row
				if(x != N-1)
				{
					B2 = mix[x+1][y-1];
				}
				else
				{
					B2 = 0;
				}

				//Don't use x-1 index if x is also first row
				if(x != 0)
				{
					D2 = mix[x-1][y-1];
				}
				else
				{
					D2 = 0;
				}

			}
			else
			{
				B1 = 0;
			}

			//Don't use x+1 index if x is last row
			if(x != N-1)
			{
				C1 = mix[x+1][y];
			}
			else
			{
				C1 = 0;
			}

			//Don't use x-1 index if x is first row
			if(x != 0)
			{
				D1 = mix[x-1][y];
			}
			else
			{
				D1 = 0;
			}

			//Don't use y+2 (NN3) if out of range
			if(y != N-1 && y!= N-2)
			{
				A3 = mix[x][y+2];
			}
			else
			{
				A3 = 0;
			}

			//Don't use y-2 (NN3) if out of range
			if(y != 0 && y!= 1)
			{
				B3 = mix[x][y-2];
			}
			else
			{
				B3 = 0;
			}

			//Don't use x+2 (NN3) if out of range
			if(x != N-1 && x != N-2)
			{
				C3 = mix[x+2][y];
			}
			else
			{
				C3 = 0;
			}

			//Don't use x-2 (NN3 if out of range)
			if(x != 0 && x != 1)
			{
				D3 = mix[x-2][y];
			}
			else
			{
				D3 = 0;
			}

			//NN1 Energies vector
			first_energies.push_back(V[0]*(A1 + B1 + C1 + D1));
			// cout << V[0] << "x" << A1 << "+" << B1 << "+" << C1 << "+" << D1 << endl;

			//NN2 Energies vector
			second_energies.push_back(V[1]*(A2 + B2 + C2 + D2));
			// cout << V[1] << "x" << A2 << "+" << B2 << "+" << C2 << "+" << D2 << endl;

			//NN3 energies vector
			third_energies.push_back(V[2]*(A3 + B3 + C3 + D3));
			// cout << V[2] << "x" << A3 << "+" << B3 << "+" << C3 << "+" << D3 << endl;
		}
	}


	cout << "Energies: " << endl;
	for(int h = 0; h < N*N; h++)
	{
		//calculate total energy
		total_energies = total_energies + first_energies[h] + second_energies[h] + third_energies[h];
		//print value after every step
		// cout << total_energies << endl;
	}
	cout << "Total Energy: " << total_energies << endl;
}

int main()
{
	srand ( time(0) );
	//call function to generate random NxN matrix of -1's and 1's
	binaryMixture();

	//print out ECI values
	cout << "V: " << endl;
	for(int i = 0; i < 3; i++)
	{
		cout << V[i] << endl;
	}
}