#! /usr/bin/env bash

echo

echo -e "./philo 5 1000 200 300 10"
./philo 5 1000 200 300 10
echo -e "Exit status $?\n"

echo "./philo 5 1000 2147483647 300 10"
./philo 5 1000 2147483647 300 10
echo -e "Exit status $?\n"

echo "./philo 5 1000 2147483648 300 10"
./philo 5 1000 2147483648 300 10
echo -e "Exit status $?\n"

echo "./philo 5 1000 200 300 -10"
./philo 5 1000 200 300 -10
echo -e "Exit status $?\n"

echo "./philo 5 1000 200 300 +10"
./philo 5 1000 200 300 +10
echo -e "Exit status $?\n"

echo "./philo 5 1000 200 300 aaa10"
./philo 5 1000 200 300 aaa10
echo -e "Exit status $?\n"
