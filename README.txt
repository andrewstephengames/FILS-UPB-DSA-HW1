EXERCISE 2 - Journey through the desert:

We have a struct "Oasis" which defines how much water an oasis holds and what distance is till the next one
We also have the main class, "JourneyThroughTheDessert", which contains:

-declaration of:
	->"oasis", definde as an Oasis struct type
	->"queueInit, queueAux", the initial queue and the copy which we modify
	->"w", a float variable which tells how much water we have at all time
	->"nrOasis, consuption, aux", intigers, which show how many oasises we have, what is the consuption rate, and an auxiliare that helps us handle errors better

-functions:
	->"readInput", which reads input from the "input.txt" file and puts it in the intiger variables and in the oasis defined by the struct
	->"execute", which takes the input read, checks for errors, and then sees if there is a possible path from the first oasis. If yes, it shows it in the "output.txt" file, if not, it puts the first oasis at the end of the queue and tryes from the next one. If there is no possible path, it shows an according essage in the output file
	->a constructor, that initialises all the private elements from above

User Instruction:

-user must write inside the "input.txt" file the input in this form: number of oasises and consuption rate on first line, separated by space, and on the next lines each oasis, with the amount of water it holds and the distance to the next one.
-the output will be received in the "output.txt" file, which will be either the starting possible oasis, a message saying is impossible to traverse the dessert with the given oasises, or an error message if the input has any mistakes(not enough oasises, consuption rate on 0 or lower, etc)

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
	->a constructor which initialises all the private variables

User instructions:

-user must put the values of variables inside the "input.txt" file. The input takes the form: variable name (from A to Z), equal sign "=", value(a number), everything with no spaces, each variable and value on a different line
-the output will come in the "output.txt" file, either the result, or errors, from which the user will understand his input mistake
