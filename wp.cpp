#include<iostream>
#include<string>
#include<tr1/unordered_map>
#include<fstream>
#include"wp.h" 

using namespace std;



long hash_value(const char* c) {
	long hash = 1;
	int length = 0;
		while(*c){
		if(*c-97 >= 0 && *c <=122){
			hash *= alph_val[*c-97];
		} 
		length++;
		*c++;
	}
	return hash % 27*length;
}


int main(){
	ifstream wordfile;
	string word;
	wordfile.open("words.txt");
	cout << hash_value("ASSzzzzzzzzzzzzz");
	
	if(!wordfile.is_open()){
		while( getline(wordfile,word))
			{
				long  hash = hash_value(word.c_str());
				if(hash <= 0){
				cout << word << ":\t: Value="<< hash<< endl;
				}
			}
		}
return 0;
}



