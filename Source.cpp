#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool canMake(string rack, string phrase);
string canMake(string rack);
int scoreWord(string phrase);

int main()
{
	string rack, phrase;
	int choice = 0;
	while (1)
	{
		std::cout << "Enter in your current scrabble rack\n";
		std::cin >> rack;
		if (!rack.compare("exit"))
			break;
		std::cout << "Do you wish to \n1. See if you can make a word with your current Rack\n2. Check the longest word you can make with your Rack\n3. See the largest score you can get with your Rack";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "What word would you like to check?\n";
			std::cin >> phrase;
			if (canMake(rack, phrase))
				std::cout << "You can make that word!\n";
			else
				std::cout << "You cannot make that word!\n";
			break;
		case 2:

			break;
		case 3:

			break;
		default:
			std::cout << "You entered an invalid choice try again";
			break;
		}
	}
}


bool canMake(string rack, string phrase)
{


}

string canMake(string rack)
{


}