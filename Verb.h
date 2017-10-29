#include "Word.h"

#ifndef VERB_H
#define VERB_H



class Verb : public Word {
private:
	string type;
public:
	Verb() :Word() { type = ""; }
	Verb(string word, string definition, string type) :Word(word, definition) { this->type = type; }
	//get definition of word
	string getDefinition()
	{
		return "(" + type + ".) " + definition;
	}

	bool isVerb()
	{
		return true;
	}
	bool isNoun()
	{
		return false;
	}
	string getType() { return type; }
	void setType(string type) { this->type = type; }

};
#endif // !VERB_H