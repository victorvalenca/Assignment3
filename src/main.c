/**********************************************************

TITLE: Assignment 3 - Substitution Cipher

PURPOSE: To decypher a string using frequency analysis

Created by Victor Fernandes March 26, 2015

 ***********************************************************/

/**********************************************************
  Begin import statements
 ***********************************************************/
#include <stdio.h>

/**********************************************************
  Forward Declarations
 **********************************************************/
void displayFrequencyAnalysis(int*);
void doFrequencyAnalysis(char*, int*);
void sortFrequencyAnalysis(int*, int**);
void swapCipherTextChars(char*);
void displayCipherText(char*);	//Helper function for displaying cipher

/**********************************************************
  Begin Main
 **********************************************************/
int main(){

	//Initialize arrays
	char cipherText[] = "INSERT CIPHER HERE. PRAISE GABEN"; 	// Contains cipher to be decrypted
	int charFreq[26] = {0};		// Container for number of character occurences
	int* alphaSort[26] = {0};	// Array of pointers to ints

	//Initialize and assign pointers
	char* pCipherText = cipherText;
	int*  pCharFreq = charFreq;
	int** pAlphaSort = alphaSort;

	//	while(0){

	//Clean up screen and display the cipher to the user

	displayCipherText(pCipherText);

	//TODO: Frequency analysis display
	doFrequencyAnalysis(pCipherText, pCharFreq);

	//TODO: Sort frequency analysis
	//		sortFrequencyAnalysis(pCharFreq, pAlphaSort);

	//TODO: Display Frequency Analysis
	displayFrequencyAnalysis(pCharFreq);

	//TODO: Prompt and swap characters
	//		swapCipherTextChars(pCipherText);

	//	}
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
void displayFrequencyAnalysis(int* arr){
	//TODO: Finish sortFrequencyAnalysis to implement this
	for (int i = 0; i < 26; i++){
		printf("%c: %d\t",(char)(i + 65), *arr);
		arr++;
	}
	printf("\n");

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
	while (*text != '\0'){
		freq = start; //Reset to beginning of charFreq
		//Check if char is a letter in the ASCII table(A = 65, Z = 90)
		if ( !((int)*text < 65 || (int)*text > 90 ) ){
			freq += ((int)*text - 65);
			(*freq)++;
		}
		text++;
	}
}

/**********************************************************

NAME: sortFrequencyanalysis

PURPOSE: To decypher a string using frequency analysis

Created by Victor Fernandes March 26, 2015

ALGORYTHM: Perform a merge sort (or a similar high-performance algorythm)
and store the pointers inside alphaSort[].

 ***********************************************************/
void sortFrequencyAnalysis(int* freq, int** sortArr){
	//TODO: See README.md
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
}

