#!/bin/bash

while true; do
	read line
	echo "$line" > myfifo
done
