//Jacob Blacklock
//K-Shift Decoder/Encoder
//Program will encode and decode a string of text based on a given number K
//10/17/18

#include <iostream>
#include <string>
#include <typeinfo>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
	
string encrypt(int k, string phrase, int len, string alpha)
{
	for (int i=0;i<len;i++)
	{
		char &letter = phrase[i];
		for (int j=0;j<=25;j++)
		{
			if (letter == alpha[j])
			{	
				if (j<k)
				{
					letter = alpha[j-k+26];
				}
				else
				{
					letter = alpha[j-k];
				}	
				break;
			}
		}
	}
	return phrase;
}
string decrypt(int k, string phrase, int len, string alpha)
{
	for (int i=0;i<len;i++)
	{
		char &letter = phrase[i];
		for (int j=0;j<=25;j++)
		{	
			if (letter == alpha[j])
			{	
				if ((j+k)>25)
				{	
					letter = alpha[j+k-26];
				}	
				else	
				{	
					letter = alpha[j+k];
				}
				break;
			}
		}
	}
	return phrase;
}

int main () 
{
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	char crypt;	
	int k;
	string phrase;
	int len;
	char letter;
	
	cout << "Would you like to encrypt or decrypt? (e/d)" << endl;
	cin >> crypt;
	cout << "What is the secret key K? (number to shift by)" << endl;
	cin >> k;
	cout << "Input your phrase (in lowercase): " << endl;
	cin.ignore();
	getline(cin, phrase);
	len = phrase.length();
	
	if (crypt == 'e')
	{
		string encryption = encrypt(k, phrase, len, alpha);
		cout << "Encrypted phrase: " << encryption << endl;
	}

	if (crypt == 'd')
	{
		string decryption = decrypt(k, phrase, len, alpha);
		cout << "Decrypted phrase: " << decryption << endl;
	}
	
}
