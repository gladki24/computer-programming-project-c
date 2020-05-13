//
// Created by Seweryn on 27.04.2019.
//

#ifndef SRC_LOGIC_H
#define SRC_LOGIC_H

#endif //SRC_LOGIC_H

struct WordList* createWordListFromLine(int lineNumber, wchar_t* line, struct WordList* list);
void printWordList(struct WordList* list);
void freeWordList(struct WordList* list);