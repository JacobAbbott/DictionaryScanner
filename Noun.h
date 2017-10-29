#include "Word.h"

#ifndef NOUN_H
#define NOUN_H
class Noun : public Word {
private:
	string type;
public:
	Noun() :Word() { type = ""; }
	Noun(string word, string definition, string type) : Word(word, definition) {this->type = type;	}
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
		return true;
	}
	string getType() { return type; }
	void setType(string type) { this->type = type; }
};
#endif