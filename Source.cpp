#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

void LoadArrays(char [], char [], char [], char []);
void MakePassword(bool, bool, bool, bool, char[], int, char[], char[], char[], char[]);

int main()
{
	srand(time(NULL));
	char Lower[26], Upper[26], Nums[10], Chartrs[32], YorN;
	char* Password;
	int Length, i = 0, num = 0;
	bool Up = true, Low = true, Numb = true, Chart = true;

	LoadArrays(Lower, Upper, Nums, Chartrs);
	
	cout << "How long do you want your password(length from 6-32)?";
	cin >> Length;
	while (Length <= 0 || Length > 32)
	{
		cout << "Out of range. Try again:";
		cin >> Length;
	}
	Password = new char [Length];
	
	cout << "Do you want uppercase characters? (y/n)";
	cin >> YorN;
	while (YorN != 'y' && YorN != 'Y' && YorN != 'n' && YorN != 'N')
	{
		cout << "Invalid character. Try again:";
		cin >> YorN;
	}
	if (YorN == 'n' || YorN == 'N')
	{
		Up = false;
	}

	cout << "Do you want lowercase characters? (y/n)";
	cin >> YorN;
	while (YorN != 'y' && YorN != 'Y' && YorN != 'n' && YorN != 'N')
	{
		cout << "Invalid character. Try again:";
		cin >> YorN;
	}
	if (YorN == 'n' || YorN == 'N')
	{
		Low = false;
	}

	cout << "Do you want numbers? (y/n)";
	cin >> YorN;
	while (YorN != 'y' && YorN != 'Y' && YorN != 'n' && YorN != 'N')
	{
		cout << "Invalid character. Try again:";
		cin >> YorN;
	}
	if (YorN == 'n' || YorN == 'N')
	{
		Numb = false;
	}

	cout << "Do you want other characters ex. !@#$? (y/n)";
	cin >> YorN;
	while (YorN != 'y' && YorN != 'Y' && YorN != 'n' && YorN != 'N')
	{
		cout << "Invalid character. Try again:";
		cin >> YorN;
	}
	if (YorN == 'n' || YorN == 'N')
	{
		Chart = false;
	}

	MakePassword(Up, Low, Numb, Chart, Password, Length,Lower, Upper, Nums, Chartrs);
	
	cout << "Your random password is: ";
	for (i = 0; i < Length; i++)
	{
		cout << Password[i];
	}
	cout << '\n';
	
	delete[] Password;
	system("pause");
	return 0;
}

void LoadArrays(char Lower[], char Upper[], char Nums[], char Chartrs[])
{
	int i;
	char data[94];
	ifstream Chars;
	Chars.open("Chars.txt");
	for (i = 0; i < 94; i++)
	{
		Chars >> data[i];
	}
	for (i = 0; i < 26; i++)
	{
		Lower[i] = data[i];
	}
	for (i = 0; i < 26; i++)
	{
		Upper[i] = data[i + 26];
	}
	for (i = 0; i < 10; i++)
	{
		Nums[i] = data[i + 52];
	}
	for (i = 0; i < 32; i++)
	{
		Chartrs[i] = data[i + 62];
	}
	Chars.close();
}

