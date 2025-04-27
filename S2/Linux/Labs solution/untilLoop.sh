#! /usr/bin/bash

counter=0
until [ $counter -eq 4 ]
do 
    echo "${counter}"
    ((counter++))
done