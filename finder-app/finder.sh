#!/bin/bash


filedir=$1
searchstr=$2




if [ "$#" -ne 2  ] 
then
echo "please Enter paraments [path] [string]"  
exit 1  
fi



if [ ! -d "${filedir}"  ] 
then
echo "directory not found "  
exit 1  
fi
  
  

X=$(grep -rlw $searchstr $filedir  | wc -l) 
Y=$(grep -rw  $searchstr $filedir  | wc -l)



  echo "The number of files are ${X} and the number of matching lines are ${Y}"




