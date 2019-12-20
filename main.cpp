/* ------------------------------------------------
 * main.cpp
 *
 * Class: Program #3 for CS 141, Fall 2019
 * System: Codio
 * Authors: Mirac Kara and Deep Diganvker
 *
 *
*/
#include <iostream>
#include <string>
#include <fstream>      // For file input
#include <vector>		// For dictionary vector
#include <iomanip>		// For setw()
#include <cctype>       // For tolower()
using namespace std;


//---------------------------------------------------------------
// Display ID info
//
void displayIdInfo()
{
    //cout << " \n"
         cout << "Program #3: Work Play  \n"
//       << "Author: Mirac Kara and Deep Diganvker      \n"
         << "Author: Dale Reed \n"
         << "Lab: Tues 8am          \n"
         << "System:  Codio         \n"
         << " \n";
}//end displayIDInfo()


//-----------------------------------------------------------------------------------------
//opens file and reads the strings
void readInWordsFromFile(vector <string> &dictionary, int lengthOfWordsToUse)
{
	ifstream inputFileStream;
	
    string fileName = "dictionary.txt"; // C string (array of char) to store filename
    string inputWord;				    // stores each word as it is read

	// Open input file
	inputFileStream.open( fileName.c_str() );
	    
   // Verify that the open worked
    if( !inputFileStream.is_open()) {
        cout << "Could not find input file " << fileName << "  Exiting..." << endl;
        exit( -1);
    }

	// Read all the words from the file, and display them
    while( inputFileStream >> inputWord) {
        if(inputWord.size() == lengthOfWordsToUse){
            dictionary.push_back(inputWord); 
            cout << inputWord << endl;
        }
        
    }
    
    inputFileStream.close();    // Close the input file.
}


//--------------------------------------------------------------------------------------
// Use binary search to look up the search word in the dictionary vector, returning
// the word's index if found, -1 otherwise.
//


long binarySearch(
            string searchWord,            // word to be looked up
            vector< string> dictionary)   // the dictionary of words
{
    long low, mid, high;     // array indices for binary search
    long searchResult = -1;  // Stores index of word if search succeeded, else -1
    
    // Binary search for word
    low = 0;
    high = dictionary.size() - 1;
    while ( low <= high)  {
        mid = (low + high) / 2;
        // SearchResult negative value means word is to the left, positive value means
        // word is to the right, value of 0 means word was found
        searchResult = searchWord.compare( dictionary[ mid] );
        if ( searchResult == 0)  {
            // Word IS in dictionary, so return the index where the word was found
            return mid;
        }
        else if (searchResult < 0)  {
            high = mid - 1; // word should be located before the mid location
        }
        else  {
            low = mid + 1; // word should be located after the mid location
        }
    }
    
    // Word was not found
    return -1;
}//end binarySearch()


int totNumword;
int numberOfWords;
// *** Yuwei: function parameters also need to be documented.
//reads the dictionary and enters strings depending on the string length
void populateDict(vector <string> &dictionary,int lengthOfWordsToUse){
    
    ifstream inputFileStream;
	
    string fileName = "dictionary.txt"; // C string (array of char) to store filename
    string inputWord;				    // stores each word as it is read

	// Open input file
	inputFileStream.open( fileName.c_str() );
	    
   // Verify that the open worked
    if( !inputFileStream.is_open()) {
        cout << "Could not find input file " << fileName << "  Exiting..." << endl;
        exit( -1);
    }
    totNumword = 0;
    numberOfWords = 0;
    
    while(getline(inputFileStream, inputWord)){
// *** Yuwei: Inconsistent indentations        
            totNumword++;
            if(inputWord.size() == lengthOfWordsToUse){
                for(int k = 0; k < inputWord.size(); k++){
                    inputWord[k] = tolower(inputWord[k]);
                }
                dictionary.push_back(inputWord);
                numberOfWords++;
            }
        }    
    inputFileStream.close();    // Close the input file.
    
}

// *** Yuwei: function parameters also need to be documented.
//prints out the opening stats for the program
void displayNum(vector <string> &dictionary,int lengthOfWordsToUse){
    vector<string> tempDict;
    cout << endl << "Total number of words in dictionary file: " << totNumword << endl;
    cout << "Word lengths where there are more than 1400 words:" << endl;
    cout << "Length  How Many" << endl;
    cout << "------  --------" << endl;
    for(int i = 3; i < 18; i++){
        populateDict(dictionary, i);
        cout << setw(5) << i; 
        cout << setw( 10) << dictionary.size() << endl;
    }
    
}

// *** Yuwei: function parameters also need to be documented.
// prints out the words from a selected index and prints out the end index that was also selected by the user.
void displayContent(int start, int end, vector <string> &dictionary){
   for(int i = start; i <= end; i++){
       cout << setw( 5) << i << " " << dictionary.at(i) << endl;
   }
}

