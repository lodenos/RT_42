#!/bin/bash
# 1. Create ProgressBar function
# 1.1 Input is currentState($1) and totalState($2)
function ProgressBar {
# Process data
	HASH="\033[32m#\033[0m"
	let _progress=(${1}*100/${2}*100)/100
	let _done=(${_progress}*4)/10
	let _left=40-$_done
	# Build progressbar string lengths
	_done=$(printf "%${_done}s")
	_left=$(printf "%${_left}s")

	# 1.2 Build progressbar strings and print the ProgressBar line
	# 1.2.1 Output example:
	# 1.2.1.1 Progress : [########################################] 100%
	printf "\r[${_done// /$HASH}${_left// /-}] ${_progress}%%"

}

# Variables
_start=0

# This accounts as the "totalState" variable for the ProgressBar function
_end=100

# Proof of concept
for number in $(seq ${_start} ${_end})
do
	sleep $1
	ProgressBar ${number} ${_end}
done
printf "\n";