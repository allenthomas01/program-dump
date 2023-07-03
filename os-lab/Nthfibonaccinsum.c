#!/bin/bash

echo -n "enter limit "
read n
f=0
s=1
i=1

echo "which number you need"
read a

while [ $i -lt $n ]
do
t=$(($f + $s))
f=$s
s=$t
 if [ $i -eq $(($a -1)) ]
 then
 echo $a"th fibonnaci number is "$t
 fi
i=$(($i+1))
done


