#!/bin/sh
awk -F',' '$2 ~ /CARIB/' population.txt > new.txt
sort -t, -k3,3n new.txt

ln -s population.txt link1.txt
ln -s population.txt link2.txt
