#ifndef CALCULATORLOGIC_H
#define CALCULATORLOGIC_H

#include "operationtypeenum.h"
#include <QString>

#define MAX_NUMBER_SIZE 20

struct ModelState {

    bool isEmpty;

    std::string currentBuffer;

    std::string previousBuffer;

    OperationTypeEnum lastOperation;
};

void addNumber(struct ModelState *modelState, int number);

void addDot(struct ModelState *modelState);

void del(struct ModelState *modelState);

// получает значение для вывода на экран
std::string getScreenValue(struct ModelState *modelState);

// применение математической операции
void applyOperation(struct ModelState *modelState, OperationTypeEnum operation);

double calculateResult(struct ModelState *modelState);

bool isDotAvailable(struct ModelState *modelState);

bool isEqualAvailable(struct ModelState *modelState);

bool isDeleteAvailable(struct ModelState *modelState);

bool isSecondNumberEditing(struct ModelState *modelState);

// очищает буферы и вычисления
void clearModelState(struct ModelState *modelState);

#endif // CALCULATORLOGIC_H
