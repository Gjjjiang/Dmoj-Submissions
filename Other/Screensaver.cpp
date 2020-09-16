#include <iostream>

using namespace std;

int main() {
    int **a;
    int x, y, t;
	bool running = true;

	int direction = 3, ballx, bally, tick = 1;

	/*
		1

	2		3

		4

	*/

	char input;

	cin >> x;
	cin >> y;
	cin >> t;

	a = new int*[y];

	for (int counter = 0; counter < y; counter++) {

		a[counter] = new int[x];

	}

	for (int c_y = 0; c_y < y; c_y++) {
		for (int c_x = 0; c_x < x; c_x++) {
			cin >> input;

			if (input == 'O') {
				a[c_y][c_x] = -1;
				ballx = c_x;
				bally = c_y;
			}


			if (input == '.') {
				a[c_y][c_x] = 0;
			}

			if (input == '\\') {
				a[c_y][c_x] = 1;
			}

			if (input == '/') {
				a[c_y][c_x] = 2;
			}

			if (input == '-') {
				a[c_y][c_x] = 3;
			}

			if (input == '|') {
				a[c_y][c_x] = 4;
			}




		}
	}


	while (running) {

		if (a[bally][ballx] == -1) {
			a[bally][ballx] = 0;
		}

		if (direction == 1) {

			if (bally - 1 >= 0) {
				bally--;
				tick++;

				if (a[bally][ballx] == 1) {
					direction = 2;
					a[bally][ballx] = 2;
				}

				else if (a[bally][ballx] == 2) {
					direction = 3;
					a[bally][ballx] = 1;
				}

				else if (a[bally][ballx] == 3) {
					direction = 4;
					a[bally][ballx] = 4;
				}
				
				
			}
			else break;
		}

		if (direction == 2) {
			if (ballx - 1 >=0) {
				
				ballx--;
				tick++;

				if (a[bally][ballx] == 1) {
					direction = 1;
					a[bally][ballx] = 2;
				}

				else if (a[bally][ballx] == 2) {
					direction = 4;
					a[bally][ballx] = 1;
				}
				
				
				else if (a[bally][ballx] == 4) {
					direction = 3;
					a[bally][ballx] = 3;
				}
			}

			else break;
		}
		

		if (direction == 3) {

			if (ballx + 1 < x) {

				ballx++;
				tick++;
				if (a[bally][ballx] == 1) {
					direction = 4;
					a[bally][ballx] = 2;
				}

				else if (a[bally][ballx] == 2) {
					direction = 1;
					a[bally][ballx] = 1;
				}

				else if (a[bally][ballx] == 4) {
					direction = 2;
					a[bally][ballx] = 3;
				}
				
			}
			else {
				break;
			}
		}

		if (direction == 4) {
			
			if (bally + 1 < y) {
				bally++;
				tick++;

				if (a[bally][ballx] == 1) {
					direction = 3;
					a[bally][ballx] = 2;
				}

				else if (a[bally][ballx] == 2) {
					direction = 2;
					a[bally][ballx] = 1;
				}
				
				
				else if (a[bally][ballx] == 3) {
					direction = 1;
					a[bally][ballx] = 4;
				}
			}

			else{
				break;
			}
		}
		if (a[bally][ballx] == 0) {
			a[bally][ballx] = -1;
		}

	}
	//cout<<tick<<endl;
	if (tick>t)cout<<"The observer stays within the grid.";
	else cout<< "The observer leaves the grid after "<<tick<< " tick(s).";

	return(0);
}
