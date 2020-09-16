#include <iostream>
#include <string>
using namespace std;

int main(){
	string *sentence;

	int num;


	cin>>num;
	cin.ignore();

	sentence = new string[num];

	for (int counter=0;counter<num;counter++){
		getline(cin,sentence[counter]);
	}

	int start=0,pos,old_pos=0;

	for (int counter=0;counter<num;counter++){
		start=0;
		old_pos=0;
		sentence[counter]+=" ";
		while(sentence[counter].find(" ",start)<sentence[counter].length()){
			pos=sentence[counter].find(" ",start);
			if ((pos)-(old_pos)==4){
				sentence[counter].replace(old_pos,4,"****");

			}
			old_pos=pos+1;
			start=pos+1;
		}

	}

	for (int counter=0;counter<num;counter++){
		cout<<sentence[counter]<<endl;
	}

	return 0;
}
