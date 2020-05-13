//
// Created by Seweryn on 29.04.2019.
//
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "utils.h"
#include "../structures.h"

void toLowerCase(wchar_t* word, wchar_t* lowerCaseWord) {

    int c;
    wcscpy(lowerCaseWord, word);

    for (c = 0; c < wcslen(word); c++) {
        lowerCaseWord[c] = tolower(word[c]);
    }
}

TCompareResult compareWords(wchar_t* wordA, wchar_t* wordB) {

    wchar_t lowerCaseWordA[WORD_MAX_LENGTH];
    wchar_t lowerCaseWordB[WORD_MAX_LENGTH];
    toLowerCase(wordA, lowerCaseWordA);
    toLowerCase(wordB, lowerCaseWordB);

    return wcscmp(lowerCaseWordA, lowerCaseWordB);
}

int structureExist(void* structure) {
    return structure != NULL;
}