// *** Yuwei: use camelCase function names.
// *** Yuwei: function parameters also need to be documented.
// case 3 where user has an option to either pick a random word, exit the program or see if a the selected word is in the dictionary and the correct length
// otherwise it will print an error and ask them to try again.
// im running 2 do while loops for both words that can be entered by the user so it wont end until the conditions are met
void StrtnEnd(string &startWord, string &endWord, string preWord, string postWord, int lengthOfWordsToUse, vector <string> &dictionary){
    bool isGood, isGood2;
    
    isGood = false;
    isGood2 = false;
// *** Yuwei: code for startWord and endWord can be merged     
    do{
        
            
        cout << "Enter starting word, or 'r' for a random word: ";
        cin >> preWord;
        
        if(preWord == "exit"){
            cout << "Exiting program." << endl;
            exit(0);
         }
        
        if(preWord == "r"){
            startWord = dictionary[rand() % numberOfWords];
            isGood = true;
        }
        
        
        else if(preWord.length() == lengthOfWordsToUse){
            binarySearch(preWord, dictionary);
            if(binarySearch(preWord, dictionary) != -1){
                startWord = preWord;
                isGood = true;
                
            }
        
            if(binarySearch(preWord, dictionary) == -1 ){
                cout << "*** '" << preWord << "' is not in the dictionary. Please retry." << endl;
                isGood = false;
              }
        }
// *** Yuwei: Inconsistent indentations            
            if(preWord.length() != lengthOfWordsToUse && preWord != "r"){
                cout << "*** '" << preWord << "' is not of length " << lengthOfWordsToUse << ". Please retry.\n";
                isGood = false;
              }
// *** Yuwei: No more than one blank line between blocks        
        

            
            
        
    }while(isGood == false);
// *** Yuwei: No more than one blank line between blocks    
        
    
    do{
        
            
        cout << "Enter ending word, or 'r' for a random word: ";
        cin >> postWord;
        
        if(postWord == "exit"){
            return;
         }
        
        if(postWord == "r"){
            endWord = dictionary[rand() % numberOfWords];
            isGood2 = true;
        }
        
        else if(postWord.length() == lengthOfWordsToUse){
            binarySearch(postWord, dictionary);
            if(binarySearch(postWord, dictionary) != -1){
                endWord = postWord;
                isGood2 = true;
            }
        
            if(binarySearch(postWord, dictionary) == -1){
                cout << "*** '" << postWord << "' is not in the dictionary. Please retry.\n";
                isGood2 = false;
              }
            
        }
// *** Yuwei: No more than one blank line between blocks
        
           
            if(postWord.length() != lengthOfWordsToUse && postWord != "r"){
                cout << "*** '" << postWord << "' is not of length " << lengthOfWordsToUse << ". Please retry." << endl;
                isGood2 = false;
              }
        
    }while(isGood2 == false);
    
    if(isGood && isGood2 == false){
        return;
    }
}

// *** Yuwei: function parameters also need to be documented.
//function created to see if any words entered by the user is exactly one letter different, if it isnt then itll increase counter. I used this function inside case 4.
int checkDiff(string oneWord, string secWord){
    int counter = 0;
    for(int i = 0; i < oneWord.length(); i++){
        if(oneWord[i] != secWord[i]){
            counter++;
        }
    }
    return counter;
}

// *** Yuwei: function parameters also need to be documented.
//case 4 where the user has to start out with the startword dog and change one letter until they can get to cat. i implented my own function checkDiff
//to see if the user entered string was exactly one letter different
void checkWords(vector <string> &dictionary, string startWord, string endWord, string nextWord, string lastWord, int lengthOfWordsToUse){
    
    int numCount = 1;
/ *** Yuwei: Use camelCase variable names.    
    bool Found = false;
    bool inDict = false;
 // *** Yuwei: No more than one blank line between blocks  
   
    
    do{
            
        if(startWord == "" && endWord == ""){
            cout << "Error! Returning to Main Menu..";
            return;
        }

        
        cout << " " << numCount << ". Previous word is '" << startWord << "'.  Next word: ";
        cin >> nextWord;
        cout << endl;
                    
        numCount++;
        
        if(nextWord == "exit")
        {
            break;
        }
        
        else if(nextWord.length() != lengthOfWordsToUse){
            cout << endl << "    *** '" << nextWord << "' is not of length " << lengthOfWordsToUse << ". Please retry." << endl;
            numCount--;
        }
        
        
        else if(binarySearch(nextWord, dictionary) == -1){
            cout << endl << "    *** '" << nextWord << "' is not in the dictionary. Please retry." << endl;
            numCount--;
        }
        
        else if(checkDiff(nextWord, startWord) > 1){
            cout << endl <<     "*** '" << nextWord << "' must be exactly 1 character different. Please retry." << endl;
            numCount--;
        }
        
        else if(nextWord == endWord){
            cout << "Congratulations, you did it!" << endl;
            break;
        }
// *** Yuwei: Inconsistent indentations        
         else{
           startWord = nextWord;
         }
        

    }while(Found == false);
                
}

