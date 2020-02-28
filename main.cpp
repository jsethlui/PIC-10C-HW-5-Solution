//Jeremy Louie
//PIC 10C
//Falcon
//No collaborators
//"I pledge that I have neither given nor received unauthorized assistance on this assignment."

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

//when you play the game or thrones you win or die

//shows words with length 'wordLength' (of type int) in vector
//@param 'stringVector' of type string vector and 'wordLength' of type int
void show(std::vector<std::string> stringVector, int wordLength) {
	long numWords = 0;

	std::sort(stringVector.begin(), stringVector.end());		//sort string vector (makes it computationally easier for compiler)
	std::vector<std::string>::iterator bound;					//declare iterator
	bound = partition(stringVector.begin(), stringVector.end(), [wordLength](std::string str) {return str.size() >= wordLength;});	//from beginning to end of input vector, capture wordLength of type int and return words with length of wordLength

	//Count number of words
	for (std::vector<std::string>::iterator iter = stringVector.begin(); iter != bound; ++iter) {
		numWords++;
	}

	std::cout << "\n" << numWords << " words with size greater than / equal to " << wordLength<< " and they are: \n";

	//from beginning to end of input vector, print each element from bound
	for (std::vector<std::string>::iterator iter = stringVector.begin(); iter != bound; ++iter) {
		std::cout << ' ' << *iter;
	}
}

int main(int argc, const char * argv[]) {
	std::vector<std::string> words;
	std::string word;
	int word_length;
	std::cout << "words = ";
	getline(std::cin, word);
	std::stringstream sentence(word);
	while (sentence >> word) {
		words.push_back(word);
	}
	std::cout << "\n" << "word length = ";
	std::cin >> word_length;
	show(words, word_length);
	
	std::cout << "\n\n";
}

//Output

//words = when you play the game or thrones you win or die
//
//word length = 4
//
//4 words with size greater than / equal to 4 and they are:
//bwhen thrones game play
