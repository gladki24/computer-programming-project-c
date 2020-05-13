//
// Created by Seweryn on 14.05.2019.
//

// Ważne! L przed wartością TOKENS jest obowiązkowe (wide char)

#ifndef SRC_CONFIGURATION_H
#define SRC_CONFIGURATION_H

#endif //SRC_CONFIGURATION_H

// Configuration
#define PARAMS_MAX_LENGTH 128
#define WORD_MAX_LENGTH 64
#define LINE_MAX_LENGTH 1024
#define BUFFER_SIZE 1024
#define TOKENS L",.- /\n\t\r\"\';<>[]()?{}!"

// CLI texts
#define NO_FILE_ERROR L"\nBlad wczytywania pliku wejsciowego"
#define NO_FILE_OUTPUT_ERROR L"\nBlad wczytywania pliku wyjsciowego"
#define NO_DEFINE_INPUT_FILE L"\n Blad! Nie podano ścieżki do pliku wejsciowego\n"
#define NO_DEFINE_OUTPUT_FILE L"\nUwaga! Nie podano pliku wyjsciowego.\nWyniki dzialania programu nie zostana zapisane\n"
#define WORD_COUNT_INFORMATION L"Liczba slow: %d"
