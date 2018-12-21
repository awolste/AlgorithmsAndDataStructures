//Andrew Wolstenholme 2120
//MySentence.h
#ifndef MYSENTENCE_H
#define MYSENTENCE_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Corpus.h"
using namespace std;


class MySentence{
  public:
	MySentence(string str);
	void reverse();
	static char rotationOf(char c);
	void rotate();
	void rotate(int timesRot);
	bool operator==(MySentence & obj);
	friend ostream & operator<<(ostream & out, MySentence & obj);
	double scoreWith(Corpus& corp);
	void decode(Corpus& corp);

  private:
	string sentence;
};

#endif
