/*
	Student: João Rodrigues
	Student Number: 16928
	Lective year: 2021/2022

	Subject: Advanced Data Structures
	About: First Practical Work

	File: menus.c
	Intent: Print menus on console

*/

#include <stdio.h>
#include "menus.h"

/// <summary>
/// Prints standard string for user to input an answer 
/// </summary>
void PrintInputReceiver() {
	printf("\n>> ");
}

/// <summary>
/// Shows information about files used for data
/// </summary>
void ShowFilesInfo() {
	// Data Information
	printf("This program uses .csv files to store data.");
	printf("\nYou can find an example, called \"one_job.csv\" that you can load or get to know the data format. \n");
	printf("To use this file, have in mind that is located 1 directory backwards.\n");

	// Blank lines
	printf("\n\n\n");
}

/// <summary>
/// Opening menu
/// </summary>
void ShowFirstMenu() {


	ShowFilesInfo();

	// Display user's options to start
	printf("1. Load a Job from file\n");
	printf("2. Create Job from scratch\n");
	PrintInputReceiver();
}

/// <summary>
/// Checks if an int number is between 2 values, inclusively
/// </summary>
/// <param name="value"></param>
/// <param name="minVal"></param>
/// <param name="maxVal"></param>
/// <returns></returns>
	int IsNumberBetweenInclusive(int value, int minVal, int maxVal) {

	// value must be between min and max value
	if (value >= minVal && value <= maxVal) return 1;
	
	// On false, retrieve 0
	return 0;

}

/// <summary>
/// Menu to choose file to load
/// </summary>
void ShowFileMenu() {

	ShowFilesInfo();
	
	printf("Remember the file can only contain 1 job!\n\n");

	printf("File: ");
}

/// <summary>
/// Asks user to input an identifier for Job, and gives a space for his input
/// </summary>
void ShowAskForJobID() {

	printf("Choose an identifier for your new Job\n\n");
	PrintInputReceiver();
}

/// <summary>
/// Menu after create a Job
/// </summary>
void ShowMenuPostCreateJob() {
	printf("Now that Job has been created with given identifier, start creating components!");
	printf("To do so, create now an Operation for your Job. The ID must be a number higher than 0. \n\n");

	printf("Operation id: ");
}

/// <summary>
/// Menu with all regular options
/// </summary>
void ShowAllToolsMenu() {
	printf("Principal Menu\n\n");
	printf("Choose an option, if a value other than the ones given, is inputted, program closes\n\n");

	printf("1. Show Job\n");
	printf("2. Insert an Operation\n");
	printf("3. Remove an Operation\n");
	printf("4. Edit an Operation\n");
	printf("5. Get maximum time unit's quantity, necessary to complete job and corresponding operations\n");
	printf("6. Get minimum time unit's quantity, necessary to complete job and corresponding operations\n");
	printf("7. Get average time unit's quantity, necessary to complete an operation, considering all alternative possibilities\n");
	printf("8. Save Job on file\n");

	PrintInputReceiver();
}

/// <summary>
/// Menu to remove an Operation
/// </summary>
void ShowRemoveOperationMenu() {
	printf("Remove an Operation \n\n\n  If value -1 is given, you'll be retrieved to Main menu \n");

	printf("Insert operations' ID to remove");
	PrintInputReceiver();
}

/// <summary>
/// Menu to remove an Operation
/// </summary>
void ShowInsertOperationMenu() {
	printf("Insert an Operation. \n\n\n If value -1 is given, you'll be retrieved to Main menu \n");
	printf("Insert new Operation's ID");
	PrintInputReceiver();
}

/// <summary>
/// Menu with options to edit an Operation
/// </summary>
void ShowEditOperationMenu() {
	printf("1. Change Operation ID\n");
	printf("2. Add Process\n");
	printf("3. Edit Process\n");
	printf("4. Remove Process\n");
	printf("5. Show Processes\n");
	PrintInputReceiver();
}

/// <summary>
/// Header of Menu with options to edit a Process
/// </summary>
void ShowChangeProcessMenuHeader() {
	printf("Edit a Process\n");
	printf("Input -1 to go back and submit Process ID again\n\n\n");

}

/// <summary>
/// Options and Input field to choose attribute to edit a Process
/// </summary>
void ShowChangeProcessMenuOptions() {
	printf("1. Change Machine\n");
	printf("2. Change Time");
	PrintInputReceiver();
}