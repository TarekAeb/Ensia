#shebang line 
#!/usr/bin/bash


value=$1

if [ $value -gt "10" ]
then
    echo "Given argument is greater than 10."
else
    echo "the other case"
fi