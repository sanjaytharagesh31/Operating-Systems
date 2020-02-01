#!/bin/sh

touch noDUP.txt
uniq $1 > noDUP.txt