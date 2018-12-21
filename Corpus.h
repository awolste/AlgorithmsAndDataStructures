//Andrew Wolstenholme 2120
// Corpus.h
#ifndef CORPUS_H
#define CORPUS_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


class Corpus{
  public:
	Corpus();
	Corpus(ifstream& input);
	double proportion(char c);
	double* getArr();

  private:
	double props[26];
};
//have to get sentence class to recognize a corpus obj
#endif
