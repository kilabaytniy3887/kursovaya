#pragma once


void fileInput(char text[], const int size);
void printText(char text[]);
void removeSpacebars(char text[]);
bool isPunctuation(char text);
void removeMarks(char text[], int size);
void fixRegister(char text[]);
void textReduct(char text[], int size);
void changePositions(char text[]);
void verticalWords(char text[], int size);
int searchLinneum(char text[], char pattern[]);
void computePrefixFunction(char text[], char pattern[], int* pi);
int kmpSearch(char text[], char pattern[]);
void findRows(char text[], const int size);
void mainMenuChetire();
