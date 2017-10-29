#include "Noun.h"


#ifndef PROPER_H
#define PROPER_H


class ProperNoun : public Noun {
private:
	string type;
public:
	ProperNoun() :Noun() { type = ""; }
	ProperNoun(string word, string definition, string type) :Noun(word, definition, type) {}
	//get definition of word
	string getDefinition()
	{
		return "(pn.) " + definition;
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