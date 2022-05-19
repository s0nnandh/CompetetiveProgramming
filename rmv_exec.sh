#!/bin/bash

for file in $(find . -type f);
do  
    if [ -x "$file" ];then
        rm "$file"
    fi;
done