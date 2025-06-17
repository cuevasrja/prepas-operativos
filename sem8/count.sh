#!/bin/bash

# This is a simple script to count the number of times a word appears in a file.
if [ $# -ne 2 ]; then
    echo -e "\033[91;1mUsage:\033[0m $0 <word> <file>"
    exit 1
fi
word=$1
file=$2
if [ ! -f "$file" ]; then
    echo -e "\033[1;91mFile not found!\033[0m"
    exit 1
fi
count=$(grep -o -i -c "$word" "$file")
echo -e "\033[1;92mThe word '$word' appears $count times in the file '$file'.\033[0m"