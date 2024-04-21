#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "myStack.h"
using namespace std;

struct Pair {
    char variableName;
    int variableValue;
};

class Calculator {
private:
    Stack<char> expressionStack;
    Pair variables[26];
    int number;
    bool errorHandle;
public:
    Calculator();
    void inverseElementsInStack();
    void readInput();
    int execute();
    void writeInput();
};

#endif // CALCULATOR_H