void MakePassword(bool Up, bool Low, bool Numb, bool Chart, char Password[], int length, char Lower[], char Upper[], char Nums[], char Chartrs[])
{
	int i = 0, num;
	if (Up && Low && Numb && Chart)
	{
		while (length > i)
		{
			
			num = rand() % 4 + 1;

			switch (num)
			{
			case 1:
				Password[i] = Lower[rand() % 26];
				break;
			case 2:
				Password[i] = Upper[rand() % 26];
				break;
			case 3:
				Password[i] = Nums[rand() % 10];
				break;
			case 4:
				Password[i] = Chartrs[rand() % 32];
				break;
			}
			
			i++;

		}
	}
	else if(Up && Low && Numb)
	{
		while (length > i)
		{

			num = rand() % 3 + 1;

			switch (num)
			{
			case 1:
				Password[i] = Lower[rand() % 26];
				break;
			case 2:
				Password[i] = Upper[rand() % 26];
				break;
			case 3:
				Password[i] = Nums[rand() % 10];
				break;
			}

			i++;

		}
	}
	else if (Up && Low && Chart)
	{
		while (length > i)
		{

			num = rand() % 3 + 1;

			switch (num)
			{
			case 1:
				Password[i] = Lower[rand() % 26];
				break;
			case 2:
				Password[i] = Upper[rand() % 26];
				break;
			case 3:
				Password[i] = Chartrs[rand() % 32];
				break;
			}

			i++;

		}
	}
	else if (Up && Numb && Chart)
	{
		while (length > i)
		{

			num = rand() % 3 + 1;

			switch (num)
			{
			case 1:
				Password[i] = Upper[rand() % 26];
				break;
			case 2:
				Password[i] = Nums[rand() % 10];
				break;
			case 3:
				Password[i] = Chartrs[rand() % 32];
				break;
			}

			i++;

		}
	}
	else if(Low && Numb && Chart)
	{
		while (length > i)
		{

			num = rand() % 3 + 1;

			switch (num)
			{
			case 1:
				Password[i] = Lower[rand() % 26];
				break;
			case 2:
				Password[i] = Nums[rand() % 10];
				break;
			case 3:
				Password[i] = Chartrs[rand() % 32];
				break;
			}

			i++;

		}
	}
	else if (Up && Low)
	{
		while (length > i)
		{

			num = rand() % 2 + 1;

			switch (num)
			{
			case 1:
				Password[i] = Lower[rand() % 26];
				break;
			case 2:
				Password[i] = Upper[rand() % 26];
				break;
			}
			i++;

		}
	}
	else if (Up && Numb)
	{
		while (length > i)
		{

			num = rand() % 2 + 1;

			switch (num)
			{
			case 1:
				Password[i] = Upper[rand() % 26];
				break;
			case 2:
				Password[i] = Nums[rand() % 10];
				break;
			}

			i++;

		}
	}
	else if (Up && Chart)
	{
		while (length > i)
		{

			num = rand() % 2 + 1;

			switch (num)
			{
			case 1:
				Password[i] = Upper[rand() % 26];
				break;
			case 2:
				Password[i] = Chartrs[rand() % 32];
				break;
			}

			i++;

		}
	}
	else if (Low && Numb)
	{
		while (length > i)
		{

			num = rand() % 2 + 1;

			switch (num)
			{
			case 1:
				Password[i] = Lower[rand() % 26];
				break;
			case 2:
				Password[i] = Nums[rand() % 10];
				break;
			}

			i++;

		}
	}
	else if (Low && Chart)
	{
		while (length > i)
		{

			num = rand() % 2 + 1;

			switch (num)
			{
			case 1:
				Password[i] = Lower[rand() % 26];
				break;
			case 2:
				Password[i] = Chartrs[rand() % 32];
				break;
			}

			i++;

		}
	}
	else if(Numb && Chart)
	{
		while (length > i)
		{

			num = rand() % 2 + 1;

			switch (num)
			{
			case 1:
				Password[i] = Nums[rand() % 10];
				break;
			case 2:
				Password[i] = Chartrs[rand() % 32];
				break;
			}

			i++;

		}
	}
	else if (Numb)
	{
		for (i = 0; i < length; i++)
		{
			Password[i] = Nums[rand() % 10];
		}
	}
	else if (Up)
	{
		for (i = 0; i < length; i++)
		{
			Password[i] = Upper[rand() % 10];
		}
	}
	else if (Low)
	{
		for (i = 0; i < length; i++)
		{
			Password[i] = Lower[rand() % 10];
		}
	}
	else if (Chart)
	{
		for (i = 0; i < length; i++)
		{
			Password[i] = Chartrs[rand() % 10];
		}
	}
}