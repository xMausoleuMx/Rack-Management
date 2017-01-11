#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool canMake(string rack, string phrase);
string canMake(string rack);
string maxScore(string rack);
int scoreWord(string phrase, string rack);


fstream reader;

int main()
{
	string rack, phrase, holder;
	int choice = 0;
	while (1)
	{
		std::cout << "Enter in your current scrabble rack\nType exit to exit\n";
		std::cin >> rack;
		if (!rack.compare("exit"))
			break;
		std::cout << "Do you wish to \n1. See if you can make a word with your current Rack\n2. Check the longest word you can make with your Rack\n3. See the largest score you can get with your Rack\n";
		std::cin >> choice;
		switch(choice)
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
			holder = canMake(rack);
			cout << holder << " is the longest word you can make with your current rack and is worth " << scoreWord(holder, rack) << " points!\n";
			break;
		case 3:
			holder = maxScore(rack);
			cout << holder << " is the highest scoring word you can make with your current rack and is worth " << scoreWord(holder, rack) << " points!\n";
			break;
		default:
			std::cout << "You entered an invalid choice try again\n";
			break;
		}
	}
}

string maxScore(string rack)
{
	string highScore,temp;
	int points = 0, holder;
	reader.open("enable1.txt");
	while (getline(reader, temp))
	{
		if (canMake(rack, temp))
		{
			holder = scoreWord(temp, rack);
			if (points < holder)
			{
				points = holder;
				highScore = temp;
			}
		}

	}
	return highScore;
}

int scoreWord(string phrase, string rack)
{
	int scores[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
	int score = 0;
	for (int i = 0; i < phrase.size(); i++)
	{
		for (int z = 0; z < rack.size(); z++)
		{
			if (phrase[i] == rack[z])
			{
				rack[z] = 0;
				score += scores[phrase[i] - 'a'];
				break;
			}
		}
	}
	return score;
}

bool canMake(string rack, string phrase)
{
	if (rack.size() < phrase.size())
		return false;
	string copy = phrase;
	bool flag = false;
	for(int i = 0; i < phrase.size(); i++)
	{
		for (int z = 0; z < rack.size(); z++)
		{
			if (phrase[i] == rack[z])
			{
				rack[z] = 0;
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			for (int z = 0; z < rack.size(); z++)
				if (rack[z] == '?')
					break;
			return false;
		}
		flag = false;
	}
	return true;
}

string canMake(string rack)
{



	return "blank for now";
}