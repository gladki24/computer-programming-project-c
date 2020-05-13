//
// Created by Seweryn on 27.04.2019.
//
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "../structures.h"
#include "cli.h"

void printInstruction() {
    printf("Program wczytuje plik tekstowy i tworzy statystyke slow w nastepujacym formacie:\n");
    printf("\"[Slowo]\": [wiersze wystepowania]\n");
    printf("\n");
    printf("Dostepne przelaczniki: \n");
    printf("-i - plik wejsciowy\n");
    printf("-o - plik wyjsciowy\n");
    printf("Przykladowe wywolanie: src.exe -i=../plik.txt -o=../wynik.txt\n");
}

void searchInputParam(char* param, char* inputSrcResult) {
    int foundedElement;
    char buffer[BUFFER_SIZE];

    foundedElement = sscanf(param, "-i=%s", buffer);
    if (foundedElement != 0) {
        strcpy(inputSrcResult, buffer);
    }
}

void searchOutputParam(char* param, char* outputSrcResult) {
    int foundedElement;
    char buffer[BUFFER_SIZE];

    foundedElement = sscanf(param, "-o=%s", buffer);
    if (foundedElement != 0) {
        strcpy(outputSrcResult, buffer);
    }
}

void searchParams(char* param, TIOConfiguration* configuration) {
    searchInputParam(param, configuration->inputSrc);
    searchOutputParam(param, configuration->outputSrc);
}

void displayErrorNoInputSrc() {
    wprintf(NO_DEFINE_INPUT_FILE);
}

void displayWarningNoOutputSrc() {
    wprintf(NO_DEFINE_OUTPUT_FILE);
}

TConfigurationMode validIOConfiguration(TIOConfiguration* configuration) {
    if (configuration->inputSrc[0] == '\0') {
        displayErrorNoInputSrc();
        return NoInput;
    }

    if (configuration->outputSrc[0] == '\0') {
        displayWarningNoOutputSrc();
        return Input;
    }
    return InputAndOutput;
}

TConfiguration readCLIParams(int paramsCount, char** params) {
    int paramIndex;
    TIOConfiguration ioConfiguration;
    TConfiguration configuration;

    ioConfiguration.inputSrc[0] = '\0';
    ioConfiguration.outputSrc[0] = '\0';

    for (paramIndex = 1; paramIndex < paramsCount; paramIndex++) {
        searchParams(params[paramIndex], &ioConfiguration);
    }

    configuration.IO = ioConfiguration;
    configuration.Mode = validIOConfiguration(&ioConfiguration);

    return configuration;
}
