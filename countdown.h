#ifndef COUNTDOWN_H
#define COUNTDOWN_H

void enterLetters(char *letters);
void allLowerCase(char *string);
void countLetters(char *letters, int *letterCount);
int validUserWord(char *word, char *letters);

int wordTest(char *word, char *userWord, char *letterChoice);
void dictionarySearch(char *letters, char *yourWord, char *compuWord);
void printCompuWord(char *compuWord);

#endif /* Include/header guard. */
