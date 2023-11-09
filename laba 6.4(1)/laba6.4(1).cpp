#include<iostream>
#include<iomanip>
#include <time.h>

using namespace std;

void Input(double* q, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "q[" << i << "] = ";
		cin >> q[i];
	}
	cout << endl;
}
void Print(double* q, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(8) << fixed << setprecision(3) << q[i];
	cout << endl;
}
double Max(double* q, const int size)
{
	double max = q[0];
	for (int i = 1; i < size; i++)
		if (fabs(q[i]) > fabs(max))
			max = q[i];
	return max;
}
double Sum(double* q, const int size)
{
	double S = 0;
	double first = -1;
	double second = -1;
	for (int i = 0; i < size; i++)
		if (q[i] > 0)
		{
			first = i;
			break;
		}
	for (int i = first + 1; i < size; i++)
		if (q[i] > 0)
		{
			second = i;
			break;
		}
	if (first == -1)
		cout << "no + elements" << endl;
	if (first != -1 && second == -1)
		cout << "one + elements" << endl;
	for (int i = first + 1; i < second; i++)
		S += q[i];
	return S;
}
void Sort(double* q, const int size)
{
	for (int i = 1; i < size; i++)
	{
		int c = 0;
		for (int j = 0; j < size - i; j++)
			if (q[j] == 0)
			{
				int tmp = q[j];
				q[j] = q[j + 1];
				q[j + 1] = tmp;
				c = 1;
			}
		if (c == 0)
			return;
	}
}
int main()
{
	int s;
	cout << "s = "; cin >> s;
	double* d = new double[s];

	Input(d, s);

	cout << "q[s] =";
	Print(d, s);
	cout << "module max = " << Max(d, s) << endl;
	cout << "S = " << Sum(d, s) << endl;

	Sort(d, s);
	cout << "d[s] =";
	Print(d, s);
	delete[] d;
	return 0;
}
