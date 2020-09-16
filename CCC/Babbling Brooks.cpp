#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;
//Using string manipulation to find the streams
int main() {
	string stream("");
	int temp, input;
	bool found = false;
	ostringstream convert;
	string temp_str;
	int length;
	cin >> temp;

	for (int counter = 0; counter < temp; counter++) {
		cin >> input;
		convert.str("");
		
		convert << input;

		stream += convert.str()+=" ";


	}

	int start = 0, pos, old_pos = 0, counter;
	int location;


	while (input != 77) {

		cin >> input;

		//99
		if (input == 99) {
			double percent;
			start = 0, old_pos = 0;

			cin >> location;
			cin >> percent;
			percent /= 100.0;

			for (counter = 1; stream.find(" ", start) != string::npos; counter++) {
				pos = stream.find(" ", start);

				if (counter == location) {
					found = true;
					break;
				}


				old_pos = pos + 1;
				start = old_pos;

			}

			if (found) {
				convert.str("");
				temp = atoi(stream.substr(old_pos, pos - old_pos).c_str());

				

				if (((double)temp*percent) - (int)(temp*percent) >= 0.5)temp = ceil(temp*percent);
				else temp = floor(temp*percent);

				convert << atoi(stream.substr(old_pos, pos - old_pos).c_str()) - temp;
				stream.insert(pos, convert.str());
				convert.str("");
				convert << temp;
				stream.replace(old_pos, pos - old_pos, convert.str()+=" ");
				//cout << stream << endl;
			}
		}

		// 88
		if (input == 88) {
			
			start = 0,old_pos = 0;

			cin >> location;
			//locate desired number
			for (counter = 1; stream.find(" ", start) != string::npos; counter++) {
				pos = stream.find(" ", start);

				if (counter == location) {
					found = true;
					break;
				}
				old_pos = pos + 1;
				start = old_pos;
			}
			if (found) {
				/*Debuging
				cout << stream.substr(old_pos, pos - old_pos) << endl;
				cout << stream.substr(pos + 1, (stream.find(" ", pos + 1) + 1) - (pos + 1)) << endl;
				*/

				//use converting string to int and adding
				temp = atoi(stream.substr(old_pos, pos - old_pos).c_str());
				
				temp += atoi(stream.substr(pos + 1, (stream.find(" ", pos + 1)) - (pos)).c_str());
				
				convert.str("");
				convert << temp;

				temp_str = convert.str() += " ";
				length = (stream.find(" ", pos + 1) + 1) - old_pos;

				if (stream.find(" ", pos + 1) != string::npos) {
					stream.replace(old_pos, length, temp_str);
				}

				temp_str = "";
				//cout << stream << endl;
			}
		}

	}
	cout << stream << endl;
	return 0;
}
