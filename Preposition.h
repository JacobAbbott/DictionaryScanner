#include "MiscWord.h"

#ifndef PREPOSITION_H
#define PREPOSITION_H

class Preposition : public MiscWord {
private:
	string type;
public:
	Preposition() :MiscWord() { this->type = ""; }
	Preposition(string word, string definition, string type) :MiscWord(word, definition, type) { this->type = type; }
	//get definition of word
	string getDefinition()
	{
		return "(" + type + ".) " + definition;
	}

	bool isVerb()
	{
		return false;
	}
	bool isNoun()
	{
		return false;
	}
	string getType() { return type; }
	void setType(string type) { this->type = type; }
};
#endif 
