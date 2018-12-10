#!/bin/bash

awk 'BEGIN {print "const char LispLibrary[] PROGMEM ="; print "\"\\"} NR>5{printf "%s\\\n", $0} END {print "\";"}' lib.lisp > LispLibrary.h
