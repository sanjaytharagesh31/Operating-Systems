#!/bin/sh

for i in *
do
if test -d $i
then
cnt=`expr $cnt + 1`
fi
done
echo "Total directories in home are $cnt"


