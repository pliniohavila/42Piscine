#!/bin/bash

echo "$ ./do-op "
./do-op 
echo "Expect: 1 - Received: $?"

echo "$ ./do-op 1 + 1"
echo "Expect: 2 - Received: "
./do-op 1 + 1

echo "$ ./do-op 42amis - --+-20toto12"
echo "Expect: 62 - Received: "
./do-op 42amis - --+-20toto12

echo "$ ./do-op 1 p 1"
echo "Expect: 0 - Received: "
./do-op 1 p 1

echo "$ ./do-op 1 + toto3"
echo "Expect: 1 - Received: "
./do-op 1 + toto3

echo "$ ./do-op toto3 + 4"
echo "Expect: 4 - Received: "
./do-op toto3 + 4

echo "$ ./do-op foo plus bar"
echo "Expect: 0 - Received: "
./do-op foo plus bar

echo "$ ./do-op 25 / 0"
echo "Expect: 'Stop : division by zero' - Received: "
./do-op 25 / 0

echo "$ ./do-op 25 % 0"
echo "Expect: 'Stop : division by zero' - Received: "
./do-op 25 % 0