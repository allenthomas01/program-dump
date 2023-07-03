#!/bin/bash

#this is a comment


echo "this is a bash script which runs endlessly unless 'exit' command is given"
while [ 1 ]
do
echo "WHAT COMMAND DO YOU WANT TO DO"

read  command
$command
done


