/*
	Student: João Rodrigues
	Student Number: 16928
	Lective year: 2021/2022

	Subject: Advanced Data Structures
	About: First Practical Work

	File: menus.h
	Intent: Makes available, function to print menus on console

*/

#ifndef MENUS
#define MENUS

// Opening menu
void ShowFirstMenu();

// File Menu
void ShowFileMenu();

int IsNumberBetweenInclusive(int value, int minVal, int maxVal);


// Asks user to input an identifier for Job, and gives a space for his input
void ShowAskForJobID();

// Menu after create a Job
void ShowMenuPostCreateJob();

// Menu with all regular options
void ShowAllToolsMenu();

// Menu to remove an Operation
void ShowRemoveOperationMenu();

// Menu to remove an Operation
void ShowInsertOperationMenu();

// Menu with options to edit an Operation
void ShowEditOperationMenu();

// Header of Menu with options to edit a Process
void ShowChangeProcessMenuHeader();

// Options and Input field to choose attribute to edit a Process
void ShowChangeProcessMenuOptions();

#endif