#include "Word.h"

#ifndef ADVERB_H
#define ADVERB_H

class Adverb : public Word {
private:
	string type;
public:
	Adverb() :Word() {}
	Adverb(string word, string definition, string type) :Word(word, definition) { this->type = type; }
	//get definition of word
	string getDefinition()
	{
		return "("  + type+ ".) " + definition;
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
#endif // !ADVERB_H
