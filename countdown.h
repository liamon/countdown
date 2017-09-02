#ifndef COUNTDOWN_H
#define COUNTDOWN_H

void enterLetters(char *letters);
void allLowerCase(char *string);
int validUserWord(char *word, char *letters);
void countLetters(char *letters, int *letterCount);

void dictionarySearch(char *letters, char *yourWord, char *compuWord);
int wordTest(char *word, char *userWord, char *letterChoice);
void printCompuWord(char *compuWord);

#endif /* Include/header guard. */
