#!/bin/bash -xe
cd /trabalhoProg/app
gcc main.c -w -l pthread -o main
chmod 777 main