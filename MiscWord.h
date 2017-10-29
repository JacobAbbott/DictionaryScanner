#include "Word.h"

#ifndef MISCWORD_H
#define MISCWORD_H

class MiscWord : public Word {
private:
	string type;
public:
	MiscWord() :Word() {}
	MiscWord(string word, string definition, string type) :Word(word, definition) { this->type = type; }
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