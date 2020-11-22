#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int countZeros(int** a, const int rowCount, const int colCount);
void same(int** a, int* f, const int rowCount, const int colCount, int& num);

int main()
{
	srand((unsigned)time(NULL));
	int num;
	int k = 100;
	int *f = new int[k];
	int Low = 0;
	int High = 10;
	int rowCount, colCount;

	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	 Create(a, rowCount, colCount, Low, High);
	// Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	cout << "count = " << countZeros(a, rowCount, colCount);
	cout << endl;
	same(a, f, rowCount, colCount, num);

	cout << "Number of column = " << num + 1 << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	
	delete[] f;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Input(int** a, const int rowCount, const int colCount)
{
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int countZeros(int **a, const int rowCount, const int colCount)
{
	   int num = 0;
	   for (int i = 0; i < rowCount; i++)
	   {
		   for (int j = 0; j < colCount; j++)
		   {
			   if (a[i][j] == 0)
			   {
				   num++;
				   break;
			   }
		   }
	   }
	return num;
}

void same(int** a, int* f, const int rowCount, const int colCount, int& num)
{
    num = 0;
	int i;
	int c = 1;
	int max1 = 0;
	int max = 0;
	for (i = 0; i < (colCount); i++)
	{
		for (int j = 1; j < (rowCount); j++)
		{
			if (a[j - 1][i] == a[j][i])
			{
				c++;
				if (max < c) 
				{
					max = c;
				}
				
			}
			else
				c = 1;
		}	
		f[i] = max;
		max = 0;
	}
		for (int k = 1; k < i; k++)
		{
			if (f[k] > max1)
			{
				max1 = f[k];
				num = k;
			}
		}
}



