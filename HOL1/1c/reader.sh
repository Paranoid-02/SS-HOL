#!/bin/bash

while true; do
	line=$(cat myfifo)
	echo "Received: $line"
done


