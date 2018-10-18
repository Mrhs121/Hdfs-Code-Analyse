#!/bin/bash
for ((a=2004;a<2019;a++))
do
    touch $a.c
    echo "touch {$a}.c"
done
