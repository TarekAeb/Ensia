#! usr/bin/bash

printArgs(){
	if [ $# -lt 1 ]
	then 
		echo "Too few arguments!"
		exit 1
	fi
	echo -e "You have passed to the function the following arguments: \n"
	for i in $@
	do 
		echo "$i"
	done
}


firstArg=23
secondArg=43
thirdArg=53

echo $(printArgs $firstArg $secondArg $thirdArg)