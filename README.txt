EXERCISE 3 - Calculator:

We have a struct "Pair" which defines a type of variable which holds a name(char) and value(int).
We also have the "Calculator" class, which holds:

-declaration of:
	->"expressionStack", which will hold the expression
	->an array "variables" with 26 positions, for all available letters
	->"number", int variable to get the index in the "variavles" array 
	->"errorHandle", boolean, as we had some problems with the error funcions, we made them ourselves

-functions:
	->"inverseElementsInStack", reverses the order of elements in Stack in order to compute
	->"readInput", reads all lines of text aside from the last line of equation and puts them in the "variable" array, handles errors regarding name of variables and "=" sign 
	->"execute", takes the last line, the expression, sees is it is a corresct expression, puts it's elements in the "expressionStack" if it's good, then analyses the stack and computes the expression
	->"writeOutput", writes the result in the output file, in case no error has been confirmed previously

User instructions:

-user must put the values of variables inside the "input.txt" file. The input takes the form: variable name (from A to Z), equal sign "=", value(a number), everything with no spaces, each variable and value on a different line
-the output will come in the "output.txt" file, either the result, or errors, from which the user will understand his input mistake
