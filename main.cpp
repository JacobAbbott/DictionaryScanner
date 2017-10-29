#include<iostream>
#include "Dictionary.h"
#include "Tri-grams.h"


void saveData(Dictionary dict)
{
	vector<Word*> dictionary = dict.getDictionary();
	ofstream outFile;
	outFile.open("dictionary.txt", fstream::out);
	for (int i = 0; i < dictionary.size(); i++)
	{
		outFile << dictionary.at(i)->getWord() << endl;
		outFile << dictionary.at(i)->getDef() << endl;
		outFile << dictionary.at(i)->getType() << "\n\n";
	}
	outFile.close();
}

void saveThread(Dictionary dict)
{
	std::thread save (saveData,dict);
	save.join();
}

void populate(Trigrams &tr)
{
	tr.populateData();
}

void populateTrigrams(Trigrams &tr)
{
	thread update(populate, tr);
	update.join();
	return;
}



//show the main menu
void displayMenu()
{
	cout << "a) Find definition \n";
	cout << "b) Find words with more than three z's \n";
	cout << "c) List words with q without following u \n";
	cout << "d) List all nouns and verbs \n";
	cout << "e) List all Palindromes\n";
	cout << "f) Find ngrams of a word\n";
	cout << "g) Guessing Game\n";
	cout << "h) Trigrams\n";
	cout << "i) Add Word\n";
	cout << "j) Update Word\n" ;
	cout << "k) Delete Word\n";
	cout << "q) Quit\n\n";
	cout << "Select one of above: \t";
}

//main function for execution
int main()
{
	Dictionary dict;
	char choice = ' ';
	string searchWord;
	Trigrams tr;

	cout << "Data Loading.......";
	dict.loadDictionary();
	

	do
	{
			
			system("CLS");
			displayMenu();
			cin >> choice;


		switch (choice)
		{
		case 'a':
			cout << "Enter the word to search definition : ";
			cin >> searchWord;
			dict.getDefinition(searchWord);
			break;
		case 'b':
			dict.getTripleZ();
			break;
		case 'c':
			dict.qNextU();
			break;
		case 'd':
			dict.findNounAndVerb();
			break;
		case 'e':
			dict.findAllPalindromes();
			break;
		case 'f':
			cout << "Please Enter the word to check ngrams : ";
			cin >> searchWord;
			dict.findAllNgrams(searchWord);
			break;
		case 'g':
			dict.guessingGame();
			break;
		case 'h':
			do
			{
				cout << "\nPlease enter a pair of characters to get possible third character : ";
				cin >> searchWord;
			} while (searchWord.size() != 2);
			tr.getChars(searchWord);
			tr.generateWords();
			break;
		case 'i':
			dict.addWord();
			saveThread(dict);
			break;
		case 'j' :
			dict.updateWord();
			saveThread(dict);
			break;
		case 'k':
			dict.deleteWord();
			saveThread(dict);
			break;
		case 'q':
			cout << "\nThanks for using....\n";
			break;
		default:
			cout << "\nChoice Invalid....\n";
			break;
		}
		cout << endl;
		system("pause");

	} while (choice != 'q');

	return 0;

}