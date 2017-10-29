#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<time.h>


using namespace std;
struct tri {
	string pair;
	char thirdchar;
	int count;
};

class Trigrams {
private:
	vector<tri> trigrams;
public:
	Trigrams();
	void Sort();
	void populateData();
	void getChars(string word);
	void find(string word, char c);

	void generateWords();
};