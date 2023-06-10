#include "calculatorlogic.h"

double calculateBL(struct ModelState *modelState)
{
    double curNum = ::atof(modelState->currentBuffer.c_str()) , prevNum=::atof(modelState->previousBuffer.c_str()) , result = 0;
    switch(modelState->lastOperation) {
        case OperationTypeEnum::plus:
            result = curNum + prevNum;
        break;
        case OperationTypeEnum::minus:
            result = prevNum - curNum;
        break;
        case OperationTypeEnum::multiply:
            result = curNum * prevNum;
        break;
        case OperationTypeEnum::divide:
            if (curNum == 0) {
                modelState->currentBuffer = "";
                modelState->isEmpty = true;
                result = 987654e-99;
            } else {
                result = prevNum / curNum;
            }
        break;
    default:
        modelState->currentBuffer = "";
        modelState->isEmpty = true;
    }
    return result;
}
