#include <iostream>
#include <cmath>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {


	const double one_mars_day = 88642.663;
	
	int earth_day, earth_hour, earth_min;

	int t_mars_day, t_mars_hours, t_mars_min;

	string input;


	while (getline(cin, input)){
	input += " ";
	int pos, start=0, old_pos=0;

	for (int counter = 1; input.find(" ", start) != string::npos; counter++) {
		pos = input.find(" ", start);

		if (counter == 1) earth_day = atoi(input.substr(old_pos, old_pos - pos).c_str());
		if (counter == 2) earth_hour = atoi(input.substr(old_pos, old_pos - pos).c_str());
		if (counter == 3)earth_min = atoi(input.substr(old_pos, old_pos - pos).c_str());

		old_pos = pos + 1;
		start = old_pos;

	}
	/*
	cin >> earth_day;
	cin >> earth_hour;
	cin >> earth_min;
	*/
	double earth_t, mars_t;//time in sec

	earth_t = earth_day * 24 * 60 * 60 + earth_hour * 60 * 60 + earth_min * 60;
	//days
	double temp = earth_t / one_mars_day;
	
	t_mars_day = temp;

	//hours
	temp -= t_mars_day;
	temp *= 24;

	t_mars_hours =  temp;

	//minutes

	temp -= t_mars_hours;
	temp *= 60;

	if (temp - (int)temp >= 0.5)temp = ceil(temp);
	else temp = floor(temp);
    
	t_mars_min = temp + 36;

	if (t_mars_min > 59) {
		t_mars_hours++;
		t_mars_min -= 60;
		
	}
	cout << "Day " << t_mars_day << ", " << setw(2) << setfill('0') << t_mars_hours << ":" << setw(2) << setfill('0') << t_mars_min << endl;
	}
	return 0;
}
