#include <iostream>
#include <sstream>

using namespace std;

string add(string, string);
string sbtract(string, string);

int main() {
	
	string a, b;
	int n;
	cin >> n;
	for (int counter = 0; counter < n; counter++) {
		bool negative_a, negative_b;
		cin >> a >> b;

		if (a[0] == '-')negative_a = true;
		else negative_a = false;

		if (b[0] == '-')negative_b = true;
		else negative_b = false;

		if (!negative_a && !negative_b) {
			cout << add(a, b) << endl;
		}

		else if (negative_a&&negative_b) {
			a.erase(0, 1);
			b.erase(0, 1);
			cout << "-" << add(a, b) << endl;
		}

		else if (negative_a) {
			a.erase(0, 1);
			string temp = sbtract(b, a);

			if (temp[0] == '-') {
				while (temp[1] == '0'&&temp.length()!=1) {
					temp.erase(1, 1);
				}
			}
			else {
				while (temp[0] == '0'&&temp.length() != 1) {
					temp.erase(0, 1);
				}
			}

			cout << temp << endl;
		}
		else if (negative_b) {
			b.erase(0, 1);
			string temp = sbtract(a, b);

			if (temp[0] == '-') {
				while (temp[1] == '0'&&temp.length() != 1) {
					temp.erase(1, 1);
				}
			}
			else {
				while (temp[0] == '0'&&temp.length() != 1) {
					temp.erase(0, 1);
				}
			}

			cout << temp << endl;
		}
	}


	return 0;
}

string add(string a, string b) {
	string sum="";
	int r = 0;
	//zero place holders (00...0xyz)
	if (a.length() > b.length()) {
		int temp = a.length() - b.length();
		for (int counter = 0; counter < temp; counter++) {
			b = "0" + b;
		}
	}

	else if (a.length() < b.length()) {
		int temp = b.length() - a.length();
		for (int counter = 0; counter < temp; counter++) {
			a = "0" + a;
		}
	}

	for (int counter = a.length()-1; counter>=0; counter--) {
		sum = to_string(((a[counter]-'0') + (b[counter]-'0') + r)%10) + sum;
		r = ((a[counter] - '0') + (b[counter] - '0') + r) / 10;
		if (counter == 0 && r > 0) {
			sum = to_string(r) + sum;
		}
	}
	return sum;
}

//defined as a-b
string sbtract(string a, string b) {
	bool negative;
	string diff="";

	if (a.length() > b.length()) {
		negative = false;
		int temp = a.length() - b.length();
		for (int counter = 0; counter < temp; counter++) {
			b = "0" + b;
		}
	}

	else if (a.length() < b.length()) {
		negative = true;
		int temp = b.length() - a.length();
		for (int counter = 0; counter < temp; counter++) {
			a = "0" + a;
		}
	}

	else {
		for (int counter = 0; counter < a.length(); counter++) {
			if (a[counter]-'0' > b[counter]-'0') {
				negative = false;
				break;
			}
			else if (a[counter]-'0' < b[counter]-'0'){
				negative = true;
				break;
			}
			if (counter == a.length() - 1) {
				return "0";
			}
		}
	}

	if (negative) {
		return "-" + sbtract(b, a);
	}
	else {
		
		for (int counter = a.length() - 1; counter >= 0; counter--) {
			
			if (a[counter] < b[counter]) {
	
				for (int c = 1; counter - c>=0; c++) {
					
					if (a[counter - c] == '0') {
						a[counter - c] = '9';
					}
					else {
						a[counter - c] = a[counter - c] - 1;
						diff = to_string((a[counter] - '0') + 10 - (b[counter] - '0')) + diff;
						break;
					}
				}
			}

			else diff = to_string((a[counter] - '0') - (b[counter] - '0')) + diff;
		}
		return diff;
	}
}
