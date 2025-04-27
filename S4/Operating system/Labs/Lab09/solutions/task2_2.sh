# /bin/bash


for param in "$@"
do
    sum=$((sum + param))
done

echo "The sum of all parameters is: $sum"