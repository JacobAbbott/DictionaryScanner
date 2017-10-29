#include "Noun.h"
#include "Verb.h"

#ifndef  NOUNANDVERB_H
#define NOUNANDVERB_H


class NounAndVerb : public Noun {
	private:
		string type;
		Verb v;
	public:
		NounAndVerb() :Noun() { type = ""; v = Verb(); }
		NounAndVerb(string word, string definition, string type) :Noun(word, definition, "n") {
			v = Verb(word, definition, type);
		}
		//get definition of word
		string getDefinition()
		{
			return "(" + type + ".) " + Word::getDefinition();
		}

		bool isVerb()
		{
			return true;
		}

		bool isNoun()
		{
			return true;
		}
		string getType() { return type; }
		void setType(string type) { this->type = type; }

};
#endif // ! NOUNANDVERB_H