#! /usr/bin/bash

function given_args {

        if [ $# -lt 1 ]
        then
                echo -e "Number of arguments: $#"
                return 1
        else
                echo -e "Number of arguments: $#"
                return 0
        fi
}


# Pass the results of the funtion into a variable
content=$(given_args)

echo -e "$?"
