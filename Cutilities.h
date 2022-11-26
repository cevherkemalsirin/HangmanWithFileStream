#pragma once
#include<iostream>

using namespace std;

enum CharacterCaseType{ CC_UPPERCASE,CCL_LOWERCASE,CC_EITHER};

char getCharacterFromUser(const char promt[], const char error[],CharacterCaseType CaseType  = CCL_LOWERCASE);
char getCharacterFromUser(const char promt[], const  char error[], const char ValidInputs[], int len, CharacterCaseType CaseType = CCL_LOWERCASE);

int getNumberFromUser(const char promt[], const  char error[]);
int getNumberFromUser(const char promt[], const  char error[], const int min, const int max);


class Cutilities
{

};

