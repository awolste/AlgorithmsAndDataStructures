//MySentence.cpp Andrew Wolstenholme 2121
#include "MySentence.h"
using namespace std;

MySentence::MySentence(string str) : sentence(str){}

//initializer list, no code necessary

void MySentence::reverse(){
	string temp = sentence;
	for (unsigned int i = 0; i < sentence.length(); i++){
		temp.at(i) = sentence.at(sentence.length() - 1 - i);
	}	
	sentence = temp;
}
//swap end letters with beggining letters. set sentence to the new string


char MySentence::rotationOf(char c){
	if (c == 90)
		return 'A';
	else if (c == 122)
		return 'a';
	else if ((c < 123 && c > 96) || (c < 91 && c > 64))
		return c + 1;
	else 
		return c;
}
//changes capitals to capitals and lower case to lower. if z, goes to a


void MySentence::rotate(){
	for (unsigned int i = 0; i < sentence.length(); i++){
		sentence.at(i) = rotationOf(sentence.at(i)); 
	}
}
//uses above funtion, loops through each letter


void MySentence::rotate(int timesRot){
	for (int i = 0; i < timesRot; i++){
		for (unsigned int j = 0; j < sentence.length(); j++){
			sentence.at(j) = rotationOf(sentence.at(j)); 
		}
	}
}
//does the same as rotate but does this the designated amount of times.


bool MySentence::operator==(MySentence & obj){
	for (unsigned int i = 0; i < sentence.length(); i++){
		if (sentence.at(i) != obj.sentence.at(i))
			return false;
	}
	return true;
}
//compares two sentences by looking at each letter in the same locations


double MySentence::scoreWith(Corpus &corp){
	double sum = 0;			//cant access corpus otherwise
	double* array = corp.getArr(); //make a copy of array pointer
	for (unsigned int i = 0; i < sentence.length(); i++){
		if (sentence.at(i) < 123 && sentence.at(i) > 96){
			sum += array[sentence.at(i) - 97];
		}	//only add decimal proportion if a letter
		else if (sentence.at(i) < 91 && sentence.at(i) > 64){
			sum += array[sentence.at(i) - 65];
		}	//ifs for capital and lower
	}
	return sum;
}



void MySentence::decode(Corpus& corpus){
	rotate();
	double max = scoreWith(corpus); //1st rotation
	int times = 1;
	double x;
	for (int i = 2; i < 27; i++){
		rotate();
		x = scoreWith(corpus);
		if (x > max){
			max = x;
			times = i;
		}		
	}
	rotate(times);
	reverse();
}
//calls rotate functions, reverse and scoreWith 
//rotates until it is known which combo has the highest sum of proportions


ostream & operator<<(ostream & out, MySentence & obj){
	out << obj.sentence << "\n";
	return out;
} //prints sentence as a friend


