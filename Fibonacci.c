/*Author: Sohail Quadir
Date: 10/31/19
Purpose: The purpose of this program is to compute the size of a population of green crud after a certain number of days, 
given the number of days, and the initial population.
Sources of help: No outside sources. 
Time spent: 8 hours
*/
#include <stdio.h>
int getInitialCrud(); //Asks the user for the initial amount of crud
int askUserNumOfDays(); //Asks the user for the number of days the crud has been out. 
int FibonacciCalc(int, int); //calculates how much crud will be there after the number of days.
char restartGame(); //Asks the user if they want to play again.
void clearKeyboardBuffer(); //clears the keyboard buffer
int main(int argc, char* argv[]) {
	char playAgain; //variable that determines if the user wants to play again or not.
	do {
		int initialSize = getInitialCrud();
		
		int numOfDays = askUserNumOfDays();

		int populationAfterDays = FibonacciCalc(initialSize, numOfDays);

		printf("The final population would be %d pounds\n", populationAfterDays);

		playAgain = restartGame();
	} while (playAgain == 'y' || playAgain == 'Y');

	return 0;
}
int getInitialCrud() { //This function asks the user for the initial size of the green crud. 
	int startingAmount;
	do {
		printf("Please enter the initial size of green crud:\n");
		scanf_s("%d", &startingAmount);
		if (startingAmount < 0) { //The function checks to make sure that the user inputted a number that is greater than 0. If they did not, the function restarts.
			clearKeyboardBuffer();
			printf("I'm sorry, but that value is either unrecognized or 0\n");
		}
	} while (startingAmount < 0);
	
	return startingAmount; //return the value to the main function to be used. 
}
int askUserNumOfDays() { //This function asks the user for the number of days the crud has been out. 
	int Days;
	do {
		printf("Please enter the number of days: \n");
		scanf_s("%d", &Days);
		if (Days < 0) { //Checks to make sure that the user inputted a value that is greater than 0. If not, the function restarts. 
			clearKeyboardBuffer();
			printf("Days must be greater than or equal to 0\n");
		}
	} while (Days < 0);

		return Days;
}
int FibonacciCalc(int startingAmount, int NumOfDays) { //This function performs the arithmetic to determine the final value of crud. 
	int numOfSequences = NumOfDays / 5; //Determines how many times the for loop iterates. 
	int valueBeforePrevious = startingAmount; //Initializing variables
	int previousValue = startingAmount;
	int nextValue = startingAmount;
	for (int i = 1; i < numOfSequences; i++) {
		nextValue = valueBeforePrevious + previousValue; //This can be thought of as FsubN = FsubN-2 + FsubN-1
		valueBeforePrevious = previousValue; //FsubN-2
		previousValue = nextValue; //FsubN-1
	}

	return nextValue;
}
char restartGame() { //This function asks the user whether they want to play again or not. 
	char playAgain;
	clearKeyboardBuffer();
	printf("Would you like to keep going? (y/n): \n");
	scanf_s("%c", &playAgain);
	if (playAgain == 'y' || playAgain == 'y') { //returns y to main, which starts the do-while loop over. 
		return playAgain;
	}
	else if (playAgain == 'n' || playAgain == 'N') { //returns 0 to main, ending the do-while loop. 
		return 0;
	}
	
	else { //In case user enters something other than y or n. 
		printf("I'm sorry, I don't that answer is unrecognized.\n");
		restartGame();
	}
}
void clearKeyboardBuffer() {
		char ch;
		scanf_s("%c", &ch, 1);
		while (ch != '\n' && ch != '\0') {
			scanf_s("%c", &ch, 1);
		}
	}


/*Computing I −− COMP.1010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, 
providing an enriching learning experience for students, and as training as a practicing 
computing professional upon graduation. This practice is manifested in the University's 
Academic Integrity policy. Students are expected to strictly avoid academic dishonesty 
and adhere to the Academic Integrity policy as outlined in the course catalog. Violations 
will be dealt with as outlined therein.

All programming assignments in this class are to be done by the student alone. 
No outside help is permitted except the instructor and approved tutors.

I certify that the work submitted with this assignment is mine and was generated in a
manner consistent with this document, the course academic policy on the course website 
on Blackboard, and the UMass Lowell academic code.

Date: 11/03/19
Name: Sohail Quadir

*/