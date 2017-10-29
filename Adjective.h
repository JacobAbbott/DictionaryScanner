#include "Word.h"

#ifndef ADJECTIVE_H
#define ADJECTIVE_H
class Adjective : public Word {
private:
	string type;
public:
	
	Adjective() :Word() {}
	Adjective(string word, string definition, string type) :Word(word, definition) { this->type = type; }
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
