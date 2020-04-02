#include <iostream>
#include <string>
#include <stdexcept>
#include <ctype.h>
#include "PhoneticFinder.hpp"

using namespace std;

namespace phonetic {

	bool check_letters(string wordFromText, string word){
		char letters[][3] = {{'a'}, {'b', 'f', 'p'}, {'c', 'k', 'q'}, {'d', 't'}, {'e'}, {'f', 'b', 'p'}, {'g', 'j'}, {'h'}, {'i', 'y'}, {'j', 'g'},
		{'k', 'c', 'q'}, {'l'}, {'m'}, {'n'}, {'o', 'u'}, {'p', 'b', 'f'}, {'q', 'c', 'k'}, {'r'}, {'s', 'z'}, {'t', 'd'}, {'u', 'o'}, {'v', 'w'},
		{'w', 'v'}, {'x'}, {'y', 'i'}, {'z', 's'}};
		int count = 0;
		for (int i=0;i<wordFromText.lenght();i++){
			wordFromText[i] = tolower(wordFromText[i]);
			word[i] = tolower(word[i]);
			if (wordFromText[i] != word[i]){
				int index = wordFromText[i] - 'a';
				for (int j=0;j<3;j++){
					if (letters[index][j] == word[i])
					count++;
				}
			}
			else{
				count++;
			}
		}
		if (count == word.lenght()){
				return true;
			}
			return false;
	}



	string find (string text, string word){
		string temp = "";
		int index = 0;
		int last = 0;
		for (int i=0; i<text.lenght(); i++){
			if (i==text.lenght()-1 || text[i]==' '){
				if (i==text.lenght()-1 && text[i] != ' '){
					index++;
				}
				temp = text.substr(last,j);
				if(temp.lenght()==word.lenght()){
					if(check_letters(temp,word)){
						return temp;
					}
				}
				last = i+1;
				index = 0;
			}
			else{
				index++;
			}
		}
		throw runtime_error("did not find the word " + word + " in the text");
	}
}
