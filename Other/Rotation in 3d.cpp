#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void rotate_x(long double angle, long double &x, long double &y, long double &z);
void rotate_y(long double angle, long double &x, long double &y, long double &z);
void rotate_z(long double angle, long double &x, long double &y, long double &z);
int main() {
	long double angle, rx, ry, rz, x, y, z;
	int n;
	cin >> n;

	for (int counter = 0; counter < n; counter++) {
		cin >> x >> y >> z >> rx >> ry >> rz >> angle;

		//rotate around y-axis to positive x-axis
		if (rx < 0) {
			rotate_y(M_PI + atan(rz / rx), x, y, z);
		}
		else if(rx > 0) {
			rotate_y(atan (rz / rx), x, y, z);
		}
		else {
			if (rz>0) {
				rotate_y(M_PI / 2, x, y, z);
			}
			else if (rz<0) {
				rotate_y(- M_PI / 2, x, y, z);
			}
		}
		
		//rotate around z-axis to positive x-axis
		if (rx < 0) {
			rotate_z(M_PI - atan(ry / (sqrt(pow(rx, 2) + pow(rz, 2)))), x, y, z);
		}
		else if (rx > 0) {
			rotate_z(-atan(ry / (sqrt(pow(rx, 2) + pow(rz, 2)))), x, y, z);
		}
		else {
			if (ry > 0) {
				rotate_z(-M_PI / 2, x, y, z);
			}
			else if (ry < 0) {
				rotate_z(M_PI / 2, x, y, z);
			}
		}
		
		//rotate desired angle around x-axis
		if (rx<0){
		    rotate_x(-angle, x, y, z);
        }
        else if(rx>0){
            rotate_x(angle, x, y, z);
        }
		//rotate around z-axis reverse
		if (rx < 0) {
			rotate_z(-(M_PI - atan(ry / (sqrt(pow(rx, 2) + pow(rz, 2))))), x, y, z);
		}
		else if (rx > 0) {
			rotate_z(atan(ry / (sqrt(pow(rx, 2) + pow(rz, 2)))), x, y, z);
		}
		else {
			if (ry > 0) {
				rotate_z(M_PI / 2, x, y, z);
			}
			else if (ry < 0) {
				rotate_z(-M_PI / 2, x, y, z);
			}
		}

		//rotate around y-axis to positive x-axis
		if (rx < 0) {
			rotate_y(-(M_PI + atan(rz / rx)), x, y, z);
		}
		else if (rx > 0) {
			rotate_y(-atan(rz / rx), x, y, z);
		}
		else {
			if (rz > 0) {
				rotate_y(-M_PI / 2, x, y, z);
			}
			else if (rz < 0) {
				rotate_y(M_PI / 2, x, y, z);
			}
		}
	    cout << fixed << setprecision(6) << x << " " << y << " " << z << endl;
	}
	return(0);
}
void rotate_x(long double angle, long double &x, long double &y, long double &z) {
	long double temp_x = x, temp_y = y, temp_z = z;
	y = temp_y * cos(angle) - temp_z * sin(angle);
	z = temp_y * sin(angle) + temp_z * cos(angle);
}
void rotate_y(long double angle, long double &x, long double &y, long double &z) {
	long double temp_x = x, temp_y = y, temp_z = z;
	x = temp_z * sin(angle) + temp_x * cos(angle);
	z = temp_z * cos(angle) - temp_x * sin(angle);
}
void rotate_z(long double angle, long double &x, long double &y, long double &z) {
	long double temp_x = x, temp_y = y, temp_z = z;
	x = temp_x * cos(angle) - temp_y * sin(angle);
	y = temp_x * sin(angle) + temp_y * cos(angle);
}
