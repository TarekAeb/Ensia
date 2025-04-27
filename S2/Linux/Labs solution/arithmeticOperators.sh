#! usr/bin/bash

echo "10 + 10 =$((10+10))"
echo "10 * 10 =$((10*10))"
echo "10 / 10 = $((10/10))"
echo "10 - 10 = $((10-10))"

var=12
echo "Before incrementing var: $var"
((var++))
echo "After incrementing var: $var"