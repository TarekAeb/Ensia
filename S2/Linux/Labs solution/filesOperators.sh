#! usr/bin/bash
if [ $# -lt "1" ]
then
    echo "Less number of arguments"
elif [ -x $1 ]
then    
    echo 1
else
    echo 0
fi
