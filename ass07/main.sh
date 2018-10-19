#!/bin/sh

echo "start of script"
echo "cat all files"
cat /sys/kernel/debug/forytwo/id
cat /sys/kernel/debug/forytwo/foo
cat /sys/kernel/debug/forytwo/jiffies
echo "get kernel info"
RED
echo "test id"
cat file > /sys/kernel/debug/fortytwo/id
cat /sys/kernel/debug/forytwo/id
echo rburger > /sys/kernel/debug/fortytwo/id
cat /sys/kernel/debug/forytwo/id
echo 123 > /sys/kernel/debug/fortytwo/id
cat /sys/kernel/debug/forytwo/id
echo "get kernel info"
RED

echo "test foo"
cat file > /sys/kernel/debug/fortytwo/foo
cat /sys/kernel/debug/forytwo/foo
cat filePage > /sys/kernel/debug/fortytwo/foo
cat /sys/kernel/debug/forytwo/foo
cat fileJiff > /sys/kernel/debug/fortytwo/foo
cat /sys/kernel/debug/forytwo/foo
cat fileJiffXL > /sys/kernel/debug/fortytwo/foo
cat /sys/kernel/debug/forytwo/foo
echo rburger > /sys/kernel/debug/fortytwo/foo
cat /sys/kernel/debug/forytwo/foo
echo 123 > /sys/kernel/debug/fortytwo/foo
cat /sys/kernel/debug/forytwo/foo
echo "get kernel info"
RED

echo "test jiffies"
cat file > /sys/kernel/debug/fortytwo/jiffies
cat /sys/kernel/debug/forytwo/jiffies
echo rburger > /sys/kernel/debug/fortytwo/jiffies
cat /sys/kernel/debug/forytwo/jiffies
echo 123 > /sys/kernel/debug/fortytwo/jiffies
cat /sys/kernel/debug/forytwo/jiffies
echo "get kernel info"
RED

echo "end of script"

instruction()
{
	INS=$1
	FILE=$2
	FOLDER="ass05/"
	
	if [ $1 == "cat" ]; then
		cat $FOLDER$FILE
	else [  ]
	fi

	echo "in ft: $INS $FOLDER$FILE"

}

instruction cat main.c
