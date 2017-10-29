#include "Word.h"

//Default Constructor to initialize data members
Word::Word()
{
	this->word = "";
	this->definition = "";
}

//Parameterized constructor to assign values
Word::Word(string word, string definition)
{
	this->word = word;
	this->definition = definition;
}

void Word::setWord(string word)
{
	this->word = word;
}

void Word::setDefinition(string definition)
{
	this->definition = definition;
}

string Word::getDef()
{
	return definition;
}

//Get current word string
string Word::getWord()
{
	return word;
}

//get definition of word
string Word::getDefinition()
{
	return definition;
}

bool Word::isPalindrome()
{
	for (int i = 0; i < word.size() / 2; i++)
	{
		if (word[i] != word[word.size() - 1 - i])
			return false;
	}
	return true;
}


bool Word::isVerb()
{
	return false;
}

bool Word::isNoun()
{
	return false;
}

string Word::getType()
{
	return "?";
}
