#! /usr/bin/bash

# Check the given argument
if [ $1 != "GDSC" ]
then
	echo -e "You need to give 'GDSC' as argument."
	exit 1

elif [ $# -gt 1 ]
then
	echo -e "Too many arguments given."
	exit 1

else
	club=$1
	echo -e "Success! You are a member of the family! "
fi