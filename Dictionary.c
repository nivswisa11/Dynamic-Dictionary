/************
 * Niv Swisa
 * 208189126
 * ass05
 ***********/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Word {
    char** translations;
    struct Word* next;
} Word;

typedef struct {
    char** languages;
    int numOfLanguages;
    Word* wordList;
} Dictionary;

/*************************************
 * Function Name: newDictionary
 * Input: Dictionary*, int* numOfDictionaries
 * Output:
 * Function Operation: the function creates a new dictionary in the size of the Dictionary struct and adds it to
 * the array of dictionaries.
 ************************************/

void newDictionary(Dictionary* dictionaries, int* numOfDictionaries) {
    printf("Define a new dictionary:\n");
    int size = 1;
    char input;
    //allocating memory from heap in initial size of char to store the user input letter by letter to an array
    char* typesOfLanguages = (char*)malloc(sizeof(char));
    //if system can't find memory in heap then print that the allocation has failed and restart program
    if (typesOfLanguages == NULL) {
        printf("The creation of the dictionary has failed!\n");
        return;
    }
    scanf(" %c", &input);
    //putting the first letter of the user input in the first place in the block allocated
    typesOfLanguages[0] = input;
    while(input != '\n') {
        scanf("%c", &input);
        //break if the loop tries to put a \n in the array
        if(input == '\n')
            break;
        //increase size of block allocated from the heap by size of 1 char to insert the next letter
        typesOfLanguages = realloc(typesOfLanguages, size + 1);
        //if system can't find memory in heap then print that the allocation has failed and restart program
        if (typesOfLanguages == NULL) {
            printf("The creation of the dictionary has failed!\n");
            return;
        }
        //inserting the next letter in the newly allocated space
        typesOfLanguages[size] = input;
        size++;
    }
    //increasing block size to insert \0 at the end of block
    typesOfLanguages = realloc(typesOfLanguages, size + 1);
    //if system can't find memory in heap then print that the allocation has failed and restart program
    if (typesOfLanguages == NULL) {
        printf("The creation of the dictionary has failed!\n");
        return;
    }
    //inserting \0 at the end of the block
    typesOfLanguages[size] = '\0';

    //allocating a block from heap to store languages added to the dictionary with size of char*
    dictionaries->languages = (char**) malloc (sizeof(char*));
    //if system can't find memory in heap then print that the allocation has failed and restart program
    if (dictionaries->languages == NULL) {
        printf("The creation of the dictionary has failed!\n");
        return;
    }
    int counter = 0;
    char* token;
    //inserting the first language to the token pointer
    token = strtok(typesOfLanguages, ",");
    //inserting first language to the dictionary
    dictionaries->languages[counter] = token;
    //keep dividing languages
    token = strtok(NULL, ",");
    while(token != NULL) {
        counter++;
        //increase block by one more char* to make place for the next language
        dictionaries->languages = realloc(dictionaries->languages, sizeof(char*) * (counter +1));
        //if system can't find memory in heap then print that the allocation has failed and restart program
        if (dictionaries->languages == NULL) {
            printf("The creation of the dictionary has failed!\n");
            return;
        }
        //inserting current language to array of languages
        dictionaries->languages[counter] = token;
        token = strtok(NULL, ",");
    }
    counter++;
    //updating number od dictionaries by one
    *numOfDictionaries += 1;
    //updating number of languages in the current dictionary
    dictionaries->numOfLanguages = counter;
    printf("The dictionary has been created successfully!\n");
}

/*************************************
 * Function Name: addWord
 * Input: int *numOfDictionaries, Dictionary* dictionaries
 * Output:
 * Function Operation: in this function the user selects the dictionary that he wants to add a word to,
 * then he writes the word in the origin language and also the translations in the other languages
 ************************************/

