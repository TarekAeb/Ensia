# GDSCQuest Session Three: Introduction to bash scripting:

## Outline:
* Learn how to implement the different programming concepts in Bash
* Highlight The main differences between bash scripting and other programming languages
* Learn how to control the flow of your code in Bash
* Get hands-on practice through three different challenges


## Introduction:
* Bash scripting is useful to automate some processes, and not to repeat them
* Scripting has increased our speed and improved our efficiency to perform the different tasks
* A bash script is a series of commands written in the Bash
* Bash is an interpreted language
* A Bash script is executed by the bash interpreter 
* To execute a script, we have to specify the interpreter and tell it which script it should process.
* Why would we prefer to write bash scripts over commands?

## My first Bash script:
* write a script to output Hello world!
  

## Conditionals:
* When defining various conditions, we specify which functions or sections of code should be executed for a specific value. If we reach a specific condition, only the code for that condition is executed, and the others are skipped. As soon as the code section is completed, the following commands will be executed outside the conditional execution.
  
* Syntax:
```Bash
#if statement
if  #condition
then
    #perform some commands
fi

#if/then statement
if
then

else
fi
```
[Example](./ifOnly.sh)
* The conditions of the conditional executions can be defined using variables ($#, $0, $1, $myVar), values (0), and strings
* These values are compared with the comparison operators -eq, -lt, -gt, <, == ...
[Example](./if-elif-else.sh)


## Variables:
* The advantage of bash scripts is that we can always pass up to 9 arguments ($0-$9) to the script without assigning them to variables or setting the corresponding requirements for these
* The first argument $0 is reserved for the script
* Argument 1 is referenced by $1, 2 is by $2 and so on up to the ninth argument that is referenced as $9. This means that we have automatically assigned the corresponding argument to the predefined variables in this place. These variables are known as special variables
* $# is the total number of positional parameters, the positional parameters are those arguments or values passed to a script or funciton when being executed(ofc the script's name is not counted)
* Example
```bash
echo -e "Number of arguments: $#"
```
* Whithin a string surrounded with " ", variables ' values (preceded with $) will be evaluated
* Within a string surrounded with ' ', the variables won't be evaluated
* -e for the echo flag is used to enable the interpretation of escape characters 
* Special variables use the internal field separator (IFS) to identify when an argument ends and the next begins
* The IFS is a special shell variable that defaults to IFS=$' \t\n' It is used by the shell to tokenize strings into fields when interpreting commands.
  
* Here are some of the most commonly used special variables:
* `$#` => the number of arguments passed to a script of a function during the execution
* `$@` => retrieve the list of the command-line arguments
* `$n` => where n is a constant, retrieves the argument passed to the script/function as position n
* `$$` => The process ID of the currently executing process.
* `$?` => The exit status of the script. This variable is useful to determine a command's success. The value 0 represents successful execution, while a nonzero value (usually 1) represents a result of a failure.<br>
[Example](./numberOfArguments.sh)

* The assignment of variables takes place without the dollar sign ($). 
* The dollar sign is only intended to allow this variable's corresponding value to be used in other code sections.
* When assigning variables, there must be no spaces between the names and values. Otherwise, the actual variable name will be interpreted as an internal function or a command.
* Bash does not differentiate between the various types of variables such as float, boolean, integer, string... In bash, all the variables are strings
* Then how can we perform arithmetic on variables?
Bash allows arithmetic on variables depending on whether or not only numbers were assigned to that variable

## Arrays:
* To declare an array in bash, here is what you should do:
```bash
myArray=(1 2 3 4 5)

echo ${myArray[0]}
```
Notice that we use {} for variable expansion especially when the variable's name is followed by some characters that are not part of the variable

<br>

**_Challenge Time :)_**

<br>

## Comparison Operators:
* string operators
* integer operators
* file operators
* boolean operators

## Strings operators:
* `==` 	is equal to
* `!=` 	is not equal to
* `<`	is less than in ASCII alphabetical order
* `>` 	is greater than in ASCII alphabetical order
* `-z` 	if the string is empty (null)
* `-n` 	if the string is not null

* String comparison operators "< / >" works only within the double square brackets [[ <condition> ]]

## Integer Operators:
* -eq 	is equal to
* -ne 	is not equal to
* -lt 	is less than
* -le 	is less than or equal to
* -gt 	is greater than
* -ge 	is greater than or equal to

## File Operators

The file operators are useful if we want to find out specific permissions or if they exist.
* -e  tests if the file exists
* -f  tests whether or not it's a file
* -d 	tests if it is a directory
* -L 	tests if it is if a symbolic link
* -N 	checks if the file was modified after it was last read
* -O 	if the current user owns the file
* -G 	if the file’s group id matches the current user’s
* -s 	tests if the file has a size greater than 0
* -r 	tests if the file has read permission
* -w 	tests if the file has write permission
* -x 	tests if the file has execute permission

## Logical operators:
! 	logical negotation NOT
&& 	logical AND
|| 	logical OR
* Note that you have to surround conditions containing logical operators or strings operators > or < within [[ ... ]]

## Arithmetic operators
+ 	Addition
- 	Substraction
* 	Multiplication
/ 	Division
% 	Modulus
variable++ 	Increase the value of the variable by 1
variable-- 	

## Reading from a file descriptor:
* You can use the command read
```bash
read -p "Select a number between 1 and 10 " mynum
```

