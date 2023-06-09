#!/bin/bash

[ $# -eq 3 ] || { echo "$0 prog type ts_no."; exit 1; }

FLAGS='-std=c++17'

if [ $2 == "s" ]; then
    make CPPFLAGS=${FLAGS} $1  && \
    ./$1 < ${1}_sample_ts${3}_input.txt

elif [ $2 == "sd" ]; then
    [ -f ${1}_ts${3}_input.txt ] || { echo "input file not found."; exit 1; }

    make CPPFLAGS=${FLAGS} $1  && \
    ./$1 < ${1}_ts${3}_input.txt
    
elif [ $2 == "c" ]; then
    [ -f ${1}_customized_ts${3}_input.txt ] || { echo "input file not found."; exit 1; }

    make CPPFLAGS=${FLAGS} $1  && \
    ./$1 < ${1}_customized_ts${3}_input.txt

else
    [ -f ${1}_ts${3}_input.txt ] || { echo "input file not found."; exit 1; }

    make CPPFLAGS=${FLAGS} $1  && \
    ./$1 < ${1}_ts${3}_input.txt 2>${1}_ts${3}_err.txt 1>${1}_ts${3}_out.txt  && \
    diff ${1}_ts${3}_out.txt ${1}_ts${3}_output.txt    
    cat  ${1}_ts${3}_err.txt
fi

rm -f $1  
rm -f ${1}_ts*_out.txt
rm -f ${1}_ts*_err.txt