void addWord(int *numOfDictionaries, Dictionary* dictionaries){
    //allocating space from heap in the size of Word struct
    Word *words = (Word*)malloc(sizeof(Word));
    Word* temporaryList;
    //if system can't find memory in heap then print that the allocation has failed and restart program
    if (words == NULL) {
        printf("The addition of the word has failed!\n");
        return;
    }
    int choiceOfDictionary;
    printf("Choose a dictionary:\n");
    //printing the existing dictionaries so the user can choose a dictionary to add a word to
    for(int i = 0; i < *numOfDictionaries; i++) {
        if(i > 0)
            printf("\n");
        printf("%d. ", i+1);
        for(int j = 0; j < dictionaries[i].numOfLanguages; j++) {
            if(j < dictionaries[i].numOfLanguages-1)
                printf("%s,", dictionaries[i].languages[j]);
            else
                printf("%s", dictionaries[i].languages[j]);
        }
    }
    printf("\n");
    scanf("%d", &choiceOfDictionary);
    //defining the current dictionary to be the one that the user selected from the menu
    Dictionary* currentDictionary = &dictionaries[choiceOfDictionary - 1];
    printf("Enter a word in ");
    //asking user to type a word in the origin language
    for(int i = 0; i <currentDictionary->numOfLanguages; i++) {
        if(i < currentDictionary->numOfLanguages - 1) {
            printf("%s,",currentDictionary->languages[i]);
        }
        else {
            printf("%s:\n",currentDictionary->languages[i]);
        }
    }
    temporaryList =currentDictionary->wordList;

    char input;
    //allocating memory from heap in initial size of char to store the user input letter by letter to an array
    char* typesOfTranslations = (char*)malloc(sizeof(char));
    //if system can't find memory in heap then print that the allocation has failed and restart program
    if (typesOfTranslations == NULL) {
        printf("The addition of the word has failed!\n");
        return;
    }
    int size = 1;
    scanf(" %c", &input);
    //putting the first letter of the user input in the first place in the block allocated
    typesOfTranslations[0] = input;
    while(input != '\n') {
        scanf("%c", &input);
        //break if the loop tries to put a \n in the array
        if(input == '\n')
            break;
        //increase size of block allocated from the heap by size of 1 char to insert the next letter
        typesOfTranslations = realloc(typesOfTranslations, size + 1);
        //if system can't find memory in heap then print that the allocation has failed and restart program
        if (typesOfTranslations == NULL) {
            printf("The addition of the word has failed!\n");
            return;
        }
        //inserting the next letter in the newly allocated space
        typesOfTranslations[size] = input;
        size++;
    }
    //increasing block size to insert \0 at the end of block
    typesOfTranslations = realloc(typesOfTranslations, size + 1);
    //if system can't find memory in heap then print that the allocation has failed and restart program
    if (typesOfTranslations == NULL) {
        printf("The addition of the word has failed!\n");
        return;
    }
    //inserting \0 at the end of the block
    typesOfTranslations[size] = '\0';
    //allocating space for array of translations in size of char*
    words->translations = (char**) malloc (sizeof(char*));
    //if system can't find memory in heap then print that the allocation has failed and restart program
    if (words->translations == NULL) {
        printf("The addition of the word has failed!\n");
        return;
    }
    char* token;
    int counter = 0;
    //inserting the first word to token
    token = strtok(typesOfTranslations, ",");
    //inserting word in origin language ti dictionary
    words->translations[counter] = token;
    //keep dividing words
    token = strtok(NULL, ",");
    while(token != NULL) {
        counter++;
        //increasing size of array of words by one to make space for the next translation of origin word
        words->translations = realloc(words->translations, sizeof(char*) * (counter +1));
        //if system can't find memory in heap then print that the allocation has failed and restart program
        if (words->translations == NULL) {
            printf("The addition of the word has failed!\n");
            return;
        }
        //insert the translation to the newly allocated space
        words->translations[counter] = token;
        token = strtok(NULL, ",");
    }
    //If it's the first word in the list
    if(temporaryList==NULL){
        //insert the first word into the list
        currentDictionary->wordList = words;
        //set the next word to NULL
        words->next = NULL;
        printf("The word has been added successfully!\n");
        return;
    }
    //If it's not the first word in the list, loop until you find an empty slot in the list
    while(temporaryList->next != NULL)
        //get the next word in the list
        temporaryList = (Word*) temporaryList->next;
    //Insert the word in the next slot in the list
    temporaryList->next = words;
    //Set the next slot to NULL
    words->next = NULL;
    printf("The word has been added successfully!\n");
}

