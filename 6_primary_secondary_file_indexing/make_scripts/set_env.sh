#!/bin/bash

folder="env/"

if [ ! -d "$folder" ]; 
then
    python3 -m venv env
    . env/bin/activate
    pip install -e .
fi