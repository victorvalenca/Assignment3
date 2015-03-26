/**********************************************************

TITLE: Assignment 3 - Substitution Cipher

PURPOSE: To decypher a string using frequency analysis

Created by Victor Fernandes March 26, 2015

 ***********************************************************/

/**********************************************************
  Begin import statements and definitions
 ***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ARRSZ 26
/**********************************************************
  Forward Declarations
 **********************************************************/
void displayFrequencyAnalysis(int**);
void doFrequencyAnalysis(char*, int*);
void sortFrequencyAddresses(int*, int**);
void swapCipherTextChars(char*);
void displayCipherText(char*);	//Helper function for displaying cipher
int* getLowestAddress(int**);
void clear();
/**********************************************************
  Begin Main
 **********************************************************/
int main(){

	//Initialize arrays
	char cipherText[] = "INSERT CIPHER HERE. PRAISE GABEN"; 	// Contains cipher to be decrypted
	int charFreq[ARRSZ] = {0};		// Container for number of character occurences
	int* alphaSort[ARRSZ] = {0};	// Array of pointers to ints

	//Initialize and assign pointers
	char* pCipherText = cipherText;
	int*  pCharFreq = charFreq;
	int** pAlphaSort = alphaSort;

	while(1){

	//Clean up screen and display the cipher to the user
	//	system("clear");
		displayCipherText(pCipherText);

	//TODO: Frequency analysis display
		doFrequencyAnalysis(pCipherText, pCharFreq);

	//TODO: Sort frequency analysis
		sortFrequencyAddresses(pCharFreq, pAlphaSort);

	//TODO: Display Frequency Analysis
		displayFrequencyAnalysis(pAlphaSort);
		fflush(stdin);
	//TODO: Prompt and swap characters
		swapCipherTextChars(pCipherText);

	}
}

/**********************************************************

NAME: displayCipherText

PURPOSE: To display a string using frequency analysis

Created by Victor Fernandes March 15, 2015

 ***********************************************************/
void displayCipherText(char* text){
	//TODO: Loop text and print to console
	while (*text != '\0'){
		printf("%c", *(text++));
	}
	printf("\n\n");
}

/**********************************************************

NAME: displayFrequencyAnalysis

PURPOSE: Display frequency analysis results in a readable format

Created by Victor Fernandes March 15, 2015

 ***********************************************************/
void displayFrequencyAnalysis(int** arr){

	int* lowest = getLowestAddress(arr);
		for (int i = 0; i < ARRSZ; i++){
		if (**(arr+i) != 0)
			printf("%c:%d ",(char)(*(arr+i) - lowest) + 'A' , **(arr+i));

	}
	printf("\n\n");
}

/*********************************************************

NAME: getLowestAddress

PURPOSE: Returns the lowest address contained within a given array of pointers

Created by D. Houtman March 23, 2015

ALGORITHM: Cycle through pointers, increment counter and compare each address to check
if address is lower than previous one.

NOTES: Cherrypicked from LowestAddress.c program provided by D. Houtman

*********************************************************/
int* getLowestAddress(int** arr){
	int *lowestAddr = arr;

	for (int i = 1; i < ARRSZ; i++){
		lowestAddr = (*(arr + i) < lowestAddr) ? *(arr+i) : lowestAddr;
	}
	return lowestAddr;
}


/**********************************************************

NAME: doFrequencyAnalysis

PURPOSE: To calculate the character frequency of the cipher array

Created by Victor Fernandes March 15, 2015

ALGORYTHM: Iterate through text and increment the equivalent index of
charFreq[] by 1 for every instance of the equivalent character.

 ***********************************************************/
void doFrequencyAnalysis(char* text, int* freq){
	int* start = freq; //"Checkpoint" to start of array

	//Clear the frequencies to prevent unwanted stacking
	for (; (freq - start) < 26; freq++) {*freq = 0;}

	for (; *text != '\0'; text++){
		freq = start; //Reset to beginning of charFreq
		//Increment if char is a letter in the ASCII table(A = 65, Z = 90)
		*(freq + *text - 'A') += (*text < 'A' || *text > 'Z') ? 0 : 1;
	}
}

/**********************************************************

NAME: sortFrequencyanalysis

PURPOSE: To decypher a string using frequency analysis

Created by Victor Fernandes March 26, 2015

ALGORYTHM: Perform a merge sort (or a similar high-performance algorythm)
and store the pointers inside alphaSort[].

***********************************************************/
void sortFrequencyAddresses(int* freq, int** sortArr){
	//TODO: See README.md

	//Wipe and copy the frequency array addresses into sortArr
	for (int i = 0; i < ARRSZ; i++){
		*(sortArr + i) = '\0';
		*(sortArr+i) = freq + i;
	}
	int flag = 1; //Set flag to 1 to begin initial pass
	int* temp; //Temp variable for swapping

	for (int i = ARRSZ -1; i > 0 && flag; i--){
		flag = 0;
		for (int j = 0; j < i; j++){
			if (**(sortArr + j) < **(sortArr + (j + 1))){
				//Swap locations in array
				temp = *(sortArr + j);
				*(sortArr + j) = *(sortArr + (j + 1));
				*(sortArr + (j + 1)) = temp;
				flag = 1; //Indicate a swap has occured
			}
		}
	}


}


/**********************************************************

NAME: swapCipherTextChars

PURPOSE: Prompt and swap two characters in cipherText[]

Created by Victor Fernandes March 26, 2015

ALGORYTHM: Iterate through the cipher text and swap every instance of character A
with character B, and vice-versa.

 ***********************************************************/
void swapCipherTextChars(char* cipher){
	//TODO: See README.md
	char c1 = '\0';
	char c2 = '\0';

	printf("Enter a character to swap: ");
	scanf("%c%*c", &c1);//Read first char, ignore the rest
	c1 = toupper(c1);

	fflush(stdin);

	printf("Swap it with this character: ");
	scanf("%c%*c", &c2);//Read first char, ignore the rest
	c2 = toupper(c2);

	for (; *cipher != '\0'; cipher++){
		if (*cipher == c1){
			*cipher = c2;
		}
		else if (*cipher == c2){
			*cipher = c1;
		}
	}
}

void clear(){
	while (getchar() != '\n');
}