/*************************************
 * Function Name: deleteWord
 * Input: int *numOfDictionaries, Dictionary* dictionaries
 * Output:
 * Function Operation: the function deletes a word from a selected dictionary
 ************************************/

void deleteWord(int *numOfDictionaries, Dictionary* dictionaries) {
    int choiceOfDictionary;
    printf("Choose a dictionary:\n");
    //printing a list of all the dictionaries
    for (int i = 0; i < *numOfDictionaries; i++) {
        if (i > 0)
            printf("\n");
        printf("%d. ", i + 1);
        for (int j = 0; j < dictionaries[i].numOfLanguages; j++) {
            if (j < dictionaries[i].numOfLanguages - 1)
                printf("%s,", dictionaries[i].languages[j]);
            else
                printf("%s", dictionaries[i].languages[j]);
        }
    }
    printf("\n");
    //taking user input and inserting it to choice of the dictionary
    scanf("%d", &choiceOfDictionary);
    //working on the dictionary selected, using -1 to reach the actual place of the dictionary in the array
    Dictionary *currentDictionary = &dictionaries[choiceOfDictionary - 1];
    printf("Enter a word in %s:\n", currentDictionary->languages[0]);
    //allocating block from heap in size of char for user input
    char *removeWord = (char *) malloc(sizeof(char));
    //if system can't find memory in heap then print that the allocation has failed and restart program
    if (removeWord == NULL) {
        printf("The deletion of the word has failed!\n");
        return;
    }
    int size = 1;
    char input;
    scanf(" %c", &input);
    //putting the first letter of the user input in the first place in the block allocated
    removeWord[0] = input;
    while (input != '\n') {
        scanf("%c", &input);
        //break if the loop tries to put a \n in the array
        if (input == '\n')
            break;
        //increase size of block allocated from the heap by size of 1 char to insert the next letter
        removeWord = realloc(removeWord, size + 1);
        //if system can't find memory in heap then print that the allocation has failed and restart program
        if (removeWord == NULL) {
            printf("The deletion of the word has failed!\n");
            return;
        }
        //inserting the next letter in the newly allocated space
        removeWord[size] = input;
        size++;
    }
    //increasing block size to insert \0 at the end of block
    removeWord = realloc(removeWord, size + 1);
    //if system can't find memory in heap then print that the allocation has failed and restart program
    if (removeWord == NULL) {
        printf("The deletion of the word has failed!\n");
        return;
    }
    //inserting \0 at the end of the block
    removeWord[size] = '\0';
    //making sure the user wants to delete the chosen word
    printf("Are you sure? (y/n)\n");
    char authenticateDeletion;
    scanf("%c", &authenticateDeletion);
    //if the user wants to delete the word
    if (authenticateDeletion == 'y') {
        Word *temp;
        //defining current to be the first word of the selected dictionary
        Word *current = dictionaries[choiceOfDictionary - 1].wordList;
        //if the user input is different from the first word in the current dictionary
        if (strcmp (removeWord, current->translations[0]) != 0) {
            //if it's the only word in the dictionary
            if (current->next == NULL) {
                if (strcmp(removeWord, current->translations[0]) != 0)
                    printf("The deletion of the word has failed!\n");
            }
        }
        //if the user input is different from the first word in the current dictionary
        if (strcmp (removeWord, current->translations[0]) != 0) {
            //if there is more than one word in the dictionary
            while (current->next != NULL) {
                //if the user input is different from the current word in the selected dictionary
                if (strcmp(removeWord, current->translations[0]) != 0) {
                    //move on to the next word
                    current = current->next;
                }
                //if it is the only word in the dictionary
                if (current->next == NULL) {
                    if (strcmp(removeWord, current->translations[0]) != 0) {
                        printf("The deletion of the word has failed!\n");
                    }
                }
            }
        }
        //defining selected to be the first word of the selected dictionary
        Word *selected = dictionaries[choiceOfDictionary - 1].wordList;
        //if there is more than one word in the dictionary
        while (selected->next != NULL) {
            //defining last to be the next word after *selected
            Word *last = selected->next;
            //if the user input matched with the current word
            if (strcmp(removeWord, last->translations[0]) == 0) {
                //insert the word into temp
                temp = selected->next;
                //link the previous word with the next word
                selected->next = last->next;
                //free the memory inserted into temp
                free(temp);
                printf("The word has been deleted successfully!\n");
                break;
            }
                //otherwise, move on to the next word and continue loop
            else {
                selected = selected->next;
            }
        }
        //if the user input matched with the first word
        if (strcmp(removeWord, dictionaries[choiceOfDictionary - 1].wordList->translations[0]) == 0) {
            //if there is only one word in the current dictionary
            if (dictionaries[choiceOfDictionary - 1].wordList->next == NULL) {
                //insert the word into temp
                temp = dictionaries[choiceOfDictionary - 1].wordList;
                //set the empty space to NULL to not lose memory
                dictionaries[choiceOfDictionary - 1].wordList = NULL;
                //free the memory inserted into temp
                free(temp);
                printf("The word has been deleted successfully!\n");
            }
                //otherwise, if there is more than one word in the dictionary
            else {
                if (dictionaries[choiceOfDictionary - 1].wordList->next != NULL) {
                    //insert the first word into temp
                    temp = dictionaries[choiceOfDictionary - 1].wordList;
                    //link the next word with the dictionary
                    dictionaries[choiceOfDictionary - 1].wordList = dictionaries[choiceOfDictionary - 1].wordList->next;
                    //free the memory inserted into temp
                    free(temp);
                    printf("The word has been deleted successfully!\n");
                }
            }
        }
    }
        //if user prints anything other than y print the following
    else {
        printf("The deletion of the word has been canceled.\n");
    }
    free(removeWord);
}

