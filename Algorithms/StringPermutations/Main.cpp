#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void permute(string prefix, string suffix){
	if(suffix.length() == 0) printf("%s\n", prefix.c_str());
	else{
		for(int i = 0; i < suffix.length(); ++i){
			swap(suffix[0], suffix[i]);
			permute(prefix + suffix[0], suffix.substr(1, suffix.length() - 1));
		}
	}
}

int main(int argc, char** argv){

	string str = "abc";
	permute("", str);

	cin.get();
	return 0;
}
