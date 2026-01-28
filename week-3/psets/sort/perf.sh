#!/bin/sh

# quick and dirty shell script for benchmarking the txt files

for executable in ./sort*; do
	echo "Checking with $(basename $executable)"
	echo ""
	[ -e "$executable" ] || continue
	for file in ./txt.d/sorted*; do
		[ -e "$file" ] || continue
		echo "$(basename $file) with $(basename $executable): $(/usr/bin/time -f "%e" "$executable" "$file" 2>&1 >/dev/null)"
	done
	echo ""
	for file in ./txt.d/reversed*; do
		[ -e "$file" ] || continue
		echo "$(basename $file) with $(basename $executable): $(/usr/bin/time -f "%e" "$executable" "$file" 2>&1 >/dev/null)"
	done
	echo ""
	for file in ./txt.d/random*; do
		[ -e "$file" ] || continue
		echo "$(basename $file) with $(basename $executable): $(/usr/bin/time -f "%e" "$executable" "$file" 2>&1 >/dev/null)"
	done
	echo ""
	echo "-------------------------"
	echo ""
done