/*************************************
 * Function Name: lookupWord
 * Input: int *numOfDictionaries, Dictionary* dictionaries
 * Output:
 * Function Operation: the function looks up a word in the chosen dictionary and displays the translations for
 * the word
 ************************************/

void lookupWord(int *numOfDictionaries, Dictionary* dictionaries){
    int choiceOfDictionary;
    printf("Choose a dictionary:\n");
    //print the list of existing dictionaries
    for (int i = 0; i < *numOfDictionaries; i++) {
        if (i > 0)
            printf("\n");
        printf("%d. ", i + 1);
        for (int j = 0; j < dictionaries[i].numOfLanguages; j++) {
            if (j < dictionaries[i].numOfLanguages - 1)
                printf("%s,", dictionaries[i].languages[j]);
            else
                printf("%s", dictionaries[i].languages[j]);
        }
    }
    printf("\n");
    //receive the user input
    scanf("%d", &choiceOfDictionary);
    //make the current dictionary to be the dictionary chosen by the user
    Dictionary *currentDictionary = &dictionaries[choiceOfDictionary - 1];
    printf("Enter a word in %s:\n", currentDictionary->languages[0]);
    //allocating block from heap in size of char for user input
    char *scanForWord = (char *) malloc(sizeof(char));
    //if system can't find memory in heap then print that the allocation has failed and restart program
    if (scanForWord == NULL) {
        printf("The search has failed successfully!\n");
        return;
    }
    int size = 1;
    char input;
    scanf(" %c", &input);
    //putting the first letter of the user input in the first place in the block allocated
    scanForWord[0] = input;
    while (input != '\n') {
        scanf("%c", &input);
        //break if the loop tries to put a \n in the array
        if (input == '\n')
            break;
        //increase size of block allocated from the heap by size of 1 char to insert the next letter
        scanForWord = realloc(scanForWord, size + 1);
        //if system can't find memory in heap then print that the allocation has failed and restart program
        if (scanForWord == NULL) {
            printf("The search has failed successfully!\n");
            return;
        }
        //inserting the next letter in the newly allocated space
        scanForWord[size] = input;
        size++;
    }
    //increasing block size to insert \0 at the end of block
    scanForWord = realloc(scanForWord, size + 1);
    //if system can't find memory in heap then print that the allocation has failed and restart program
    if (scanForWord == NULL) {
        printf("The search has failed successfully!\n");
        return;
    }
    //inserting \0 at the end of the block
    scanForWord[size] = '\0';
    //defining current to be the first word in the dictionary
    Word *current = dictionaries[choiceOfDictionary - 1].wordList;
    int existenceCheck;
    //while there are words in the dictionary
    while (current != NULL) {
        //if the user input matches with the current word
        if(strcmp(scanForWord, current->translations[0]) == 0) {
            printf("The translations are:\n");
            //print translations in every language
            for(int i=0; i<dictionaries[choiceOfDictionary -1].numOfLanguages - 1; i++) {
                printf("%s: %s", dictionaries[choiceOfDictionary -1].languages[i+1], current->translations[i+1]);
                if(i < dictionaries[choiceOfDictionary -1].numOfLanguages - 2)
                    printf(",");
                if(i < dictionaries[choiceOfDictionary -1].numOfLanguages - 2)
                    printf(" ");
            }
            printf("\n");
            //change value to one as is used for flag
            existenceCheck = 1;
        }
        //move on to the next word
        current = current->next;
        //if the last word is reached, break
        if(current == NULL) {
            break;
        }
    }
    //if the word doesn't exist in the dictionary
    if(existenceCheck != 1) {
        printf("There are no translations for \"%s\" in this dictionary.\n", scanForWord);
    }
    free(scanForWord);
}

