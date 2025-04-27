read -p "Select a number between 1 and 10 " mynum
if [ $mynum -eq 10 ]
then 
    echo "Correct"
else
    echo "Try again later :)"
fi