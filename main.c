#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#include "modules/cli/cli.h"
#include "modules/logic/logic.h"
#include "modules/file/file.h"
#include "modules/structures.h"

int main(int argv, char** args) {

    // get configuration form command line
    TConfiguration configuration = readCLIParams(argv, args);
    FILE* inputFile;
    wchar_t line[LINE_MAX_LENGTH];
    int lineNumber = 1;
    TWordList* wordList = NULL;

    setlocale(LC_ALL, "pl_PL.UTF-8");
    printInstruction();

    // If user doesn't determine input file close program
    if (configuration.Mode == NoInput) {
        return 1;
    }

    // open file
    inputFile = fopen(configuration.IO.inputSrc, "rt");

    // If file doesn't exist close file
    if (inputFile == NULL) {
        wprintf(NO_FILE_ERROR);
        return 1;
    }

    // Use polish characters
    fwide(inputFile, 1);

    // process files line by line
    while (fgetws(line, LINE_MAX_LENGTH, inputFile) != NULL) {
        wordList = createWordListFromLine(lineNumber, line, wordList);
        lineNumber++;
    }

    fclose(inputFile);
    printWordList(wordList);

    // save to file if user determine output file
    if (configuration.Mode == InputAndOutput) {
        saveToFile(wordList, configuration);
    }

    freeWordList(wordList);

    return 0;
}