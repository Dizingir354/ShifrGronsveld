#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <fstream>

using namespace std;

string lib;
string MakeLib()
{
	for (int i = 32; i == 32; i++) //upercace
	{
		lib += (char)i;
	}
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
	for (int i = 192; i <= 255; i++) //upercace		Это единствение руские букви которые я смог найти но это работает, жаль что в консоли они отображаються непонятно в void PrintLib. Без этого русские символы не работают
	{
		lib += (char)i;
	}
	return lib;
}

string encrypt(string str, int key)
{
	int temp;
	string encryptText;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < lib.length(); j++)
		{
			if ((char)str[i] == lib[j]) //находим букву в алфавите
			{
				temp = (j + key) % lib.length();
				encryptText += lib[temp];
			}
		}
	}
	cout << "Зашыфрованый текст: ";
	cout << encryptText << endl;
	return encryptText;
}

void PrintLib(string str)
{
	cout << "Рядом с символами поставлен их порядочний номер" << endl;
	cout << "Все доступные буквы: ";
	for (size_t i = 0; i < str.length(); i++)
	{
		cout << str[i] << i << " ";
		if (i == 51)
		{
			cout << endl;
			cout << "Все доступные цыфри: ";
		}
		if (i == 61)
		{
			cout << endl;
			cout << "Все доступные спецсимволы: ";
		}
		if (i == 83)
		{
			cout << endl;
			cout << "Все доступные русские буквы: ";
		}
	}
	cout << "\n----------------------------------------\n";
}

#define WRITE
int main()
{
	setlocale(LC_ALL, "Russian");
	string OutFiles = "text.txt";
	string InFilesShifr = "text1.txt";
	string InFilesNoShifr = "text2.txt";
	ofstream fileIn;
	ofstream fileInNoShifr;
	ifstream fileOut;
	fileOut.open(OutFiles);
	fileIn.open(InFilesShifr);
	fileInNoShifr.open(InFilesNoShifr);
	if (fileOut.fail())	//открылся ли файл
	{
		cout << "Error openning file!\a\a\a\a\a\a\a" << endl;
		return 404;
	}
	if (fileIn.fail())	//открылся ли файл
	{
		cout << "Error openning file!\a\a\a\a\a\a\a" << endl;
		return 404;
	}
	if (fileInNoShifr.fail())	//открылся ли файл
	{
		cout << "Error openning file!\a\a\a\a\a\a\a" << endl;
		return 404;
	}

	PrintLib(MakeLib());
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str;
	getline(fileOut, str);
	int key;
	string encrText;

	encrText = encrypt(str, key);

	fileIn << encrText << endl;

	return 0;
}