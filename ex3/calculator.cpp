#include "calculator.h"

Calculator::Calculator() {
    for (int i = 0; i < 26; ++i) {
        variables[i].variableName = '\0';  // Initialize variableName to null character
        variables[i].variableValue = 0;     // Initialize variableValue to 0
    }
    number = 0;
    errorHandle = 1;
}

void Calculator::inverseElementsInStack() {
    Stack<char> aux;

    while(!expressionStack.isEmpty()){
        aux.push(expressionStack.pop());
    }

    expressionStack = aux;
}

void Calculator::readInput() {
        fstream fin("input.txt");
        ofstream fout("output.txt");

       char current, equal;
       int value;

        if (!fin.is_open()) {
            cerr << "Error opening input file: " << "input.txt" << endl;
            return;
        }

        while (fin >> current){

            if(current == '('){
                expressionStack.push(current);
                break;
            }

            if(!(current >= 'A' && current <= 'Z')){
                fout << "Invalid variable name, can't compute" << endl;
                errorHandle = 0;
                return;
            }

            variables[number].variableName = current;

            fin >> equal;

            if(equal != '='){
                fout << "Invalid operator, operator used should be =" << endl;
                errorHandle = 0;
                return;
            }

            fin >> value;
            variables[number].variableValue = value;

            number++;

        }

        while(fin >> current){
            expressionStack.push(current);
        }

        fin.close();
        fout.close();
}

int Calculator::execute() {
ofstream fout("output.txt");

    // Reverse the expressionStack if needed
    inverseElementsInStack();

    Stack<int> num;
    Stack<char> op;

    while (!expressionStack.isEmpty()) {
        char valueChar = expressionStack.pop();

        if (valueChar == '(' || valueChar == '+' || valueChar == '-' || valueChar == '*' || valueChar == '%' || valueChar == '/') {
            op.push(valueChar);
        }
        else if (valueChar == ')') {
            if (op.isEmpty()) {
                fout << "Invalid expression: Missing operator" << endl;
                errorHandle = false;
                return 0;
            }

            char aux = op.pop();  // Pop the operator

            if (num.isEmpty()) {
                fout << "Invalid expression: Not enough operands" << endl;
                errorHandle = false;
                return 0;
            }

            int num2 = num.pop();

            if (num.isEmpty()) {
                fout << "Invalid expression: Not enough operands" << endl;
                errorHandle = false;
                return 0;
            }

            int num1 = num.pop();

            int result;
            switch (aux) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '%':
                    result = num1 % num2;
                    break;
                case '/':
                    if (num2 == 0) {
                        fout << "Error: Division by zero" << endl;
                        errorHandle = false;
                        return 0;
                    }
                    result = num1 / num2;
                    break;
                default:
                    fout << "Invalid operator: " << aux << endl;
                    errorHandle = false;
                    return 0;
            }

            num.push(result);
        }
        else if (valueChar >= 'A' && valueChar <= 'Z') {
            bool found = false;
            for (int i = 0; i < 26; ++i) {
                if (variables[i].variableName == valueChar) {
                    num.push(variables[i].variableValue);
                    found = true;
                    break;
                }
            }
            if (!found) {
                fout << "Undefined variable: " << valueChar << endl;
                errorHandle = false;
                return 0;
            }
        }
        else {
            fout << "Invalid character in expression: " << valueChar << endl;
            errorHandle = false;
            return 0;
        }
    }

    if (num.isEmpty()) {
        fout << "No result computed" << endl;
        errorHandle = false;
        return 0;
    }

    int finalResult = num.pop();
    fout << "Result = " << finalResult << endl;

    fout.close();

    return finalResult;
}

void Calculator::writeInput() {
   int result;

        if(errorHandle == 1){
            result = execute();
        }
        if(errorHandle == 1){
            //not overwrite over the possible errors found;

            ofstream fout("output.txt");
            fout << "Result = " << result << endl;

            fout.close();
        }
}
