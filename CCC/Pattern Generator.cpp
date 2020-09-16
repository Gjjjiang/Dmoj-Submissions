#include <iostream>
#include <sstream>

using namespace std;

int one;
int length;

void sequence(string, int);

int main() {
	int n;

	cin >> n;

	for (int counter = 0; counter < n; counter++) {
		cin >> length >> one;
		cout << "The bit patterns are" << endl;
		sequence("",0);
	}

	return 0;
}

void sequence(string pattern, int counter) {
	if ((int)pattern.length() == length) {
		if (counter == one) {
			cout << pattern << endl;
			return;
		}
		else return;
	}

	else if (counter < one) {
		sequence(pattern + "1", counter + 1);
	}
	
	sequence(pattern + "0", counter);
	return;
}
