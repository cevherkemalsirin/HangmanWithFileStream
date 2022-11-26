#include <iostream>
#include "Cutilities.h"
#include <fstream>
#include<string>


using namespace std;
//make hangman peasant do not use strings :P
// 
// secretPharse = GetSecretPhrase()
//hidden phrase = makeHiddenPhrase(secretPhase)
// number of guessesLeft=6
//draw board(hiddenPhrase)
//

//game loop 
// {
// guess= getGuess(), 
// UpdateBoard(nummberOfGuessesLeft,hiddenPhrase,Guess,SecretPhrase)
// DrawBoard(HiddenPhase)
//}
// DisplayResult(SecretPhrase,NumberOfGuessesLeft)
//
		/* *---*
		 |   |
		 |   o
		 |  /|\
		 |  / \ 
		_|_*/
// 
//

string* getSecretPhraseData(const char fileName[],int& numberOfData);

string getRandomSecretPhrase(string*data,int len);

string makeHiddenPhrase(const string& secretPhase);
void drawBoard(const string& hiddenPhrase,int& numberOfGuesses);

void playGameHangman();

bool gameOverHangman(int numberOfGuesses, const string& hiddenPhase);
char getGuess();
void UpdateBoard(char Guess, int& numberOfGuessesLeft, string& hiddenPhrase, const string& SecretPhrase);
bool hasHidden(const string& HiddenPhrase);

void printScoreHangman(const string& hiddenPhrase, const string& secretPhrase);
int main9()

{
	return 0;

	bool playAgain = false;
	char yOrN = ' ';
	do
	{
		

		playGameHangman();


		playAgain = false;
		yOrN=getCharacterFromUser("Please Enter yes or no", " Invalid try again","y,n,Y,N",4);

		if (yOrN == 'y') playAgain = true;
		else playAgain = false;


	} while (playAgain);


}

string* getSecretPhraseData(const char fileName[], int& numberOfData)
{
	int counter = 0;
	string* hangmanWords;

	ifstream ifs(fileName);
	string temp;

	if (!ifs.fail())
	{
	while (getline(ifs, temp))
	{
		counter++;
	}
	numberOfData = counter;

	ifs.clear(); // clears errors
	ifs.seekg(0);// to find 

	hangmanWords = new string[counter];

	for (int i = 0; i < counter; i++)
	{
		ifs >> hangmanWords[i];
	}

	ifs.close();

	return hangmanWords;
	}
	
}

string getRandomSecretPhrase(string * data,int len)
{
	srand(time(0));
	int a = rand() % len;

	return data[a];

}

string makeHiddenPhrase(const string& secretPhase)
{
	string secretPhr = "";

	for (auto& c : secretPhase)
		secretPhr += "_";

	return secretPhr;
}

void drawBoard(const string& hiddenPhrase, int& numberOfGuesses)
{

	switch (numberOfGuesses)
	{
	case 6:
		system("cls");
		cout << " *---* " << endl;
		cout << " |   | " << endl;
		cout << " |     " << endl;
		cout << " |     " << endl;
		cout << "_|_    " << endl;
		cout <<"Hidden Word is: "<< hiddenPhrase << "    number of guesses are: "<< numberOfGuesses<<endl;
		break;
	case 5:
		system("cls");
		cout << " *---* " << endl;
		cout << " |   | " << endl;
		cout << " |   o " << endl;
		cout << " |     " << endl;
		cout << "_|_    " << endl;
		cout << "Hidden Word is: " << hiddenPhrase << "    number of guesses are: " << numberOfGuesses << endl;
		break;
	case 4:
		system("cls");
		cout << " *---* " << endl;
		cout << " |   | " << endl;
		cout << " |   o " << endl;
		cout << " |   | " << endl;
		cout << "_|_    " << endl;
		cout << "Hidden Word is: " << hiddenPhrase << "    number of guesses are: " << numberOfGuesses << endl;
		break;
	case 3:
		system("cls");
		cout << " *---* " << endl;
		cout << " |   | " << endl;
		cout << " |   o " << endl;
		cout << " |  /| " << endl;
		cout << "_|_    " << endl;
		cout << "Hidden Word is: " << hiddenPhrase << "    number of guesses are: " << numberOfGuesses << endl;
		break;
	case 2:
		system("cls");
		cout << " *---* " << endl;
		cout << " |   | " << endl;
		cout << " |   o " << endl;
		cout << " |  /|\\ " << endl;
		cout << "_|_    " << endl;
		cout << "Hidden Word is: " << hiddenPhrase << "    number of guesses are: " << numberOfGuesses << endl;
		break;
	case 1:
		system("cls");
		cout << " *---* " << endl;
		cout << " |   | " << endl;
		cout << " |   o " << endl;
		cout << " |  /|\\ " << endl;
		cout << "_|_ /  " << endl;
		cout << "Hidden Word is: " << hiddenPhrase << "    number of guesses are: " << numberOfGuesses << endl;
		break;
	case 0:
		system("cls");
		cout << " *---* " << endl;
		cout << " |   | " << endl;
		cout << " |   o " << endl;
		cout << " |  /|\\ " << endl;
		cout << "_|_ / \\ " << endl;
		cout << "Hidden Word is: " << hiddenPhrase << "    number of guesses are: " << numberOfGuesses << endl;
		break;
	default:
		cout << "invalid" << endl;
		break;
	}


	
	
}

void playGameHangman()
{
	int numberOfData = 0; // how many words

	string* dataptr = getSecretPhraseData("HangmanData.txt", numberOfData);

	string secretPhase = getRandomSecretPhrase(dataptr, numberOfData);
	delete [] dataptr; dataptr = nullptr;

	string hiddenPhase = makeHiddenPhrase(secretPhase);

	int numberOfGuesses = 6;
	char playerGuess;

	drawBoard(hiddenPhase, numberOfGuesses);
	do
	{
		
		 playerGuess=getGuess();

		 UpdateBoard(playerGuess, numberOfGuesses, hiddenPhase, secretPhase);

		 drawBoard(hiddenPhase, numberOfGuesses);
		 

	} while (!gameOverHangman(numberOfGuesses, hiddenPhase));

	printScoreHangman(hiddenPhase, secretPhase);
}
bool gameOverHangman(int numberOfGuesses, const string& hiddenPhase)
{
	bool gameOver = false;
	

	if (numberOfGuesses <= 0 || !hasHidden(hiddenPhase)) gameOver = true;

	return gameOver;
}

char getGuess()
{
	char guess = getCharacterFromUser("Please enter a guess: ", "Invalid character input for guess !!");

	return guess;



}

void UpdateBoard(char Guess, int& numberOfGuessesLeft, string& hiddenPhrase, const string& SecretPhrase)
{

	bool found = false;

	for (int i=0;i<SecretPhrase.size();i++)
	{
		if (Guess == SecretPhrase[i])
		{
			hiddenPhrase[i] = SecretPhrase[i];
			found = true;
		}

	}

	if (!found) numberOfGuessesLeft--;



}

void printScoreHangman(const string& hiddenPhrase, const string& secretPhrase)
{
	bool playerWon = hasHidden(hiddenPhrase);

	if (!playerWon)
	{
		cout << " Congratulations you won " << endl;
	}
	else
	{
		cout << " Sorry, you could not find the secret phrase which is :" << secretPhrase << endl;
	}

}
bool hasHidden(const string & HiddenPhrase)
{

	bool hasHidden = false;

	for (auto& c : HiddenPhrase)
	{
		if (c == '_')hasHidden = true;
	}

	return hasHidden;
}