// YChoiAssignment2.cpp : Pig Latin Translator
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool avowel(char);
string append(string);
string pigLatintranslate(string);

int main()
{
	char doOver = 'y';

	while (doOver == 'Y' || doOver == 'y')
	{
		string str;
		cout << "Enter the word you would like to translate: (Max 50 Character) " << endl;
		cin >> str;
		//Checks the length of the string
		if (str.length() > 47)
		{
			cout << "Too long. Please enter a shorter word:" << endl;
		}
		//Checks if the string begins with a number
		else if ((str[0] == '1' || str[0] == '2' || str[0] == '3' || 
			      str[0] == '4' || str[0] == '5' || str[0] == '6' || 
			      str[0] == '7' || str[0] == '8' || str[0] == '9' || str[0] == '0'))
		{
			cout << "Do not begin with a letter. Use Letters Only" << endl;
		}
		else
		{
		//Outputs the pig latin
			cout << pigLatintranslate(str) << endl;
		}
		cout << "Translate another word? (Input Y to do it again, N to Exit): " << endl;
		cin >> doOver;
	}
}

	
//Creates a string
string append(string str)
{
	string::size_type len = str.length();
	string str0;
	str0 = str.substr(1, len - 1) + str[0];
	return str0;
}

bool avowel(char vowel)
{//Checks to see if the word begins with a vowel
	switch (vowel)
	{
	case 'A': case 'a': case 'E': case 'e': case 'I':
	case 'i': case 'O': case 'o': case 'U': case 'u': case 'Y': case 'y':
		return true;
	default:
		return false;
	}
}

string pigLatintranslate(string str)
{
	bool vowel;
	string::size_type length;
	string::size_type counter;
	//Checks for the exceptions ot the rule
	if (avowel(str[0]))
		str = str + "ay";
	else if (str == "yet" || str == "the" || str == "but" || str == "nor"
		|| str == "for" || str == "THE" || str == "YET"
		|| str == "BUT" || str == "FOR" || str == "NOR")
	{
		str = str;
	}
	//Checks if the string is less than 2 characters
	else if (str.length() <= 2)
	{
		str = str;
	}
	else
	{
		str = str + "";
		str = append(str);
		length = str.length(); vowel = false;
		for (counter = 1; counter < length - 1; counter++)
		// Case for vowels
			if (avowel(str[0]))
			{
				vowel = true;
				break;
			}
		//Case for consonants
			else
				str = append(str);
		if (!vowel)
			str = str.substr(1, length) + "ay";
		else
			str = str + "ay";
	}
	return str;
}