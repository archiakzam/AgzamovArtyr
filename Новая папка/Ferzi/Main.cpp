#include <iostream>

#include <windows.h>
#include <fstream>
using namespace std;
int N=8;
struct ferzes
{
	int x, y;

	ferzes(int m_x = 0, int m_y = 0)
	{
		x = m_x;
		y = m_y;
	}
};

void pole1(int** pole, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) pole[i][j] = 0;
	}
}

void print(int** pole, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) cout << pole[i][j] << ' ';
		cout << endl;
	}
}

void In_File(int** pole, int N, ofstream* FILE)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) 
		{
			if(pole[i][j] == 0) *FILE << "o ";
			else *FILE << "x ";
		}
		*FILE << endl;
	}
}

bool Is_Kill(ferzes ferz, ferzes* all_ferz, int N)
{
	for (int i = 0; i < N; i++)
	{
		int dx = abs(ferz.x - all_ferz[i].x);
		int dy = abs(ferz.y - all_ferz[i].y);
		if (dx == 0 || dy == 0 || (dx  == dy)) return true;
	}
	return false;
}

int main()
{	
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	setlocale(LC_ALL,"RU");
	ofstream FILE;
	FILE.open("output.txt");
	int solution = 0, count_ferz = 0;
	int** field = new int*[N];
	for (int i = 0; i < N; i++) field[i] = new int[N];
	ferzes* all_ferzes = new ferzes[N];
	pole1(field, N);
	


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ferzes temp(j, i);
			bool result = Is_Kill(temp, all_ferzes, count_ferz); //false - can put
			if (!result)
			{
				field[i][j] = 1;
				all_ferzes[count_ferz].x = j;
				all_ferzes[count_ferz].y = i;
				count_ferz++;
				if (count_ferz == N)
				{
					FILE << solution + 1 << '.' << endl;
					In_File(field, N, &FILE);
					FILE << endl;
					
					solution++;
					field[all_ferzes[count_ferz - 1].y][all_ferzes[count_ferz - 1].x] = 0;
					i = all_ferzes[count_ferz - 1].y;
					j = all_ferzes[count_ferz - 1].x;
					count_ferz--;
					if((j + 1) == N && count_ferz != 0)
					{
						field[all_ferzes[count_ferz - 1].y][all_ferzes[count_ferz - 1].x] = 0;
						i = all_ferzes[count_ferz - 1].y;
						j = all_ferzes[count_ferz - 1].x;
						count_ferz--;
					}
					continue;
				}
				break;
			}
			else if ((j + 1) == N)
			{
				field[all_ferzes[count_ferz - 1].y][all_ferzes[count_ferz - 1].x] = 0;
				i = all_ferzes[count_ferz - 1].y;
				j = all_ferzes[count_ferz - 1].x;
				count_ferz--;
				if ((j+1) == N && count_ferz != 0)
				{
					field[all_ferzes[count_ferz - 1].y][all_ferzes[count_ferz - 1].x] = 0;
					i = all_ferzes[count_ferz - 1].y;
					j = all_ferzes[count_ferz - 1].x;
					count_ferz--;
				}
			}
		}
	}
	cout<<"solution count ="<<solution;

	for (int i = 0; i < N; i++) delete field[i];
	delete[] field;
	delete[] all_ferzes;
	FILE.close();
	system("notepad output.txt");
	return 0;
}
