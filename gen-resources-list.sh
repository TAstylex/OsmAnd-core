#!/bin/bash

if [ -d "/opt/local/sbin" ]; then
	export PATH=$PATH:/opt/local/sbin
fi
if [ -d "/opt/local/bin" ]; then
	export PATH=$PATH:/opt/local/bin
fi

SRCLOC="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
PYTHON3=`which python3`
if [ ! -f "$PYTHON3" ]; then
	PYTHON3=`which python3.1`
fi
if [ ! -f "$PYTHON3" ]; then
	PYTHON3=`which python3.2`
fi
if [ ! -f "$PYTHON3" ]; then
	PYTHON3=`which python3.3`
fi
if [ ! -f "$PYTHON3" ]; then
	PYTHON3=`which python3.4`
fi
if [ ! -f "$PYTHON3" ]; then
	echo "Python3 not found in $PATH"
	exit 1
fi

"$PYTHON3" "$SRCLOC/gen-resources-list.py" "$@"
