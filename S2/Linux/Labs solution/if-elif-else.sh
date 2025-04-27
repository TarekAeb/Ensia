#!/usr/bin/bash

value=$1

if [ $value -eq "100" ]
then 
    echo "The given argument is equal to 100"
elif [ $value -gt "100" ]
then 
    echo "The given argument is greater than 100"
else
    echo "The given argument is less than 100"

fi