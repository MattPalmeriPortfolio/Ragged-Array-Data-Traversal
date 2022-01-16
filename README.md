# Ragged-Array-Data-Traversal

Contents
---------------------
* File Contents
* Introduction
* Algorithm
* Requirements

## File Contents
	
	Ragged_Array_Data_Traversal.cpp (program file containing code)

## Introduction
Book practice project from Problem Solving With C++ Chapter 9. Project 5.
Program traverses data over a predefined ragged array. Demonstrates ability to traverse arrays in c++.
Written using Microsoft Visual Studio. 

## Algorithm

	1. Create fixed array of size 4, each index representing a different lab
		1a. for each lab, add a differing # of stations:
			Lab 1: 5 stations
			Lab 2: 6 stations
			Lab 3: 4 stations
			Lab 5: 3 stations
	2. output array - not trivial, but rather a separate for loop per lab
		2a. if it has no user ID (0) output "empty" instead
	3. allow admin to log on user
		3a. take input of lab, station, and user ID, separated by space;
			3aa. throw error if lab or station are oob
	4. allow admin to log off user
		4a. take input of lab and station
			4aa. throw error if either is oob
	5. allow admin to search for user ID
		5a. like outputting, do a separate for loop through each lab and search for user ID
			5aa. return the lab and station if found, error if not
	6. prompt to continue

## Requirements
No requirements or modules needed for running this program.
