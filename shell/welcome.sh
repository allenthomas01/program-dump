#!/bin/bash

# Read the user's name 
read -p "Enter your name: " name

# Print the welcome message
echo "Welcome to bash, $name!"

# Get user's age
read -p "Enter your age: " age

# Calculate the birth year
current_year=2023
birth_year=$((current_year - age))

# Print the result
echo "Your birth year is $birth_year."