/*************************************
 * Function Name: deleteDictionary
 * Input: int *numOfDictionaries, Dictionary* dictionaries
 * Output:
 * Function Operation: the function deletes a dictionary and moves the other dictionaries one place back in the
 * array of dictionaries
 ************************************/

void deleteDictionary(int *numOfDictionaries, Dictionary* dictionaries){
    int choiceOfDictionary;
    printf("Choose a dictionary:\n");
    //printing list of existing dictionaries
    for (int i = 0; i < *numOfDictionaries; i++) {
        if (i > 0)
            printf("\n");
        printf("%d. ", i + 1);
        for (int j = 0; j < dictionaries[i].numOfLanguages; j++) {
            if (j < dictionaries[i].numOfLanguages - 1)
                printf("%s,", dictionaries[i].languages[j]);
            else
                printf("%s", dictionaries[i].languages[j]);
        }
    }
    printf("\n");
    //choice of dictionary to be deleted
    scanf("%d", &choiceOfDictionary);
    //asking user if he is sure he wants to delete the selected dictionary
    printf("Are you sure? (y/n)\n");
    char authenticateDeletion;
    scanf(" %c", &authenticateDeletion);
    //allocating memory from heap in size of Dictionary
    Dictionary *temp = (Dictionary *)malloc(sizeof(Dictionary));
    //if system can't find memory in heap then print that the allocation has failed and restart program
    if (temp == NULL) {
        printf("The search has failed successfully!\n");
        return;
    }
    //if user wants to delete dictionary
    if (authenticateDeletion == 'y') {
        //insert chosen dictionary into temp
        *temp = dictionaries[choiceOfDictionary - 1];
        //free the memory inserted into te,p
        free(temp);
        for(int i = choiceOfDictionary; i < *numOfDictionaries; i++)
            //move the place of the dictionaries one place back in the array of dictionaries
            dictionaries[i-1] = dictionaries[i];
        //decrease the number od dictionaries by one
        *numOfDictionaries = *numOfDictionaries - 1;
        //decrease the size of the array of dictionaries by size of one element
        printf("The dictionary has been deleted successfully!\n");
    }
        //if the user doesn't want to delete the dictionary print the following
    else {
        printf("The deletion of the dictionary has been canceled.\n");
    }
}

/*************************************
 * Function Name: freeWords
 * Input: Word* theListOfWords, int numOfLanguages
 * Output:
 * Function Operation: the function frees all the words and translations in the dictionaries before exiting the program
 ************************************/

void freeWords(Word* theListOfWords, int numOfLanguages){
    //if reached the last word
    if(theListOfWords == NULL)
        return;
    //call the function again recursively
    freeWords(theListOfWords->next, numOfLanguages);
    for(int i=0;i<numOfLanguages;i++)
    {
        //freeing the words inside translations
        free(theListOfWords->translations[0]);
        //setting to NULL
        theListOfWords->translations[0] = NULL;
    }
    //freeing the translations array
    free(theListOfWords->translations);
    //setting to NULL
    theListOfWords->translations = NULL;
    free(theListOfWords);
    theListOfWords = NULL;
}