## Output control:
* The output must not necessarily be redirected to the standard output(the terminal), yet it can be redirected to somewhere else such as files. The problem with the redirections is that we do not get any output from the respective command. It will just be redirected to the appropriate file. If the script is too long, then they can take much more time than just a few seconds. To avoid sitting inactively and waiting for our script's results, we can use the tee utility. It ensures that we see the results we get immediately and that they are stored in the corresponding files.
  
## controlling the output
* echo "Appending this line" | tee -a output.txt

##  Flow control:
* Controlling the flow of our script is basically specifying which block of code should run before an other and how should be the execution of our scripts
* The flow control is done by one of the following control structures:
  * Branches:
      If-Else Conditions
      Case Statements
  * Loops:
      For Loops
      While Loops
      Until Loops

### Loops:
#### For loop:
* Syntax:
```bash 
for counter in 1 2 3 4
do 
	echo $counter
done
```

### While loop:
* keeps iterating while a condition is true 
* syntax
```bash
while [ some condition ]
do 
	#code to execute
done
```

### Until Loop:
* There is also the until loop, which is relatively rare. Nevertheless, the until loop works precisely like the while loop, but with the difference:

    The code inside a until loop is executed as long as the particular condition is false.
<br>

**_Challenge Time :)_**

<br>

### Branches:
#### Case statements:
* A case statement(switch case statement) is used to compare only the variable with the exact value.
* -gt and -lt operators are not allowed in switch case statement
* syntax
```bash
case <expression> in
	pattern_1 ) statements ;;
	pattern_2 ) statements ;;
	pattern_3 ) statements ;;
esac

```

## Functions:
* As the scripts written in Bash get more large, the readability of your code becomes increasingly crucial. 
* Clear and well-organized code not only facilitates better understanding and maintenance but also promotes collaboration among team members.
* In programming languages, functions are used to improve the readability of our code and to make some portion of the program resuable over and over again (Writing a DRY code)
* By using functions, you can isolate a set of commands through one single block and call it whenever you need it
* To declare a function in Bash, there are mainly two methods:
	* Method 1:

```bash

function commandThatIdonnotRemember {
	tar -czvf "CompressedFolder.tar.gz"  "pathToTheFolderToBeCompressed"
	# other commands
}

```
* Method 2:
  
```bash
commandThatIdonnotRemember() {
	tar -czvf "CompressedFolder.tar.gz"  "pathToTheFolderToBeCompressed"
	# other commands
}
```

* How to call a function?
The function can be called just by referencing the function's name

* How to pass parameters to a function?
parameters are passed to functions in pretty much the same way as we pass them to a shell script. Likewise, you can make reference to any parameter passed to the function used the special variables dicussed previously
* Unlike other prog languages, when you define a variable inside the function's scope, it will be processed globally unless otherwise declared by local. In other words, first time when we define a variable inside a function, the scope of this variable will be global (to the entire script not only to the function)
  
* Example
```bash
#! usr/bin/bash

printArgs(){
	if [ $# -lt 1 ]
	then 
		echo "Too few arguments!"
		exit 1
	fi
	echo -e "You have passed to the function the following arguments: \n"
	for i in $@
	do 
		echo "$i"
	done
}

printArgs 12 43 65 97
```

* Returning values from a function:
Suppose we want to start a new process, say a function call. Then, this process should return a code or a value to the calling process (the parent process) indicating the status of the process, so that the parent process can act accordingly
* Here is the list of some return codes:
<table>
<tr>
<th>Return code</th>
<th>Description</th>
</tr>

<tr>
<td>1</td>
<td>General Error</td>
</tr>

<tr>
<td>126</td>
<td>Command invoked cannot execute</td>
</tr>

<tr>
<td>127</td>
<td>Command not found</td>
</tr>

<tr>
<td>128</td>
<td>Invalid argument to exit</td>
</tr>

<tr>
<td>130</td>
<td>Script terminated by Control-C</td>
</tr>

<tr>
<td>255\*</td>
<td>Exit status out of range</td>
</tr>

</table>


* Here is an example of how we can return values from a function:
  
```bash

function given_args {

        if [ $# -lt 1 ]
        then
                echo -e "Number of arguments: $#"
                return 1
        else
                echo -e "Number of arguments: $#"
                return 0
        fi
}

# No arguments given
given_args
echo -e "Function status code: $?\n"

# One argument given
given_args "argument"
echo -e "Function status code: $?\n"

# Pass the results of the funtion into a variable
content=$(given_args "argument")

echo -e "Content of the variable: \n\t$content"
```

<br>

_**Final Challenge :)**_

<br>

<hr>

<div style="text-align: center;">
  <span style="font-family: 'Comic Sans MS', cursive; font-size: 4rem;">Thank You</span>
</div>


## References:
https://academy.hackthebox.com/module/21/section/129<br><br>
Bash scripting Challenges:<br>
https://github.com/prajwalpd7/BashBlaze-7-Days-of-Bash-Scripting-Challenge/blob/main/Challenges/Day_2/day_2.0_explorer.md<br>
https://www.codecademy.com/resources/blog/bash-script-code-challenges-for-beginners/
<br>
<br>
<br>
<br>

<div style="text-align: right;">
  <span style="font-family: 'Comic Sans MS', cursive; font-size: 1rem;">Aya Benali Khodja</span>
</div>