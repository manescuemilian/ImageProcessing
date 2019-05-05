#!/bin/bash

SAMPLE=$1
OUTPUT=$2

gifsicle $SAMPLE --resize 150x150 > $OUTPUT