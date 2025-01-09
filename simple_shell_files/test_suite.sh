#!/bin/bash

echo "Running test suite for #cisfun"

echo "Test 1: /bin/ls"
echo "/bin/ls" | ./hsh

echo "Test 2: nonexistent command"
echo "nonexistent_command" | ./hsh

echo "Test 3: exit command"
echo "exit" | ./hsh

echo "Test 4: empty input"
echo "" | ./hsh

