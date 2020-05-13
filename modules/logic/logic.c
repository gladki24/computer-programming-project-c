//
// Created by Seweryn on 27.04.2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "../structures.h"
#include "logic.h"
#include "../utils/utils.h"

TLineList* createNewLine(int lineNumber) {
    TLineList* line = (TLineList*) malloc(sizeof(TLineList));
    line->lineNumber = lineNumber;
    line->next = NULL;
}

void addLineNumber(TWordList* list, int lineNumber) {
    TLineList* newLine = createNewLine(lineNumber);
    newLine->next = list->lines;
    list->lines = newLine;
}

TWordList* createNewWord(int lineNumber, wchar_t* word) {
    TWordList* newWord = (TWordList*) malloc(sizeof(TWordList));
    newWord->lines = createNewLine(lineNumber);
    newWord->next = NULL;
    wcscpy(newWord->word, word);

    return newWord;
}

TWordList* prependWordToList(int lineNumber, wchar_t* word, TWordList* list) {
    TWordList* newWord = createNewWord(lineNumber, word);
    newWord->next = list;
    list = newWord;
    return list;
}

TWordList* appendWordToList(int lineNumber, wchar_t* word, TWordList* list) {
    TWordList* tmp = list;
    if (tmp == NULL) {
        prependWordToList(lineNumber, word, list);
    } else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        TWordList* newWord = createNewWord(lineNumber, word);
        tmp->next = newWord;
    }
    return list;
}

void insertWord(wchar_t* word, int lineNumber, TWordList* currentWord, TWordList* lastWord) {
    TWordList* newWord = createNewWord(lineNumber, word);
    newWord->next = currentWord;
    lastWord->next = newWord;
}

TWordList* addWordToList(int lineNumber, wchar_t* word, TWordList* list) {
    TWordList* currentWord = list;
    TWordList* lastWord = list;

    if (!structureExist(currentWord)) {
        list = prependWordToList(lineNumber, word, list);
    } else {
        if (compareWords(currentWord->word, word) == Prepend) {
            list = prependWordToList(lineNumber, word, list);
        } else if (compareWords(currentWord->word, word) == Equals) {
            addLineNumber(list, lineNumber);
        } else {
            while (structureExist(currentWord->next) && compareWords(currentWord->word, word) == Append) {
                lastWord = currentWord;
                currentWord = currentWord->next;
            }
            if (!structureExist(currentWord->next) && compareWords(currentWord->word, word) == Append) {
                list = appendWordToList(lineNumber, word, list);
            } else {
                if (compareWords(currentWord->word, word) == Prepend) {
                    insertWord(word, lineNumber, currentWord, lastWord);
                } else {
                    addLineNumber(currentWord, lineNumber);
                }
            }
        }
    }
    return list;
}

void printWordList(TWordList* list) {
    int count = 0;
    TWordList* tmp;
    TLineList* lineTmp;
    tmp = list;
    while(tmp != NULL) {
        wprintf(L"\n \"%ls\": ", tmp->word);
        lineTmp = tmp->lines;
        while(lineTmp != NULL) {
            wprintf(L"%d, ", lineTmp->lineNumber);
            lineTmp = lineTmp->next;
        }

        tmp = tmp->next;
        count++;
    }

    wprintf(WORD_COUNT_INFORMATION, count);
}

void freeWordList(TWordList* list) {
    TWordList* tmpWord;
    TWordList* nextWord;
    TLineList* tmpLine;
    TLineList* nextLine;

    tmpWord = list;

    while(tmpWord != NULL) {
        tmpLine = tmpWord->lines;
        while(tmpLine != NULL) {
            nextLine = tmpLine->next;
            free(tmpLine);
            tmpLine = nextLine;
        }
        nextWord = tmpWord->next;
        free(tmpWord);
        tmpWord = nextWord;
    }
}

TWordList* createWordListFromLine(int lineNumber, wchar_t* line, TWordList* list) {
    wchar_t* word;
    word = wcstok(line, TOKENS);

    while (word != NULL) {
        list = addWordToList(lineNumber, word, list);
        word = wcstok(NULL, TOKENS);
    }
    return list;
}