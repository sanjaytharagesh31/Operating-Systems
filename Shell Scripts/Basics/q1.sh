#!/bin/bash

touch dest
path=$1
cwd=`pwd`
cd $path
files=`ls`
echo $files
for i in $files
do 
if [ -d $i ]
then
l=`ls $path/$i | wc -l`
if [ $l -eq 0 ]
then
echo $i >> $cwd/dest
fi
fi
done
cd $cwd