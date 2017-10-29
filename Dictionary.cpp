/*
Dictionary.cpp
Definition of Dictionary class functions
*/


#include <fstream>
#include<iostream>
#include "Dictionary.h"


//Null Constructor to initialize data members
Dictionary::Dictionary()
{
	dictionary = vector<Word*>();
}

//load data from text file parse it and create Word objects
//store words to dictionary (list of Word class objects)
void Dictionary::loadDictionary()
{
	ifstream inputFile;
	string line;
	inputFile.open("dictionary.txt");

	while (getline(inputFile,line))
	{
		
		string head = line;
		string definition;
		string type;
		getline(inputFile, line);
 		definition = line ;
		getline(inputFile, line);
		type = line;

		createObject(head, definition, type);

		getline(inputFile, line);
	}
	inputFile.close();
}

void Dictionary::createObject(string head, string definition, string type)
{
	Word *word;
	
	if (type == "n")
		word = new Noun(head, definition, type);
	else if (type == "v")
		word = new Verb(head, definition, type);
	else if (type == "adv")
		word = new Adverb(head, definition, type);
	else if (type == "adj")
		word = new Adjective(head, definition, type);
	else if (type == "misc")
		word = new MiscWord(head, definition, type);
	else if (type == "prep")
		word = new Preposition(head, definition, type);
	else if (type == "n_and_v")
		word = new NounAndVerb(head, definition, type);
	else if (type == "p n")
		word = new ProperNoun(head, definition, type);
	else
		word = new Word(head, definition);

	dictionary.push_back(word);
}

//Return the total words in dictionary
int Dictionary::getTotalwords()
{
	return dictionary.size();
}

//Find and display the definition of any word if not found display not found message
void Dictionary::getDefinition(string word)
{
	for (int i = 0; i < dictionary.size(); i++)
	{
		if (dictionary.at(i)->getWord() == word)
		{
			cout << "\nDefinition: \n";
			showDefinition(dictionary.at(i)->getDefinition()) ;
			return;
		}
	}
	cout << "\nThe word not found in dictionary .... \n";
}

//return dictionary of words
vector<Word*> Dictionary::getDictionary()
{
	return dictionary;
}

int Dictionary::findWord(string word)
{
	for (int i = 0; i < dictionary.size(); i++)
	{
		if (dictionary.at(i)->getWord() == word)
			return i;
	}
	return -1;
}

//Count letter occurrences in a word
int Dictionary::countLetters(string word, char character)
{
	int count = 0;
	for (int i = 0; i < word.size(); i++)
	{
		if (tolower(word[i]) == tolower(character))
			count++;
	}

	return count;
}

//check if a letter is followed by another letter in word
bool Dictionary::checkLetters(string word, char letter, char follower)
{
	bool found = true;
	for (int i = 0; i < word.size()-1; i++)
	{
		if (tolower(word[i]) == tolower(letter))
		{
			found = false;
			if (tolower(word[i + 1]) == tolower(follower))
				return true;
		}
	}
	return found;
}

//Find and display the words with more than 3 Z''s
void Dictionary::getTripleZ()
{
	vector<Word> dictionary;
	bool found = false;
	for (int i = 0; i < dictionary.size(); i++)
	{
		if (countLetters(dictionary.at(i).getWord(), 'z') > 3)
		{
			cout << dictionary.at(i).getWord() << endl;
			found = true;
		}
	}
	if (!found)
		cout << "\nThere is no word with more than 3 Z .... \n";
}

//Find and display word(s) with q not followed by u
void Dictionary::qNextU()
{
	bool found = false;
	for (int i = 0; i < dictionary.size() - 1; i++)
	{
		string word = dictionary.at(i)->getWord();
		if (!checkLetters(word, 'q', 'u'))
		{
			cout << word << endl;
			found = true;
		}
	}
	if (!found)
		cout << "\nThere is no word having q not followed by u .... \n";
}

//Display the entire dictionary with serial numbers
void Dictionary::displayDictionary()
{
	for (int i = 0; i < dictionary.size();i++)
		cout << i << endl << dictionary.at(i)->getWord() << endl << dictionary.at(i)->getDefinition()<<endl;
}

