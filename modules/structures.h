//
// Created by Seweryn on 29.04.2019.
//

#ifndef SRC_STRUCTRURES_H
#define SRC_STRUCTRURES_H

#endif //SRC_STRUCTRURES_H

#include "configuration.h"

typedef struct IOConfiguration {
    char inputSrc[PARAMS_MAX_LENGTH];
    char outputSrc[PARAMS_MAX_LENGTH];
} TIOConfiguration;

typedef enum ConfigurationMode {
    InputAndOutput,
    Input,
    NoInput
} TConfigurationMode;

typedef struct Configuration {
    TIOConfiguration IO;
    TConfigurationMode Mode;
} TConfiguration;

typedef enum CompareResult {
    Append = -1,
    Equals = 0,
    Prepend = 1
} TCompareResult;

typedef struct LineList {
    unsigned int lineNumber;
    struct LineList* next;
} TLineList;

typedef struct WordList {
    wchar_t word[WORD_MAX_LENGTH];
    struct LineList* lines;
    struct WordList* next;
} TWordList;