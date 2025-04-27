#! /usr/bin/bash

counter=0

while [ $counter -lt 10 ]
do
    ((counter++))
    if [ $counter -eq 3 ]
    then 
        continue
    elif [ $counter -eq 5 ]
    then
        break
    else
    echo "${counter}"
    
    fi
done