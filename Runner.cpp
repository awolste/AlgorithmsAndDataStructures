// Runner.cpp Andrew Wolstenholme
#include <iostream>
using namespace std;
#include "MySentence.h"
#include "Corpus.h"

int main(){
	string name = "";
	string line = "";
	cout << "Enter file name for corpus: ";
	getline(cin, name);	//helps account for spaces
	ifstream infile;	
	infile.open(name);
	Corpus corpus = Corpus(infile);	//corp obj. if default props, send no arg
	cout << "\n" << "Enter sentence terminated by <ENTER>";
	getline(cin, line);
	MySentence mySentence = MySentence(line); //send sentence to be decoded
	mySentence.decode(corpus);
	cout << "Decoded sentence is: " << mySentence;
	return 0;
}
