#!/usr/bin/bash

# Count number of characters in a variable:
#     echo $variable | wc -c

# Variable to encode
var="nef892na9s1p9asn2aJs71nIsm"

for counter in {1..40}
do
    if [ $counter -eq "36" ]
        then 
            echo $var | wc -c
        fi
        var=$(echo $var | base64)
done
