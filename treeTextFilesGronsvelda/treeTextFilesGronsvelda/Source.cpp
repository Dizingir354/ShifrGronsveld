#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <fstream>


using namespace std;

string lib;

string encrypt(string str, string key)
{
	int temp;
	int temp1;
	int temp2;
	string encryptText;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < lib.length(); j++)
		{
			if ((char)str[i] == lib[j]) //������� ����� � ��������
			{
				temp = (j + int(key[i])) % lib.length();
				encryptText += lib[temp];
			}
		}

	}
	
	cout << "������������ �����: ";
	cout << encryptText << endl;
	return encryptText;
}
string dencrypt(string str, string key)
{
	int temp;
	string encryptText;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < lib.length(); j++)
		{
			if ((char)str[i] == lib[j]) //������� ����� � ��������
			{
				//������ �� ������ �� ������ ����
				temp = j - int(key[i]);
				if (temp < 0)
				{
					temp += lib.length();
				}
				else
				{
					temp = (j - int(key[i])) % lib.length();
				}
				encryptText += lib[temp];
			}
		}
	}
	cout << "�������������� �����: ";
	cout << encryptText << endl;
	cout << "\n----------------------------------------\n";
	return encryptText;
}

string MakeLib()
{
	for (int i = 65; i <= 90; i++) //upercace
	{
		lib += (char)i;
	}
	for (int i = 97; i <= 122; i++) //upercace
	{
		lib += (char)i;
	}
	for (int i = 48; i <= 57; i++) //upercace
	{
		lib += (char)i;
	}
	for (int i = 33; i <= 47; i++) //upercace
	{
		lib += (char)i;
	}
	for (int i = 58; i <= 64; i++) //upercace
	{
		lib += (char)i;
	}
	for (int i = 192; i <= 255; i++) //upercace		��� ����������� ������ ����� ������� � ���� ����� �� ��� ��������, ���� ��� � ������� ��� ������������� ��������� � void PrintLib. ��� ����� ������� ������� �� ��������
	{
		lib += (char)i;
	}
	return lib;
}
bool CheckNum(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			cout << "error" << endl;
			return false;
		}
	}
	return true;
}
void PrintLib(string str)
{
	cout << "����� � ��������� ��������� �� ���������� �����" << endl;
	cout << "��� ��������� �����: ";
	for (size_t i = 0; i < str.length(); i++)
	{
		cout << str[i] << i << " ";
		if (i == 51)
		{
			cout << endl;
			cout << "��� ��������� �����: ";
		}
		if (i == 61)
		{
			cout << endl;
			cout << "��� ��������� �����������: ";
		}
		if (i == 83)
		{
			cout << endl;
			cout << "��� ��������� ������� �����: ";
		}
	}
	cout << "\n----------------------------------------\n";
}
void main()
{
	setlocale(LC_ALL, "Russian");
	PrintLib(MakeLib());
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string OutFiles = "standart.txt";
	string InFiles = "Shifr.txt";
	string InFilestwo = "�����.txt";
	ofstream fileIn;
	ifstream fileOut;
	ofstream fileInTwo;
	fileOut.open(OutFiles);
	fileInTwo.open(InFilestwo);
	fileIn.open(InFiles);
	while (true)
	{
		string str;
		getline(fileOut, str);
		cout << "������� ���� �������� � ����� ("<<str.length()<<"): " << endl;
		string key;
		cin >> key;
		string encrText;
		if (CheckNum(key))
		{
			encrText = encrypt(str, key);
		}
		fileIn << encrText<<endl;
		fileInTwo << dencrypt(encrText, key) << endl;
	}
}