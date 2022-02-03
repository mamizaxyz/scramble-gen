#!/bin/sh

set -xe
cc -Wall -Werror -pedantic -std=c11 -o scramble-gen scramble-gen.c
