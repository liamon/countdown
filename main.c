#include <stdio.h>
#include "countdown.h"

int main(void) {
	char yourWord[9] = "";
	char buffer[9] = "";
	puts("Welcome to Countdown!");
	puts("=====================");
	
	char letters[9] = "";
	enterLetters(letters);
	printf("Please enter your word: ");
	scanf("%s", buffer);
	allLowerCase(buffer);
	
	while (strlen(yourWord) == 0) {
		if (validUserWord(buffer, letters)) {
			sscanf(buffer, "%s", yourWord);
			break;
		}
		printf("That is not a valid word.\n\nPlease enter your word: ");
		scanf("%s", buffer);
		allLowerCase(buffer);
	}
	
	char computerWord[9] = "";
	dictionarySearch(letters, yourWord, computerWord);
	printCompuWord(computerWord);
	
	return 0;
}
