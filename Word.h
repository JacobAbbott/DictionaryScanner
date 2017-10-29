#include<string>

using namespace std;
#ifndef WORD_H
#define WORD_H



class Word {

protected:
	//data members declaration
	string word; 
	string definition;

public:
	Word(); // Default Constructor
	Word(string word, string definition); // Parametrized Constructor
	void setWord(string word); //set the word
	void setDefinition(string definition); //set definition
	string getDef(); //return definition
	string getWord(); // Get word string
	virtual string getDefinition(); //get definition of word


	bool isPalindrome();
	virtual bool isVerb();
	virtual bool isNoun();
	virtual string getType();
	virtual void setType(string type) {};

};
#endif // !WORD_H