void Dictionary::findNounAndVerb()
{
	bool found = false;
	for (int i = 0; i < dictionary.size(); i++)
	{
		if (dictionary.at(i)->isVerb() && dictionary.at(i)->isNoun())
		{
			found = true;
			cout << dictionary.at(i)->getWord() << endl;
		}
	}
	if (!found)
		cout << "There are no nouns and verbs\n";

}

void Dictionary::findAllPalindromes()
{
	for (int i = 0; i < dictionary.size(); i++)
	{
		if (dictionary.at(i)->isPalindrome())
		{
			cout << dictionary.at(i)->getWord() << endl;
		}
	}
}

int Dictionary::getCharCount(string word, char c)
{
	int count = 0;

	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == c)
			count++;
	}

	return count;
}

bool Dictionary::isNgram(string word, string dicword)
{
	if(word.size() != dicword.size())
		return false;

	for (int i = 0; i < word.size(); i++)
	{

		if (getCharCount(word, word[i]) != getCharCount(dicword, word[i]))
			return false;
			
		
	}
	return true;
}

void Dictionary::findAllNgrams(string word)
{
	bool found = false ;
	for (int i = 0; i < dictionary.size(); i++)
	{
		if (isNgram(dictionary.at(i)->getWord(), word))
		{
			if (word != dictionary.at(i)->getWord())
			{
				cout << dictionary.at(i)->getWord() << endl;
				found = true;
			}
		}
	}
	if (!found)
		cout << "\n There are no Ngrams for current word\n";
}

void Dictionary::guessingGame()
{
	Word* word = getRandomNoun();
	string guess;
	string hint = "";
	bool guesssed = false;

	showDefinition(word->getDef());
	for (int i = 0; i < 3; i++)
	{
		cout << "Please guess the noun : ";
		cin >> guess;
		if (guess.compare(word->getWord()) == 0)
		{
			cout << "Well done!! you have guessed correctly:\n";
			guesssed = true;
			break;
		}
		hint += word->getWord()[i];
		cout << hint << endl;
	}

	if (!guesssed)
		cout << "Sorry you could nor guess \n \tThe Noun is " << word->getWord();
	
}

Word* Dictionary::getRandomNoun()
{
	int numb;
	srand(time(NULL));
	do {
		numb = rand() % dictionary.size();
	} while (!dictionary.at(numb)->isNoun());

	return dictionary.at(numb);
}

void Dictionary::addWord()
{
	string word;
	string definition;
	string type;
	
	cout << "Please enter the word :";
	cin.ignore();
	getline(cin,word);
	cout << "Please enter definition : ";
	getline(cin, definition);
	cout << "please enter type : ";
	getline(cin,type);

	createObject(word, definition, type);
}


void Dictionary::updateWord()
{
	string word;
	string definition;
	string type;

	cout << "Please enter the word to update: ";
	cin >> word;

	int index = findWord(word);
	if (index == -1)
		cout << "Sorry the word not found..... \n";
	else
	{
		cout << "Please update the fields... Leave empty to remain unchanged \n";
		cout << "Enter the new word: ";
		cin.ignore();
		cin >> word;
		if (!empty(word))
			dictionary.at(index)->setWord(word);
		cout << "Enter the new definition: ";
		cin.ignore();
		getline(cin,definition);
		if (!empty(definition))
			dictionary.at(index)->setDefinition(definition);
		cout << "Enter the type: ";
		getline(cin,type);
		if (!empty(type))
			dictionary.at(index)->setType(type);		
	}
}

void Dictionary::deleteWord()
{
	string word;
	cout << "Please eneter the word to delete : ";
	cin >> word;
	int index = findWord(word);
	if (index == -1)
		cout << "Sorry the word not found..... \n";
	else
	{
		dictionary.erase(dictionary.begin() + index, dictionary.begin() + index+1);
	}

}

void Dictionary::showDefinition(string def)
{
	for (int i = 0; i < def.size(); i++)
	{
		cout << def[i];
		if (def[i] == ';' || def[i] == ')')
			cout << "\n";	
	}
	cout << "\n";
}



