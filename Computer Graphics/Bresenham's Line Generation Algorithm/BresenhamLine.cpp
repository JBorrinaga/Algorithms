#include <iostream>
#include <string>
using namespace std;

void bresenhamLine(int xStart, int xEnd, int yStart, int yEnd) {
	int xDiff = xEnd - xStart;
	int yDiff = yEnd - yStart;

	int errorParameter = 0;  

	for (int x = xStart, y = yStart; x <= xEnd; x++) {
		cout << '[' << x << ',' << y << ']' << '\n';

		errorParameter += yDiff;
		if ( (errorParameter * 2) >= xDiff) {
			y++;
			errorParameter -= xDiff;
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
