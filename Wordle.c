#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

void getInp(char* guess);
bool containsNumbers(const char* str);
void toLowerCase(char* str);
bool checkGuess(char* guess,char* ans);
int game();

int main() {
  srand(time(NULL));  
  int run=1;
  while(run){
    run = game();
  }
  return 0;
}




void getInp(char* guess){
  printf("enter your guess : ");
  scanf("%s",guess);
  if(strlen(guess) != 5){ // check if input length is not equal to required length;
    printf("\nUse only 5 characters\n");
    getInp(guess);
  }
  if(containsNumbers(guess)){ // check if input contains number and reject it;
    printf("\nnumbers not allowed\n");
    getInp(guess);
  }
  toLowerCase(guess);
}
void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {  // check the range of elem to be shifted to lower case;
            str[i] = str[i] + ('a' - 'A');  // Convert to lowercase
        }
    }
}
bool containsNumbers(const char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            return true;  // Found a numeric digit
        }
    }
    return false;  // No numeric digits found
}

bool checkGuess(char* guess, char* ans) { 
    char clue[6] = {'-', '-', '-', '-', '-', '\0'};
    bool answerFlags[5] = {false, false, false, false, false};
    
    for (int i = 0; i < 5; i++) {
        if (guess[i] == ans[i]) {
            clue[i] = 'G';
            answerFlags[i] = true;
        }
    }
    
    for (int i = 0; i < 5; i++) {
        if (answerFlags[i]) continue;
        for (int j = 0; j < 5; j++) {
            if (i != j && !answerFlags[j] && guess[i] == ans[j]) {
                clue[i] = 'Y';
                answerFlags[j] = true;
                break;
            }
        }
    }
    
    printf("%s\n", clue);
    return strcmp(clue, "GGGGG") == 0;
}



int game() {

  char ans[6];
  char guess[6];
  int numOfGuesses = 0;
  bool guessed = false;
  
  printf("Welcome to the Wordle game.Your task is to guess the 5 letter word in 6 attempts\n Hints will be provided in the given format :\n'-' if the corresponding alphabet is not in the ANS\n'Y' if the corresponding alphabet is present but not int correct position\n'G' if the corresponding alphabet is at the correct position in the ANS");
  
  FILE* wordFile = fopen("words.txt", "r");
  if (wordFile == NULL) {
      printf("Error opening the wordlist file.\n");
      return 0;
  }
  char wordList[100][6];
  int wordCount = 0;
  while (wordCount < 100 && fscanf(wordFile, " %5s", wordList[wordCount]) != EOF) {
    wordCount++;
  }

  fclose(wordFile);

  int randomIndex = rand() % wordCount;
  strcpy(ans, wordList[randomIndex]);

  
  while(numOfGuesses<6 && !guessed){
    numOfGuesses++;
    printf("\n\nAttempt number : %d\n",numOfGuesses);
    getInp(guess);
    bool isCorrect = checkGuess(guess,ans);
    if(isCorrect){
      printf("You have guess the word in %d attempts \n",numOfGuesses);
      guessed = true;
      break;
    }
    else if(numOfGuesses!=6){
      printf("Try again\n");
    }
    else printf("You have failed the word was '%s'\n",ans);
    
  }

  int again;
  printf("Do you want to play again? Enter 1 for Yes or 0 for No: ");
  scanf("%d", &again);
  return again;
}



