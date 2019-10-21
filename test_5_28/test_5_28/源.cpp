#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#define N 8      //皇后个数 
using namespace std;

int sum = 0;
bool Place(int k, int i, int *x);
void NQueens(int k, int n, int *x);;
void NQueens(int n, int *x);

int main()
{
	int x[N];
	for (int i = 0; i<N; i++) x[i] = -1;
	NQueens(N, x);
	cout << N << "皇后共有" << sum << "种解！" << endl;
	return 0;
}

bool Place(int k, int i, int *x) //判定两个皇后是否在同一列或在同一斜线上
{
	for (int j = 0; j<k; j++)
	if ((x[j] == i) || (abs(x[j] - i) == abs(j - k))) return false;
	return true;
}
void NQueens(int k, int n, int *x)
{
	for (int i = 0; i<n; i++)
	{
		if (Place(k, i, x))
		{
			x[k] = i;
			if (k == n - 1)    //输出所有可行解
			{
				sum++;
				for (int i = 0; i<n; i++)
				{
					for (int j = 0; j<n; j++)
					{
						if (j == x[i])
							cout << " #";
						else
							cout << " _";
					}
					cout << endl;
				}
				cout << endl;
			}
			else
			{
				NQueens(k + 1, n, x);
			}
		}
	}
}


void NQueens(int n, int *x)
{
	NQueens(0, n, x);
	system("pause");
}
#endif

#include<iostream>
#include<ctime>
using namespace std;

bool isOK(int n, int pieces[])
{    //剪枝函数
	//判断当前状态是否合理，即皇后会不会互相攻击
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int left = -(j - i);//向左的斜线
			int right = (j - i);//向右的斜线
			if (pieces[j] == pieces[i] + left || pieces[j] == pieces[i] + right)
			{//第i行皇后和第j行皇后会互相攻击
				return false;
			}
		}
	}
	//所有皇后都不会互相攻击
	return true;
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void nQueen(int n, int t, int pieces[])
{
	if (t > n)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < pieces[i]; j++)
				cout << "- ";
			cout << pieces[i] << " ";
			for (int j = pieces[i] + 1; j <= n; j++)
				cout << "- ";
			cout << endl;
		}
		cout << endl;
	}
	else
	{
		for (int i = t; i <= n; i++)
		{
			swap(pieces[t], pieces[i]);
			if (isOK(t, pieces))
			{
				nQueen(n, t + 1, pieces);
			}
			swap(pieces[t], pieces[i]);
		}
	}
}

void main()
{
	int n;
	cin >> n;
	int *pieces = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		pieces[i] = i;
	}
	nQueen(n, 1, pieces);
	cout << "OK" << endl;
	system("pause");
}
