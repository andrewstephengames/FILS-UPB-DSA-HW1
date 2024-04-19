#include <iostream>
#include <fstream>
#include <cstring>
#include "myStack.h"
using namespace std;


struct Pair{

    char variableName;
    int variableValue;

};

class Calculator{

    private:

    Stack<char> expressionStack;
    Pair variables[26];
    int number;
    bool errorHandle;

    public:

    void inverseElementsInStack(){
        Stack<char> aux;

        while(!expressionStack.isEmpty()){
            aux.push(expressionStack.pop());
        }

        expressionStack = aux;
    }

    void readInput(){

        fstream fin("input.txt");
        fstream fout("output.txt");

       char current, equal;
       int value;

        if (!fin.is_open()) {
            cerr << "Error opening input file: " << "input.txt" << endl;
            return;
        }


        while (fin >> current){

            if(!(current >= 'A' && current <= 'Z')){
                fout << "Invalid variable name, can't compute" << endl;
                errorHandle = 0;
                return;
            }

            if(current == '('){
                expressionStack.push(current);
                break;
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

    int execute(){
        fstream fout("output.txt");

        inverseElementsInStack();

        Stack<int> num;
        Stack<char> op;

        char valueChar;
        int valueInt;

        while(!expressionStack.isEmpty()){
            valueChar = expressionStack.pop();

            if(valueChar == '('  || valueChar == '+'  || valueChar == '-'  || valueChar == '*'  || valueChar == '%' || valueChar == '/'){
                op.push(valueChar);
            }
            else if(valueChar == ')'){
                char aux = op.pop();

                op.pop();

                if(num.peek() >= 1){
                    int num1 = num.pop(), num2 = num.pop();
                    int num3;

                    switch(aux){
                        case '+':
                            num3 = num1 + num2;
                        break;

                        case '-':
                            num3 = num1 - num2;
                        break;

                        case '*':
                            num3 = num1 * num2;
                        break;

                        case '%':
                            num3 = num1 % num2;
                        break;

                        case '/':
                            if(num2 == 0){
                                fout << "Division by o! Be careful at your input!" << endl;
                                errorHandle = 0;
                                return 0;
                            }
                            num3 = num1 / num2;
                        break;
                    }

                    num.push(num3);
                }

                else {
                    fout << "Computations can't be performed, not enough elements, look at your input" << endl;
                    errorHandle = 0;
                    return 0;
                }
            }
            else if(valueChar >= 'A' && valueChar <= 'Z'){
                for(int i = 0; i < 26; i++){
                    if(variables[i].variableName == valueChar){
                        valueInt = variables[i].variableValue;
                    }
                    op.push(valueInt);
                }
            }

            if(!num.isEmpty()){
                fout << "Wrong declaration in the input!" << endl;
                errorHandle = 0;
                return 0;
            }

            if(errorHandle == 1){
                return op.peek();
            }

            fout.close();
        }
    }

    void writeInput(){
        int result;

        if(errorHandle == 1){
            result = execute();
        }
        if(errorHandle == 1){
            //not overwrite over the possible errors found;

            fstream fout("output.txt");
            fout << "Result = " << result << endl;

            fout.close();
        }
    }

    Calculator(){
       
        variables[26] = {NULL};
        number = 0;
        errorHandle = 1;
    }

};

int main(){

    Calculator calculator;

    calculator.readInput();
    calculator.writeInput();

    return 0;
}