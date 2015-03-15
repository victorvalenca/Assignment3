# Assignment 3

 Assignment for my C programming course

## PURPOSE

 To assist the user into reading and deciphering a message using chracter
 frequency and substitution.

## TODO

### Variables

  - [ ] int charFreq[]: This array will contain int representing the number of
  occurences for each character in the cipher.

  - [ ] char cipherText[]: This array contains the cipher to be decrypted.

  - [ ] int\* alphasort[]: This is an array of pointers to ints, storing the
  largest number from charFreq[] at index 0, the second at index 1, and so on.
  Instead of associating the integer, it simply points to it.

### Functions

 - [ ] doFrequencyAnalysis():
  - ARGUMENTS: Takes in a pointer to cipherText[] and a pointer to charFreq[].
  - ALGORYTHM: Uses a single *for* loop for populating charFreq[] without the
  use of *if* or *select* statement.

 - [ ] sortFrequencyAnalysis():
  - ARGUMENTS: Takes in pointers to charFreq[] and alphaSort[]
  - ALGORYTHM: Sort through values in charFreq[] and store the addresses
  inside alphaSort[]. Preferrably using a high-performance algorythm such
  as MergeSort. (Find a nice implementation, and not reinvent the wheel)

 - [ ] displayFrequencyAnalysis():
  - ARGUMENTS: A pointer to alphaSort[]
  - ALGORYTHM: Iterate through alphaSort[], and subtract the value of
  charFreq[] and add 'A' to it.

 - [ ] swapCipherTextChars():
  - ARGUMENTS: A pointer tcipherText[]
  - ALGORYTHM: Prompt the user to swap two characters in cipherText[].
  Ex: Every instance of A is swapped with C, and every instance
  of C swapped with A.

#### NOTE

 This program should use pointers for all the above functions. Aside from
 declaring the three mentions arrays in *main()*, this program does not make
 use of any array in the implemented functions. **Pointers only.**
