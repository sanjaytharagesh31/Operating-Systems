#!/bin/sh

echo "1) Display the population in reverse order of region name"
echo "2) Display all block files"
echo "3) Display count of processes"
echo "4) Disk usage of population.txt"
echo "5) Exit"
while read c
do
case $c in
"1") sort -rt, -k2 population.txt;;
"2") ls -lR /dev | grep '^b';;
"3") ps aux | wc -l;;
"4") du population.txt;;
"5") exit;;
esac
done