/*************************************
 * Function Name: freeWordList
 * Input: Dictionary* dict
 * Output:
 * Function Operation: the function calls the freeWords function
 ************************************/

void freeWordList(Dictionary* dict)
{
    freeWords(dict->wordList, dict->numOfLanguages);
}

/*************************************
 * Function Name: main
 * Input:
 * Output:
 * Function Operation: the function displays the menu and allows the user to use the program by sending him to
 * any function requested
 ************************************/

int main() {
    int printTheMenu = 0;
    int numOfDictionaries = 0;
    Dictionary *dictionaries;
    int choiceFromMenu, character;
    //while true
    while (1) {
        if (printTheMenu == 0)
            printf("Welcome to the dictionaries manager!\n"
                   "Choose an option:\n"
                   "1. Create a new dictionary.\n"
                   "2. Add a word to a dictionary.\n"
                   "3. Delete a word from a dictionary.\n"
                   "4. Find a word in a dictionary.\n"
                   "5. Delete a dictionary.\n"
                   "6. Exit.\n");
        //reset printTheMenu to zero
        printTheMenu = 0;
        if (scanf("%d", &choiceFromMenu) != 1) {
            while ((character = getchar()) != '\n' && character != EOF);
            choiceFromMenu = -1;
        }
        switch (choiceFromMenu) {
            case 1:
                //if there are no dictionaries
                if (numOfDictionaries == 0)
                    //allocate memory from heap in size of Dictionary
                    dictionaries = (Dictionary *) malloc(sizeof(Dictionary));
                //if system can't find memory in heap then print that the allocation has failed and restart program
                if (dictionaries == NULL) {
                    printf("The creation of the dictionary has failed!\n");
                    break;
                } else
                    //if there is an existing dictionary increase size of array of dictionaries by one
                    dictionaries = realloc(dictionaries, (numOfDictionaries + 1) * sizeof(Dictionary));
                //if system can't find memory in heap then print that the allocation has failed and restart program
                if (dictionaries == NULL) {
                    printf("The creation of the dictionary has failed!\n");
                    break;
                }
                newDictionary(&dictionaries[numOfDictionaries], &numOfDictionaries);
                break;
            case 2:
                //if user chooses 2 but there are no dictionaries, don't print the menu again
                if (numOfDictionaries == 0) {
                    printTheMenu = 1;
                    printf("This option is not available right now, try again:\n");
                    //scanf("%d", &choiceFromMenu);
                } else {
                    addWord(&numOfDictionaries, dictionaries);
                }
                break;
            case 3:
                //if user chooses 3 but there are no dictionaries, don't print the menu again
                if (numOfDictionaries == 0) {
                    printTheMenu = 1;
                    printf("This option is not available right now, try again:\n");
                } else {
                    deleteWord(&numOfDictionaries, dictionaries);
                }
                break;
            case 4:
                //if user chooses 4 but there are no dictionaries, don't print the menu again
                if (numOfDictionaries == 0) {
                    printTheMenu = 1;
                    printf("This option is not available right now, try again:\n");
                } else {
                    lookupWord(&numOfDictionaries, dictionaries);
                }
                break;
            case 5:
                //if user chooses 5 but there are no dictionaries, don't print the menu again
                if (numOfDictionaries == 0) {
                    printTheMenu = 1;
                    printf("This option is not available right now, try again:\n");
                } else {
                    deleteDictionary(&numOfDictionaries, dictionaries);
                    dictionaries = realloc (dictionaries, numOfDictionaries * sizeof(Dictionary));
                }
                break;
            case 6:
                if (numOfDictionaries > 0) {
                    //call the function for every dictionary separately
                    for (int i = 0; i < numOfDictionaries; i++) {
                        {
                            freeWordList(&dictionaries[i]);
                        }
                    }
                    //free the languages
                    for (int i = 0; i < numOfDictionaries; i++) {
                        free(dictionaries[i].languages[0]);
                        free(dictionaries[i].languages);
                    }
                    //free the dictionaries
                    free(dictionaries);
                    dictionaries = NULL;
                    printf("Bye!");
                    break;
                    default:
                        printf("Wrong option, try again:\n");
                    break;
                }

        }
        //if user chooses 6, exit program
        if (choiceFromMenu == 6)
            break;
    }
}