#!/bin/sh

cwd=`pwd`
cd $HOME
cnt=0
for i in *
do
if test -d $i
then
cnt=`expr $cnt + 1`
fi
done
echo "Total directories in home are $cnt"
cd $cwd


