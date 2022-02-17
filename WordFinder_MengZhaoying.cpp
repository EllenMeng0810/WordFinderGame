/*Course: COSC 1437 Programming Fundamental Ⅱ*/
/*Subject: Project 1*/
/*Structor: Gregory Rogers*/
/*Student: Zhaoying Meng*/
/*Due: 10/30/2018*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

static string wordlist[5];

void readWords(string fileName);
void removeDuplicate(string , int );
void guessWords();

int main()
{
	ifstream inFile;
	string fileName = "wordlist.txt";
	string words[100];
	string letters = "";
	string guess;
	string correctWordsGuessed[5];
	int index;
	int len;
	int num;
	int counter;

	cout << "Word Finder 1.0" << endl;
	cout << "5 words were read from the file" << endl;
	cout << "Below are the letters to create words from : " << endl;
	cout << endl;

	readWords(fileName);

	/*
	for (index = 0; index < 5; index++)
	{
		cout << wordlist[index] << endl;
	}
	*/
	for (index = 0; index < 5; index++)
	{
		letters = letters + wordlist[index];
	}

	//cout << letters << endl;
	len = letters.length();
	//cout << len << endl;

	removeDuplicate(letters, len);

	guessWords();

	cout << "\nGame over!!!" << endl;

	inFile.close();
	
	system("pause");
}


void removeDuplicate(string str, int n)
{
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (str[i] == str[j])
			{
				for (k = j; k < n; k++)
				{
					str[k] = str[k + 1];
				}
				n--;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
}

void readWords(string fileName)
{
	ifstream inFile;
	string words[10];
    int index;
	int len;

	inFile.open(fileName);
	int i = 0;
	while (i <= 5)
	{
		for (index = 0; index < 10; index++)
		{
			inFile >> words[index];
			len = words[index].length();
			//cout << len << endl;
			if (len < 3 || len > 6)
			{
				i = i - 1;
			}
			if (len >= 3 && len <= 6)
			{
				wordlist[i] = words[index];
			}
			i++;
		}
	}
}

void guessWords()
{
	string guess;
	string correctWordsGuessed[5];
	int index;
	int num;
	int counter;

	num = 0;
	counter = 0;

	while (num < 10)
	{
		while (counter < 5)
		{
			cout << "\nPlease start guessing : ";
			cin >> guess;
			for (index = 0; index < 5; index++)
			{
				if (guess.compare(wordlist[index]) == 0)
				{
					cout << guess << " <- In File" << endl;
					correctWordsGuessed[counter] = guess;
					counter++;
					//cout <<  "counter is" << counter << endl; 
					break;
				}
			}
			if (index == 5)
				cout << guess << " <- Not In File" << endl;
			num++;
		}
		if (counter == 5)
			break;
	}

	cout << "\nBelow are the words that were found:" << endl;
	for (int k = 0; k < 5; k++)
	{
		cout << correctWordsGuessed[k] << " ";
	}
}