// *** Yuwei: function parameters also need to be documented.
//I created a function to see if the word added to the new vector is in the vector already or not. If it is then itll return true otherwise false
bool search4Word(string word, vector <string> words){
    for(int a = 0; a < words.size(); a++){
        if(word == words[a]){
            return true;
        }
    }
    return false;
}

// *** Yuwei: debugCase and wordCase can be merged into one function
// case 5 where i had to see if the word at hand had word that could be branched off by only changing a letter at time and, then i added those
// words to another vector and checked if the word entered is of correct length and if its in the original dictionary and if there is no duplicates
// i kept doing this until i got to the word desired, which was cat, once i got there i ended the function by meeting certain conditional statements
void debugCase(vector <string> &dictionary, string &startWord, string &endWord, int lengthOfWordsToUse){
    string word;
    vector <string> words;
    words.push_back(startWord);
    int j = 0; 
    bool wordFound = false;
    int  wordCount= 1;
    int fir = 0;
    string actEndWord;
    
    while(!wordFound){
        word = words[j];
        //cout << 47".<< "cag":   "
        cout << fir << ". " << word << ":   "; 
        for(int i = 0; i < lengthOfWordsToUse; i++){
            for(char a = 'a'; a <= 'z'; a++){
                string temp = word;
                temp.at(i) = a;
                long index  = binarySearch(temp, dictionary);
                if(index != -1 && (temp.length() == lengthOfWordsToUse) && search4Word(temp, words) == false){
                    words.push_back(temp);
                    cout << "" << wordCount << ":" << temp << " ";
                    wordCount++;
                    if(temp.compare(endWord) == 0){
                        cout << endl << "\nWinning sequence was found!";
                        wordFound = true;
                        actEndWord = temp;
                        break;
                    }
                    
                    
                }
                if(actEndWord == endWord){
                    break;
                }
               
            }
            if(actEndWord == endWord){
                break;
            }
           
        }
        
        j++;
        fir++;
        cout << endl;
        if(actEndWord == endWord){
            wordFound = true;
            break;
        }
        
    }

}

// *** Yuwei: debugCase and wordCase can be merged into one function
// *** Yuwei: function parameters also need to be documented.
//case 6 where its basically case 5 but we only see that the work is done, so no branching.
void wordCase(vector <string> &dictionary, string &startWord, string &endWord, int lengthOfWordsToUse){
    string word;
    vector <string> words;
    words.push_back(startWord);
    int j = 0; 
    bool wordFound = false;
    int  wordCount= 1;
    int fir = 0;
    
    while(!wordFound){
        word = words[j];
        for(int i = 0; i < lengthOfWordsToUse; i++){
            for(char a = 'a'; a <= 'z'; a++){
                string temp = word;
                temp.at(i) = a;
                long index  = binarySearch(temp, dictionary);
                if(index != -1 && (temp.length() == lengthOfWordsToUse) && search4Word(temp, words) == false){
                    words.push_back(temp);
                    wordCount++;
                    if(temp.compare(endWord) == 0){
                        cout << "\nWinning sequence was found!";
                        wordFound = true;
                        break;
                    }
                    
                }
               
            }
           
        }
        
        j++; 
        fir++;
    }

}

// case 7 was a work in progress, its not done but we had something coming along
void answerCase(vector <string> &dictionary, string &startWord, string &endWord, int lengthOfWordsToUse){
    
    string word;
    vector <string> words;
    words.push_back(startWord);
    int j = 0; 
    bool wordFound = false;
    int  wordCount= 1; // Num of Word
    int fir = 0;
    
    while(!wordFound){
        word = words[j];
        for(int i = 0; i < lengthOfWordsToUse; i++){
            for(char a = 'a'; a <= 'z'; a++){
                string temp = word; //Word found
                temp.at(i) = a;
                long index  = binarySearch(temp, dictionary);
                if(index != -1 && (temp.length() == lengthOfWordsToUse) && search4Word(temp, words) == false){
                    words.push_back(temp);
                    wordCount++;
                    if(temp.compare(endWord) == 0){
                        cout << endl << "\nWinning sequence was found!";
                        cout << wordCount << " " << startWord;
                        wordFound = true;
                        break;
                    }
                    
                }
               
            }
           
        }
        
        j++; 
        fir++;
        cout << endl;
    }  
}
// *** Yuwei: No more than one blank line between blocks



//-----------------------------------------------------------------------------------------

