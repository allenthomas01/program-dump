#!/bin/bash

res=0
i="y"
echo -n "Enter a: "
read a

echo -n "Enter b: "
read b

while [ $i=="y" ]
do
echo "1.Add"
echo "2. Subtract"
echo "3.Multiply"
echo "4. Divide"
echo "5. Remainder"
echo -n "Enter your choice: "
read ch

case $ch in
1) res='expr $a+$b'
   echo "sum= " $res;;

2) res='expr $a-$b'
   echo "Difference= " $res;;

3) res='expr $a\*$b'
   echo "Product= " $res;;

4) res='expr $a/$b'
   echo "Quotient= " $res;;

5) res='expr $a%$b'
   echo "Remainder= " $res;;

*)
echo -n "Do you wish to continue: "
read i
esac
done




