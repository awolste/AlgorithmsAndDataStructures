//Corpus.cpp Andrew Wolstenholme 2121
#include "Corpus.h"
using namespace std;

Corpus::Corpus() : props{0.09, 0.02, 0.02, 0.04, 0.12, 0.02, 0.03,
		 0.02, 0.09, 0.01, 0.01, 0.04, 0.02, 0.06,
		 0.08, 0.02, 0.01, 0.06, 0.04, 0.06, 0.04,
		 0.02, 0.02, 0.01, 0.02, 0.01} {

	cout << "Frequencies are ";
	for(int i = 0; i < 26; i++)
		cout << props[i] << ", ";
}
	//use initializer list and print array


Corpus::Corpus(ifstream& input) {
	string temp = "";
	string line = "";
	while (!input.eof()){	//be sure to take all of the infile
		input >> temp;
		line += temp;
	}
	char c;
	for (unsigned int i = 0; i < line.length(); i++){
		c = line.at(i);
		if (c < 123 && c > 96){
			props[c - 97] ++;
		}
		else if (c < 91 && c > 64){
			props[c - 65] ++;
		}	//account for upper and lower, but not other chars
	}
	for (int j = 0; j < 26; j++){
		props[j] = props[j]/(line.length());
	}	//find relative proportion
	cout << "Frequencies are ";
	for(int x = 0; x < 26; x++)
		cout << props[x] << ", ";
}



double Corpus::proportion(char c){
	if ((c>96) && (c<123)){
		return props[c - 97];
	}
	else if (c < 91 && c > 64){
		return props[c - 65];
	}
	return 0;
}

double* Corpus::getArr(){
	return props;
} //used to access proportion array in non member functions
