//
// Created by Seweryn on 29.04.2019.
//

#include <stdio.h>
#include "../structures.h"
#include "file.h"

void saveWordList(TWordList* list, FILE* file) {

    TWordList* tmp;
    TLineList* lineTmp;
    tmp = list;

    while(tmp != NULL) {
        fwprintf(file, L"\n \"%ls\": ", tmp->word);
        lineTmp = tmp->lines;
        while(lineTmp != NULL) {
            fwprintf(file, L"%d, ", lineTmp->lineNumber);
            lineTmp = lineTmp->next;
        }
        tmp = tmp->next;
    }
}

int saveToFile(TWordList* list, TConfiguration configuration) {

    FILE* fileToSave;
    fileToSave = fopen(configuration.IO.outputSrc, "wt");

    if (fileToSave == NULL) {
        wprintf(NO_FILE_OUTPUT_ERROR);
        return 1;
    }

    saveWordList(list, fileToSave);
    fclose(fileToSave);
}
