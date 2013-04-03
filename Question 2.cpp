#include <iostream>
#include <cctype>
#include <fstream>
#include <string>

using namespace std;

void encrypt(string infile, string outfile);
char ceaserCipher(char c,int key);
void decrypt(string infile, string outfile);
char ceaserDecipher(char c, int key);

void displayMenu()
{
  char quit;
  do {
  cout << "\nWelcome to ENGR1200U Cryptographic Techniques Program\n\n";
  cout << "Please enter your selection:\n\n";
  cout << "\t1. Encript\n";
  cout << "\t2. Decrypt\n";
 

  int selection;
  cin >> selection;

  if (selection == 1)
  { 
    string inputfile, outputfile;
    cout << "Please enter the file you would like the encrypt: ";
    cin >> inputfile;
    cout << "Please enter the file you would like the encrypted text to be held in: ";
    cin >> outputfile;

    encrypt(inputfile, outputfile);
  }
  if (selection == 2)
  {
    string inputfile, outputfile;
    cout << "Please enter the file you would like the decrypt: ";
    cin >> inputfile;
    cout << "Please enter the file you would like the decrypted text to be held in: ";
    cin >> outputfile;

    decrypt(inputfile, outputfile);
  }
 
  cout << "If you would like to quit press 'q', if not press any key and you will be returned to the main menu.\n\n";
  cin >> quit;

  } while( quit != 'q');
}

void encrypt(string infile, string outfile)
{
  ifstream inputfile;
  ofstream outputfile;
  
  inputfile.open(infile.c_str());
  outputfile.open(outfile.c_str());

  while(!inputfile.eof())
  {
    char letters = inputfile.get();
    outputfile << ceaserCipher(letters, 5);
  }
}
void decrypt(string infile, string outfile)
{
  ifstream inputfile;
  ofstream outputfile;

  inputfile.open(infile.c_str());
  outputfile.open(outfile.c_str());

  while(!inputfile.eof())
  {
    char letters = inputfile.get();
    outputfile << ceaserDecipher(letters, 5);
  }
}

char ceaserCipher(char c,int key)
{
  if (isalpha(c))
  {
   c = (c - 'A' + key) % 26 + 'A';
  } 
  else if (ispunct(c))
  {
	c = c;
  }
  else if(c == 10)
  {
	 c = c;
  }
  else if(c = 32)
  {
	  c = c;
  }
  return c;
}
char ceaserDecipher(char c,int key)
{
  if (c >= 69 && c <= 90)
	{
	c = (c - 'A') % 26 + 'A' - key;
	} 
	else if(c == 'B')
	{
		c = 'W';
	}
	else if(c == 'D')
	{
		c = 'Y';
	}
	else if (ispunct(c))
	{
		c = c;
	}
	else if (c == 32)
	{
		c = c;
	}
	else if (c == 10)
	{
		c = c;
	}
	else if (!(isalnum(c) || ispunct(c)))
	{
		c = ' ';
	}   
  return c;
}


int main()
{
  
  displayMenu();
  return 0;
}












