//  main.cpp
//  Project 2 2250

#include <iostream>
#include <string>
using namespace std;

// structure
struct Word {
    string english;
    string piglatin;
};

// function prototypes
void displayPigLatin(const Word wordArr[], int size);
Word * splitSentence(const string words, int &size);
void convertToPigLatin(Word wordArr[], int size);
int nth(string, char, int);



int main() {
    string input;
    int size;
    
// Ask for user for entry to convert to pig latin
    cout << "Please enter a word or phrase to be converted to pig latin: \n";
    
    getline(cin, input);
    
    Word * holder = new Word;
    
    holder = splitSentence(input, size);
    
    convertToPigLatin(holder, size);
    
    displayPigLatin(holder, size);

    return 0;
}

void displayPigLatin(const Word wordArr[], int size) {
    for (int i = 0; i < size; i++){
        cout << wordArr[i].piglatin << " ";
    }
    cout << endl;
}

// Split sentence into individual words.
Word * splitSentence(const string words, int &wordCount) {
    wordCount = 1;
    for (int i = 0; i < words.length(); i++){
        if (words[i] == ' '){
            wordCount++;
            }
        }
    
// Words are counted by the number of character spaces + 1.
    Word * placeHolder = new Word[wordCount];
    if (wordCount != 1){
        for (int i = 0; i < wordCount; i++){
            placeHolder[i].english = words.substr(nth(words, ' ', i), nth(words, ' ', i + 1) - nth(words, ' ', i));
        }
    }
    
// Else statement for one-worded entries.
    else placeHolder[0].english = words;
    
// Coverts uppercase letters to lowercase; removes non-alphabetical characters.
    for (int i = 0; i < wordCount; i++){
        for (int j = 0; j < placeHolder[i].english.size(); j++){
            placeHolder[i].english[j] = tolower(placeHolder[i].english[j]);
            if (isalpha(placeHolder[i].english[j]) == 0){
                placeHolder[i].english.erase(j, 1);
                j--;
            }
        }
    }
    return placeHolder;
}

//
void convertToPigLatin(Word wordArr[], int size) {
    for (int i = 0; i < size; i++){
        if (wordArr[i].english.empty()) wordArr[i].english = " ";
    }
// Pig latin coversion for words beginning with vowels.
    for (int i = 0; i < size; i++) {
    if (wordArr[i].english[0] == 'a' || wordArr[i].english[0] == 'e' || wordArr[i].english[0] == 'i' || wordArr[i].english[0] == 'o' || wordArr[i].english[0] == 'u'){
        wordArr[i].piglatin = wordArr[i].english;
        wordArr[i].piglatin.append("way");
        }
// Pig latin coversion for words beginning with consonants
    else if (wordArr[i].english != " "){
            wordArr[i].piglatin.append(wordArr[i].english, 1, wordArr[i].english.length() -1);
            wordArr[i].piglatin.append(wordArr[i].english, 0, 1);
            wordArr[i].piglatin.append("ay");
        }
    }
}

// Makes sure spaces aren't stored with the words
int nth(string searchedIn, char searchedFor, int n){
    int nthCount = 0;
    for (int i = 0; i < searchedIn.length(); i++){
        if (searchedIn[i] == searchedFor){
            nthCount++;
            if (nthCount == n){
                return i + 1;
            }
        }
    }
    return 0;
}
