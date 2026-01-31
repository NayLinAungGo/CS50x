#!/bin/bash

parallel --joblog results.txt "./sort{1} {2}" ::: {1..3} ::: txt.d/*.txt > /dev/null
