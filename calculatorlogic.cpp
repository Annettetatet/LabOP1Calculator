#include "calculatorlogic.h"
#include "operations.h"



double getBufferAsDouble(std::string buffer) {
    double result = atof(buffer.c_str());
    return result;
}

std::string formatDouble(double value) {
    std::string result = std::to_string(value);
    int lastPos = result.length() - 1;
    // ищем с конца ненулевой символ
    while(result[lastPos] == '0') {
        lastPos--;
    }
    // если это точка, то смещаем позиции дальше
    if (result[lastPos] == '.') {
        lastPos--;
    }

    result = result.substr(0, lastPos + 1);

    return result;
}

std::string getScreenValue(struct ModelState *modelState) {
    if (modelState->isEmpty) {
        return "0";
    } else {
        return modelState->currentBuffer;
    }
}

void addNumber(struct ModelState *modelState, int number) {
    // если текущее число больше максимально допустимого, прекращаем ввод
    if (modelState->currentBuffer.size() <= MAX_NUMBER_SIZE) {
        modelState->isEmpty = false;
        if(modelState->currentBuffer == "-0"){
            modelState->currentBuffer = "-" + std::to_string(number);
        }
        if (modelState->currentBuffer == "0"){
            modelState->currentBuffer = std::to_string(number);
        }
        else
            modelState->currentBuffer += std::to_string(number);
        }
}

bool isDotAvailable(struct ModelState *modelState) {
    int dotPos = modelState->currentBuffer.find(".");
    bool res = true;
    if ((dotPos >= 0) || (modelState->currentBuffer.size() > MAX_NUMBER_SIZE - 1)) {
        res = false;
    }
    return res;
}

bool isEqualAvailable(struct ModelState *modelState) {
    return modelState->lastOperation != OperationTypeEnum::none;
}

void addDot(struct ModelState *modelState) {
    if (isDotAvailable(modelState)) {
        if (modelState->isEmpty) {
            modelState->currentBuffer = "0";
            modelState->isEmpty = false;
        }
        modelState->currentBuffer += ".";
    }

}

bool isDeleteAvailable(struct ModelState *modelState) {
    return modelState->currentBuffer.size() > 0;
}

bool isSecondNumberEditing(struct ModelState *modelState) {
    return modelState->previousBuffer.size() > 0;
}

void del(struct ModelState *modelState) {
    if (isDeleteAvailable(modelState)) {
        modelState->currentBuffer.erase(modelState->currentBuffer.end() - 1, modelState->currentBuffer.end());
        if (!isDeleteAvailable(modelState)) {
            modelState->isEmpty = true;
        }
    }
}

void clearModelState(struct ModelState *modelState) {
    modelState->isEmpty = true;
    modelState->currentBuffer = "";
    modelState->previousBuffer = "";
    modelState->lastOperation = OperationTypeEnum::none;
}

double calculate(struct ModelState *modelState) {
    double result = calculateBL(modelState);
    modelState->currentBuffer = formatDouble(result);
    modelState->previousBuffer = "";
    return result;
}

void applyOperation(struct ModelState *modelState, OperationTypeEnum operation) {
    if (modelState->lastOperation == OperationTypeEnum::none) {
        modelState->previousBuffer = modelState->currentBuffer;
        modelState->currentBuffer = "";
        modelState->isEmpty = true;
        modelState->lastOperation = operation;
    } else {
        calculate(modelState);
    }
}

double calculateResult(struct ModelState *modelState) {
    double result = 0;
    if (modelState->lastOperation != OperationTypeEnum::none) {
        result = calculate(modelState);
        modelState->lastOperation = OperationTypeEnum::none;
    }
    return result;
}
