#!/bin/bash

find $1 -name "*.cpp" -o -name "*.h" | xargs cat | wc -l
