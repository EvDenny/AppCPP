#!/bin/bash

CC=g++
LDFLAGS="$LDFLAGS"

$CC App.cpp GuessV2.cpp hangman.cpp ArrayTutorial.cpp $LDFLAGS -o AppDebug0-1-4.1