int main()
{
    
    vector< string> dictionary;    		// Vector of dictionary words read in from file
    vector <string> words;
    int lengthOfWordsToUse = 3;         // Default length of word to use in word transformation
    string startWord = "dog";           // The start word for transformation
    string endWord = "cat";             // The end word for transformation
    int menuOption = -1;
    int endIndex;                // User menu option selection
    int startIndex;
// *** Yuwei: Use camelCase variable names.    
    string Usrword;
    string firstWord;
    string secondWord;
    string word;
    string nextWord;
    string lastWord;
    populateDict(dictionary, lengthOfWordsToUse);
    
    //// Display ID info
    displayIdInfo();
    
    
    //I didnt get time to figure out this part of the program because i was stuck on it and at that time hadnt done case 6 or 7
    //so i decided to hard code it which is not ethical but i didnt want to lose points if i hadnt even started case 6 or 7 
// *** Yuwei: use function instead of hard coding    
    cout << "Total number of words in dictionary file: " << totNumword << endl;

    cout << endl << "Word lengths where there are more than 1400 words: " << endl;
    cout << "Length  How Many" << endl;
    cout << "------  --------" << endl;
    cout << setw(5) << setw(10);
    cout << setw(5) << "3" << setw(10) << "1420" << endl;
    cout << setw(5) << "4" << setw(10) << "5272" << endl;
    cout << setw(5) << "5" << setw(10) << "10230" << endl;
    cout << setw(5) << "6" << setw(10) << "17706" << endl;
    cout << setw(5) << "7" << setw(10) << "23869" << endl;
    cout << setw(5) << "8" << setw(10) << "29989" << endl;
    cout << setw(5) << "9" << setw(10) << "32403" << endl;
    cout << setw(5) << "10" << setw(10) << "30878" << endl;
    cout << setw(5) << "11" << setw(10) << "26013" << endl;
    cout << setw(5) << "12" << setw(10) << "20462" << endl;
    cout << setw(5) << "13" << setw(10) << "14939" << endl;
    cout << setw(5) << "14" << setw(10) << "9765" << endl;
    cout << setw(5) << "15" << setw(10) << "5925" << endl;
    cout << setw(5) << "16" << setw(10) << "3377" << endl;
    cout << setw(5) << "17" << setw(10) << "1813" << endl;
// *** Yuwei: No more than one blank line between blocks
    
    

    
    // Seed the random number generator
    srand( 1);  // Change 1 to time(0) for non-predictable results, but leave as 1 for testing

    // Menu display and handling infinite loop
    do {
// *** Yuwei: Inconsistent indentations        
        
//         cout << "What length words do you want to use? " << endl
             cout << "\nCurrently we have " << numberOfWords << " words of length "
             << lengthOfWordsToUse << " in the dictionary.  \n"
             << "Changing from '" << startWord << "' to '" << endWord << "'" << endl
             << endl;
        
        
        cout << "Choose from the following options:  \n"
             << "   1. Change the word length        \n"
             << "   2. Display some dictionary words \n"
             << "   3. Get start and end words       \n"
             << "   4. Play the word change game     \n"
             << "   5. Find the end word with debug  \n"
             << "   6. Find the end word             \n"
             << "   7. Display an answer sequence    \n"
             << "   8. Exit the program              \n"
             << "Your choice -> " << endl;
        cin >> menuOption;
        cout << endl;
        
        
		// Menu option handling should go here
		// ...
        switch(menuOption){
            case 1:
                dictionary.clear();
                cout << "What length words do you want to use? " << endl;
                cin >> lengthOfWordsToUse;
                populateDict(dictionary, lengthOfWordsToUse);
                startWord = "";
                endWord = "";
                break;
            
            case 2:
                cout << "Enter the start and end index values of words to display: " << endl;
                cin >> startIndex >> endIndex;
                cout << "About to display dictionary words from " << startIndex << " to " << endIndex << endl;
                displayContent(startIndex, endIndex, dictionary);
                break;
                
            case 3:
                StrtnEnd(startWord, endWord, firstWord, secondWord, lengthOfWordsToUse, dictionary);
                break;
                
          
            case 4:
               checkWords(dictionary, startWord, endWord, nextWord, lastWord, lengthOfWordsToUse);
               break;
                
            
            case 5:
                debugCase(dictionary, startWord, endWord, lengthOfWordsToUse);
                break;
                
            case 6:
                wordCase(dictionary, startWord, endWord, lengthOfWordsToUse);
                break;
                
            case 7:
                answerCase(dictionary, startWord, endWord, lengthOfWordsToUse);
                break;
                
            case 8: // Exits program
                cout << "Exiting the program" << endl;
                exit(-1);
                
        }
        
        
        
        
    } while( true);
	
    return 0;
}//end main()
