#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "countdown.h"

void enterLetters(char *letters) {
	char lettertype;

	/* Letter frequencies from thecountdownpage.com/letters.htm */
	char *consonants = "bbcccddddddffggghhjklllllmmmmnnnnnnnnppppqrrrrrrrrrssssssssstttttttttvwxyz";
	char *vowels = "aaaaaaaaaaaaaaaeeeeeeeeeeeeeeeeeeeeeiiiiiiiiiiiiiooooooooooooouuuuu";
	srand((unsigned)time(NULL));

	for (int i = 0; i < 8; i++) { // 8 letters plus '\0'
		printf("Consonant (c) or vowel (v)? ");
		scanf(" %c", &lettertype); // Whitespace removes the newline in lettertype caused by last go around loop
		lettertype = tolower(lettertype);

		switch (lettertype) {
		case 'c':
			letters[i] = consonants[rand() % 74];
			break;
		case 'v':
			letters[i] = vowels[rand() % 67];
			break;
		default:
			puts("Please only enter a 'c' or a 'v'.\n");
			i--; // Balance out the i++ at the top of the for loop
			continue;
		}
		if (i < 7) {
			printf("Your letters are: %s\n\n", letters);
		}
	}
	letters[8] = '\0'; // Make sure word string ends with a null character
	printf("\nYour letters are: %s\n", letters);
	printf("==========================\n\n");
	return;
}

void allLowerCase(char *string) {
	for (int i = 0; string[i]; i++) { // string[i] will be false when it is '\0'
		string[i] = tolower(string[i]);
	}
}

int validUserWord(char *word, char *letters) {
	FILE *wordlist = fopen("webster.txt", "r");
	/* Must be opened and closed within the function so it starts searching from the start for each new word given */
	char wordToCompare[9] = "";
	int wordLetCount[26] = { 0 };
	int lettersCount[26] = { 0 };
	countLetters(word, wordLetCount);
	countLetters(letters, lettersCount);
	
	for (int i = 0; i < 26; i++) {
		if (wordLetCount[i] > lettersCount[i]) {
			return 0;
		}
	}
	
	while (!feof(wordlist)) {
		fscanf(wordlist, "%s", wordToCompare); // fscanf ensures there is no newline at end of string
		if (!strcmp(word, wordToCompare)) {
			fclose(wordlist);
			return 1;
		}
	}
	fclose(wordlist);
	return 0;
}

void countLetters(char *letters, int *letterCount) {
	for (int i = 0; i < (int)strlen(letters); i++) {
		int currentLetter = letters[i] - 97; // 97 is lowercase 'a' in ASCII
		++letterCount[currentLetter];
	}
}

void dictionarySearch(char *letters, char *yourWord, char *compuWord) {
	FILE *wordlist = fopen("webster.txt", "r");
	int letterCount[26] = { 0 };
	countLetters(yourWord, letterCount);
	char wordToTest[9] = "";
	char foundWord[9] = "";

	while (!feof(wordlist)) {
		fscanf(wordlist, "%s", wordToTest); // fscanf ensures there is no newline at end of string
		if (wordTest(wordToTest, yourWord, letters)) {
			// foundWord = wordToTest;
			sscanf(wordToTest, "%s", foundWord);
			sscanf(foundWord, "%s", yourWord); // The computer will now try to beat itself with a longer word
		}
	}
	sscanf(foundWord, "%s", compuWord);
	fclose(wordlist);
}

int wordTest(char *word, char *userWord, char *letterChoice) {
	if (strlen(word) <= strlen(userWord)) {
		return 0;
	}

	int wordLetterCount[26] = { 0 };
	int letChoiceCount[26] = { 0 };
	countLetters(word, wordLetterCount);
	countLetters(letterChoice, letChoiceCount);

	for (int i = 0; i < 26; i++) {
		if (wordLetterCount[i] > letChoiceCount[i]) {
			return 0;
		}
	}
	return 1;
}
void printCompuWord(char *compuWord) {
	if (strcmp(compuWord, "") == 0) { // Fixed from "" == compuWord for GitHub upload.
		printf("\nCongratulations! The computer was unable to defeat you!\n\n");
	}
	else {
		printf("\nThe computer was able to beat you with: %s\n\n", compuWord);
	}
}
