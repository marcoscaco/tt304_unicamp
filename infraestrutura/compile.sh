#!/bin/bash -xe
cd /trabalhoProg/app
gcc main.c -w -l phthread -o main
chmod 777 main