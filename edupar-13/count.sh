#!/bin/bash

count_lines() {
	if [ -d "`echo $1 | sed 's/libthread.*/libthread/'`" ]; then # c.c.c.c
		SLOC=`sloccount $1`
		# filter out c++ groups
		if echo $SLOC | grep '^cpp:' >/dev/null 2>/dev/null; then
			echo -n "????,????" 
		else
			C=`  echo "$SLOC" | grep '^ansic:' | sed 's/ansic: *//' | sed 's/ *(.*)//'`
			ASM=`echo "$SLOC" | grep '^asm:'   | sed 's/asm: *//'   | sed 's/ *(.*)//'`
			if [ -z "$C" -o -z "$ASM" ]; then
					echo -n "(huh? couldn't parse)"
			else
					echo -n "$C,$ASM"
			fi
		fi
	else
		echo -n "???,???"
	fi
}

count_group() {
	if [ -d "$1/p3extra" ]; then
		P3DIR=p3extra
	else
		P3DIR=p3
	fi
	echo -n "$1," | sed 's/.*\///'
	count_lines "$1/p2/user/libthread $1/p2/user/autostack.c"
	echo -n ","
	count_lines "$1/$P3DIR/kern"
	echo "";
}

while [ ! -z "$1" ]; do
		if [ ! -d "$1/user/group-00" ]; then
				echo "$1 doesn't look like a 410 semester directory"
				exit 1
		fi
		for i in `ls -d $1/user/group-*`; do
				echo -n "`basename $1`,"
				count_group $i;
		done
		shift
done
