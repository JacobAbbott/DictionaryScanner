#include<vector>
#include<time.h>
#include<thread>
#include<algorithm>

#include "Verb.h"
#include "Adjective.h"
#include "Adverb.h"
#include "Preposition.h"

#include "ProperNoun.h"
#include "NounAndVerb.h"

#ifndef DICTIONARY_H
#define DICTIONARY_H

class Dictionary {

	// Dictionary as vector of word
	vector<Word*> dictionary;

public:
	Dictionary(); //Default constructor to initialize data member
	void loadDictionary(); //load dictionary from text file
	void createObject(string head, string definition, string type);
	int getTotalwords(); // count of total words in  dictionary
	vector<Word*> getDictionary(); // return dictionary
	int findWord(string word);
	void getDefinition(string word); // get the definition of  given word
	int countLetters(string word, char character); // count number of occurences of a letter in word
	bool checkLetters(string word, char letter, char follower); // Check if a letter is in word and followed by another letter
	void Dictionary::qNextU(); // get words with q followed by u
	void getTripleZ(); // get words with 3 Z
	void displayDictionary(); //display the complete dictionary
	void findNounAndVerb(); //display all nouns and verbs
	void findAllPalindromes(); //display all palindromes
	int getCharCount(string word, char c); // get occurences of a letter in string
	bool isNgram(string word, string dicword); // check if both words are n grams
	void findAllNgrams(string word); //display all ngrams
	void guessingGame(); // Guessing game 
	Word* getRandomNoun(); //Generate a random noun
	void addWord(); //add word ;
	void updateWord(); //updatea word details 
	void deleteWord(); //delete a word 
	void showDefinition(string def);
};
#endif