#include "Tri-grams.h"

Trigrams::Trigrams()
{
	this->trigrams = vector<tri>();
	populateData();
	Sort();
}

//sort elements for median
void Trigrams::Sort()
{

	for (int i = 0; i < trigrams.size(); i++)
	{

		for (int j = i + 1; j < trigrams.size(); j++)
		{

			if (trigrams[j].count > trigrams[i].count)

			{

				tri temp;

				temp = trigrams[i];

				trigrams[i] = trigrams[j];

				trigrams[j] = temp;

			}
		}
	}

}

void Trigrams::populateData()
{
	fstream inputFile;
	string line;

	inputFile.open("trigramdict.txt");
	while (getline(inputFile, line))
	{
		if (line.size() > 2)
		{
			for (int i = 0; i < line.size() - 2; i++)
			{
				string word ="";
				word += line[i];
				word += line[i + 1];
				char c= line[i + 2];
				find(word, c);
			}
		}
		for(int i=0;i<3;i++)
			getline(inputFile, line);
	}
}

void Trigrams::getChars(string word)
{
	
	int count = 0;
	bool found = false;
	cout << "Third Characters are \n";
	for(int i=0;i<trigrams.size();i++)
	{
		if (count == 3)
			break;
		if (word == trigrams.at(i).pair)
		{
			if (tolower(trigrams.at(i).thirdchar) >= 'a' && tolower(trigrams.at(i).thirdchar) <= 'z')
			{
				cout << trigrams.at(i).thirdchar << endl;
				found = true;
				count++;
			}
		}
	}
	if (!found)
		cout << "\nNo pair found in th dictionay with third letter\n ";
}

void Trigrams::find(string word, char c)
{
	for (int i = 0; i < trigrams.size(); i++)
	{
		if (trigrams.at(i).thirdchar == c && trigrams.at(i).pair.compare(word) == 0)
		{
			trigrams.at(i).count++;
			return;
		}
	}

	tri temp;
	temp.pair = word;
	temp.thirdchar = c;
	temp.count = 1;
	trigrams.push_back(temp);
}

void Trigrams::generateWords()
{
	cout << "Words are \n";
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		string word = "";
		for (int j = 0; j < i % 6 +3; j++)
		{
			int numb = rand() % trigrams.size();
			word += trigrams.at(numb).pair + trigrams.at(numb).thirdchar;
		}
		cout << word << endl;
	}
}
