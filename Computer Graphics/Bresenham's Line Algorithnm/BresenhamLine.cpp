#include <iostream>
#include <string>
using namespace std;

void bresenhamLine(int xStart, int xEnd, int yStart, int yEnd) {

	int xDiff = xEnd - xStart;
	int yDiff = yEnd - yStart;

	int errorParameter;

	// Slope is between 0 and 1
	if (xDiff >= yDiff) {
		errorParameter = 2 * yDiff - xDiff;
		for (int x = xStart, y = yStart; x <= xEnd; x++) {
			cout << '[' << x << ',' << y << ']' << '\n';

			if (errorParameter > 0) {
				y++;
				errorParameter += (2 * yDiff) - (2 * xDiff);
			}
			else {
				errorParameter += (2 * yDiff);
			}
		}
	}

	// Slope is greater than 1
	else if (yDiff > xDiff) {
		errorParameter = 2 * xDiff - yDiff;
		for (int x = xStart, y = yStart; y <= yEnd; y++) {
			cout << '[' << x << ',' << y << ']' << '\n';

			if (errorParameter > 0) {
				x++;
				errorParameter += (2 * xDiff) - (2 * yDiff);
			}
			else {
				errorParameter += (2 * xDiff);
			}
		}
	}
}

void askForInput(string prompt, int *input) {
	cout << prompt;

	while(!(cin >> *input)){
		cin.clear();
		cin.ignore(100, '\n');
		cout << prompt;
	} 
}

int main(void) {
	int xStart, xEnd, yStart, yEnd;
	
	askForInput("X1: ", &xStart);
	askForInput("Y1: ", &yStart);
	askForInput("X2: ", &xEnd);
	askForInput("Y2: ", &yEnd);

	bresenhamLine(xStart, xEnd, yStart, yEnd);
}

