#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include<io.h>
#include<fstream>
using namespace std;
void RussianMessage(const char* str)
{
	char rmessage[256];
	CharToOemA(str, rmessage);
	cout << rmessage;
}
int RussianMenu()
{
	RussianMessage("\n������� 1 ��� ���������� ����� ��������� ����\n");
	RussianMessage("\n������� 2 ��� ������ ���� �������� �� �����\n");
	RussianMessage("\n������� 3 ��� ������\n");
	int choice;
	cin >> choice;
	return choice;
}
class Man
{
	int age;
	char* name;
	char* surname;
public:
	Man(const char* n, const char* s, int a)
	{
		name = new char[strlen(n) + 1];
		if (!name)
		{
			RussianMessage("������ ��� ��������� ������ !!!");
			exit(1);
		}
		strcpy(name, n);
		surname = new char[strlen(s) + 1];
		if (!surname)
		{
			RussianMessage("������ ��� ��������� ������ !!!");
			exit(1);
		}
		strcpy(surname, s);
		age = a;
	}
	Man()
	{
		name = 0;
		surname = 0;
		age = 0;
	}
	~Man()
	{
		delete[] name;
		delete[] surname;
	}
	void Put()
	{
		char temp[1024];
		RussianMessage("\n������� !!!\n");
		cin >> temp;
		if (name)
		{
			delete[] name;
		}
		name = new char[strlen(temp) + 1];
		if (!name)
		{
			RussianMessage("������ ��� ��������� ������ !!!");
			exit(1);
		}
		strcpy(name, temp);
		RussianMessage("\n������� �������:\n");
		cin >> temp;
		if (surname)
		{
			delete[]surname;
		}
		surname = new char[strlen(temp) + 1];
		if (!surname)
		{
			RussianMessage("������ ��� ��������� ������ !!!");
			exit(1);
		}
		strcpy(surname, temp);
		RussianMessage("\n������� �������\n");
		cin >> age;
	}
	void Show()
	{
		RussianMessage("\n���\n");
		cout << name;
		RussianMessage("\n�������\n");
		cout << surname;
		RussianMessage("\n�������\n");
		cout << age << endl;
	}
	void SaveToFile()
	{
		int size;
		fstream f("men.txt", ios::out | ios::binary | ios::app);
		if (!f)
		{
			RussianMessage("���� �� �������� ��� ������!!!");
			exit(1);
		}
		f.write((char*)&age, sizeof(age));
		size = strlen(name);
		f.write((char*)&size, sizeof(int));
		f.write((char*)&name, sizeof(char));
		size = strlen(surname);
		f.write((char*)&size, sizeof(int));
		f.write((char*)&surname, sizeof(char));
		f.close();
	}
	void ShowFromFile()
	{
		fstream f("men.txt", ios::out | ios::binary );
		if (!f)
		{
			RussianMessage("���� �� �������� ��� ������!!!");
			exit(1);
		}
		char* n, * s;
		int a;
		int temp;
		while (f.read((char*)&a, sizeof(int)))
		{
			RussianMessage("\n���:\n");
			f.read((char*)&temp, sizeof(int));
			n = new char[temp + 1];
			if (!n)
			{
				RussianMessage("������ ��� ��������� ������!!!");
				exit(1);
			}
			f.read((char*)&temp, sizeof(int));
			n [temp ]='\0';
			cout << name;
			
			RussianMessage("\n�������:\n");
			f.read((char*)&temp, sizeof(int));
			s = new char[temp + 1];
			if (!s)
			{
				RussianMessage("������ ��� ��������� ������!!!");
				exit(1);
			}
			f.read((char*)&temp, sizeof(int));
			s [temp] = '\0';
			cout << surname;

			delete[]n;
			delete[]s;
		}
	}
};
void main() 
{
	/*int N;
	int M;
	cin >> N;
	M = N;
	char** sim=new char*[N];
	for (int i = 0; i < N; i++)
	{
		sim[i] = new char[M];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			sim[i][j] = '*';
		}
	}
	int j;
	for (int i = 0; i < N; i++)
	{
		for (j = 0; j <= M ; j++)
		{
			
			if (j==(M/2)-i|| j == (M / 2) + i)
			{
				cout << sim[i][j];
			}
			else
			{
				cout << " ";
			}

		}
		cout << endl;
	}*/

	//int n=10;
	//int m=5;
	//int j;
	//bool t = false;
	//cin >> n;
	//m = n / 2;
	//for (int i = 0; i < n; i++)
	//{
	//	char a = 65;
	//	char z = 90;
	//	for (j = 1; j <= m+1; j++)
	//	{
	//		if (i % 2 == 0)
	//		{
	//			if (j % 2 == 0)
	//			{
	//				cout  << ' ';
	//				
	//			}
	//			else
	//			{
	//				cout << a;
	//				a++;
	//			}
	//		}
	//		else
	//		{
	//			if (j % 2 == 0)
	//			{
	//				cout << z;
	//				z--;
	//				
	//			}
	//			else
	//			{
	//				cout << ' ';
	//			}
	//		
	//		}
	//	}
	//	m--;
	//	if (m==0)
	//	{
	//		t=true;
	//	}
	//	if (t) 
	//	{
	//		m=m+2;
	//	}
	//	cout << endl;
	//}

	/*int num;
	cin >> num;
	for (int i=1;i<=num;i++)
	{
		if (i % 2 == 0)
		{
			cout << i * i;
		}
		else 
		{
			cout << "*";
		}
	}*/
Man* a;
do {
	switch(RussianMenu)
}while()


	
}