#! usr/bin/bash

for i in {100..1..-1}
do
	tar -xzvf dir${i}.tar.gz
	rm -rf dir${i}.tar.gz
done
