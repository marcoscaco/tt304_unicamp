#!/bin/bash -xe
cd /trabalhoProg/app
gcc main.c -w -l phthreds -o main
chmod 777 main