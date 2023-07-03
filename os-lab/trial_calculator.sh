#!/bin/bash

echo "enter number 1"
read a

echo "enter number 2"
read b

while [ 1 ]
do
echo
echo "SELECT FROM BELOW OPERATIONS"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
echo "5. Comparison"
echo
echo "enter 0 to exit"
read option

if [ $option==1 ]
then
sum=$(($a + $b))
echo $sum
fi

if [ $option==2 ]
then
diff=$(($a - $b))
echo $diff
fi

if [ $option==0 ]
then
exit
fi
done




