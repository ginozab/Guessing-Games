/* Brandon Ginoza */
/* 23 September 2014 */
/* Purpose: to play the guessing game with the computer doing the guessing, the user inputs to tell the computer if it is too high or low on its guess and the computer outputs a new guess. */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define true 1 			// define true needed for while loop
#define false (!true) 	// define false needed to break while loops

int main(){

	time_t now;
	time(&now);
	printf("Brandon Ginoza\nLab 3\n%s\n", ctime(&now)); // prints out name lab and time
	char answer; 		// character used as user input to ask if they want to play again
	int UI; 			// int used for user input 1 0 -1
		
	while(true){ 		// main game while loop
		printf("Hello user! Please pick a number between 1 and 100.\n"); // game greeting
		printf("My first guess is 50. How did I do?\n"); 	// computers first guess
		int counter = 0; 	// initialize the counter
		int CG = 50; 		// start current guess at 50
		int HG = 100; 		// start high guess mark at 100
		int LG = 0; 		// start low guess mark at 0

		while(true){ 		// while loop for game logic
			scanf("%d", &UI); 		// scan in user input
			counter++; 				// adds to counter for each guess
			
			if (UI == 1){ 			// if statement for user input 1, means to high
			HG = CG; 				// sets the high guess value equal to the current guess
			int temp = CG - LG; 	// finds difference between the current guess and the current low guess
			CG = CG - (temp/2); 	// generates the next current guess by dividing difference by two and subtracting it from original current guess
			printf("Hmmm, my guess was too high. My next guess is %d. How did I do?\n", CG);
			} 						// prints out the next guess 

			if (UI == -1){ 			// if statement for user input -1, logic if guess is to low
			LG = CG; 				// sets current low guess equal to current guess
			int temp = HG - CG; 	// finds difference between current high guess and current guess
			CG = CG + (temp/2); 	// generates next current guess by dividing differece(temp) by two and adding it to original current guess
			printf("Hmmm, my guess was too low. My next guess is %d. How did I do?\n", CG);
			} 						// prints out next current guess
			if (UI == 0){
				printf("Yay, I got it in %d tries! Your number was %d\n", counter, CG); // prints out the number of tries and the final number
				break; 				// breaks the logic game loop
			}
		}
		printf("Would you like to play again (y/n)? "); // prompts user input
		scanf(" %c", &answer); 		// scans in user input 
		if (answer == 'n'){ 		// if user doesn't want to play again
		break; 						// break the main gaming loop
		}

	}

	

}
