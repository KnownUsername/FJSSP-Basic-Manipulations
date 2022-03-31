/*
	Student: João Rodrigues
	Student Number: 16928
	Lective year: 2021/2022

	Subject: Advanced Data Structures
	About: First Practical Work

	File: main.c
	Intent: An interface to allow a user to use functionalities implemented on console

*/

#include "process.h"
#include "operation.h"
#include "job.h"
#include "menus.h"

#include <stdio.h>
#include <string.h>

#pragma warning(disable: 4996)

int main() {

	char input[100];
	int invalid = 1, option, inputtedId = 0;
	float average;
	JobProcess jobProcess;

	int machine, time;

	// Repeat form while invalid input
	while(invalid){

		// Clear console
		system("cls");

		// Display first menu
		ShowFirstMenu();

		scanf("%s", input);

		// Convert string to int, if possible
		option = atoi(input);

		// Valid inputs leave cycle
		if (option && IsNumberBetweenInclusive(option, 1,2)) invalid = 0;
	}

	// Reuse control variable
	invalid = 1;

	Job currentJob;

	// Clear console
	system("cls");
	
	// Load a Job
	if (option == 1) {

		// Menu for creating a file
		ShowFileMenu();

		// Get filename
		scanf("%s", input);

		// Get Job from file
		currentJob = LoadJob(input);
	}

	// Start a new Job
	else {

		// Ask user for an ID for job
		ShowAskForJobID();

		scanf("%s", input);

		// Assign input to Job's identifier
		currentJob.jobIdentifier = strdup(input);
		currentJob.operations = NULL;

	}


	//					Main menu 
	while (option && IsNumberBetweenInclusive(option, 1, 8)) {

		option = 0;

		// Clear console
		system("cls");

		// Menu with all regular options
		ShowAllToolsMenu();

		scanf("%s", input);

		// Convert string to int, if possible
		option = atoi(input);

		// Clean console
		system("cls");



		switch (option) {

		// Show Job
		case 1:

			// Displays job being used
			ShowJob(currentJob);

			// Wait an user input to return to Principal Menu
			// 1st getchar reads enter from previous user's input
			getchar();
			getchar();

			break;

		// Insert Operation 
		case 2:

			ShowInsertOperationMenu();
			scanf("%s", input);

			// Convert string to int, if possible
			inputtedId = atoi(input);

			// Return to Main Menu
			if (inputtedId == -1) break;

			// If id is already taken, it won't insert the Operation
			else if (OperationExists(currentJob.operations, inputtedId)) {
				printf("\nId is already taken!");
				getchar();
				getchar();
				break;
			}
			
			// Invalid ID
			else if (inputtedId <= 0) {
				printf("Id must be a number > 0 \n");
				getchar();
				getchar();
				break;
			}

			// As Operation's ID doesn't exists, it can be created
			currentJob.operations = InsertOperation(currentJob.operations, CreateOperation(inputtedId, NULL));

			printf("Operation Inserted sucessfully!\n");
			getchar();
			getchar();

			break;

		// Remove Operation
		case 3:

			ShowRemoveOperationMenu();
			scanf("%s", input);

			// Convert string to int, if possible
			inputtedId = atoi(input);

			// Return to Main Menu
			if (inputtedId == -1) break;

			// If given ID isn't present on any Operation, there's no Operation to remove
			if (!OperationExists(currentJob.operations, inputtedId)) {
				printf("\nNo Operation with ID = %d, was found\n", inputtedId);
				getchar();
				getchar();
				break;
			}

			// Remove Operation
			currentJob.operations = RemoveOperation(currentJob.operations, inputtedId);

			printf("Operation removed!\n");
			getchar();
			getchar();

			break;

		// Edit Operation
		case 4:
			invalid = 1;
			while (invalid) {

				// Show Operations, for user to know, which ones are available
				ShowOperationList(currentJob.operations);

				printf("If you submit -1, you'll be redirected to Main menu\n");
				printf("\nOperation ID to edit: ");

				scanf("%s", input);

				// Convert string to int, if possible
				inputtedId = atoi(input);

				// Abandon menu to edit an Operation
				if (inputtedId == -1) break;

				// If given ID isn't present on any Operation, there's no Operation to edit
				if (!OperationExists(currentJob.operations, inputtedId)) {
					printf("\nNo Operation with ID = %d, was found\n", inputtedId);
					getchar();
					getchar();
					continue;
				}

				invalid = 0;
			}

			// Return to Main Menu
			if (inputtedId == -1) break;

			// Reuse control variable
			invalid = 1;

			// Store Operation chosen, based on given id, to edit 
			Operation* operationToEdit = SearchOperation(currentJob.operations, inputtedId);

			system("cls");

			while (invalid) {
				// Possible Options to edit an Operation
				ShowEditOperationMenu();

				scanf("%s", input);

				// Convert string to int, if possible
				inputtedId = atoi(input);

				// Leave menu, to main menu
				if (inputtedId == -1) break;

				system("cls");
				switch (inputtedId) {

				// Change Operation id 
				case 1:

					while (invalid) {
						printf("Current Operation id is: %d\n", operationToEdit->opIdentifier);
						printf("To cancel the change, enter -1\n");
						printf("New id: ");

						scanf("%s", input);

						// Convert string to int, if possible
						inputtedId = atoi(input);

						// Return to Main Menu
						if (inputtedId == -1) break;

						// If given ID isn't present on any Operation, there's no Operation to edit
						else if (OperationExists(currentJob.operations, inputtedId)) {
							printf("\nAn Operation with ID = %d, was already created. Please choose a different value!\n", inputtedId);
							getchar();
							getchar();
							continue;
						}

						// Invalid ID
						else if (inputtedId <= 0) {
							printf("Id must be a number > 0 \n");
							getchar();
							getchar();
							break;
						}

						// Change ID
						operationToEdit->opIdentifier = inputtedId;

						printf("Operation has now ID: %d\n", inputtedId);
						getchar();
						getchar();
						invalid = 0;
					}
					break;

				// Add Process
				case 2:

					printf("Add a Process \n\n\n Insert -1 to retrieve to Main Menu\n");
					printf("Machine: ");
					scanf("%s", input);

					// Convert string to int, if possible
					machine = atoi(input);

					// Return to Main Menu
					if (machine == -1) break;

					printf("Time: ");
					scanf("%s", input);

					// Convert string to int, if possible
					time = atoi(input);

					// Return to Main Menu
					if (time == -1) break;


					// Insert Process on Operation's list of Operations
					operationToEdit->alternProcesses = InsertProcess(operationToEdit->alternProcesses, CreateProcess(machine, time));
					printf("Process added with success!");
					getchar();
					getchar();
					
					break;

				// Edit Process
				case 3:

					while (invalid) {
						ShowProcessList(operationToEdit->alternProcesses);
						printf("Insert Process's machine, to change. If inputted -1, you'll be retrieved to Main menu \n");
						printf(">> ");

#pragma region MACHINE_ID
						scanf("%s", input);

						// Convert string to int, if possible
						machine = atoi(input);

						// Return to Main Menu
						if (machine == -1) break;

						// Can't edit a Process that do not exists 
						if (!ProcessExists(operationToEdit->alternProcesses, machine)) continue;

#pragma endregion
#pragma region PRINTS_EDITProcess
						
						system("cls");

						// Menu (information)
						ShowChangeProcessMenuHeader();

						// Show available Processes to help user pick
						ShowProcess(SearchProcess(operationToEdit->alternProcesses, machine)->process);

						// Options of fields to edit
						ShowChangeProcessMenuOptions();

#pragma endregion
						scanf("%s", input);

						// Convert string to int, if possible
						inputtedId = atoi(input);

						// Return to Menu to edit a Process
						if (inputtedId == -1) continue;

						// Change Machine
						else if (inputtedId == 1) {
							do {
								// Clear Console
								system("cls");

								printf("Edit a Process - Change machine value\n");
								printf("Input -1 to go back and submit Process ID again\n\n\n");
								printf("New machine value: ");

								scanf("%s", input);

								// Convert string to int, if possible
								inputtedId = atoi(input);

								// Return to Menu to edit a Process
								if (inputtedId == -1) continue;

								// Invalid ID
								else if (inputtedId <= 0) {
									printf("Id must be > 0 \n");
									getchar();
									getchar();
									break;
								}

								// Existent ID
								else if (ProcessExists(operationToEdit->alternProcesses, inputtedId)) {
									printf("Id is already taken, please try another id!");
									getchar();
									getchar();
									break;
								}

								// Sucess case
								else {
									// Get Process's memory address
									ProcessList* processPtr = SearchProcess(operationToEdit->alternProcesses, machine);
									
									// Change value on memory
									processPtr->process.machine = inputtedId;
									
									printf("Sucessfully changed machine!\n");
									invalid = 0;
									getchar();
									getchar();
								}

							} while (invalid);

						}
						
						// Change Time
						else if (inputtedId == 2) {
							do {
								// Clear Console
								system("cls");

								printf("Edit a Process - Change time value\n");
								printf("Input -1 to go back and submit Process ID again\n\n\n");
								printf("New time value: ");

								scanf("%s", input);


								// Convert string to int, if possible
								time = atoi(input);

								// Return to Menu to edit a Process
								if (time == -1) continue;

								// Invalid ID
								else if (time <= 0) {
									printf("Time must be > 0 \n");
									getchar();
									getchar();
									break;
								}

								// Sucess Case
								else {
									// Get Process's memory address
									ProcessList* processPtr = SearchProcess(operationToEdit->alternProcesses, machine);

									// Change value on memory
									processPtr->process.time = time;

									printf("Sucessfully changed time!\n");
									invalid = 0;
									getchar();
									getchar();
								}

							} while (invalid);
						}
						// Clear console
						system("cls");

					}

					// Return to Main Menu
					if (machine == -1) break;
					break;

				// Remove Process
				case 4:
					while (invalid) {
						ShowProcessList(operationToEdit->alternProcesses);
						printf("Insert Process's machine to remove. If inputted -1, you'll be retrieved to Main menu \n");
						printf(">> ");

#pragma region MACHINE_ID
						scanf("%s", input);

						// Convert string to int, if possible
						machine = atoi(input);

						// Return to Main Menu
						if (machine == -1) break;

						// Can't edit a Process that do not exists 
						if (!ProcessExists(operationToEdit->alternProcesses, machine)) {
							printf("\n Inputted machine wasn't found\n");
							getchar();
							getchar();
							continue;
						}

						// Remove Operation
						operationToEdit->alternProcesses = RemoveProcess(operationToEdit->alternProcesses, machine);

						printf("Process removed with success!\n");
						getchar();
						getchar();
						invalid = 0;
#pragma endregion
					}

					// Reuse control variable
					invalid = 0;
					break;

				// Show Processes
				case 5:

					ShowProcessList(operationToEdit->alternProcesses);
					getchar();
					getchar();
					break;


				default: break;
				}

			}

			break;

		// Maximum time for job and Operations used
		case 5:
			jobProcess = GetMaximumJobProcessLine(currentJob);
			ShowJobProcess(jobProcess);
			getchar();
			getchar();
			break;

		// Minimum time for job and Operations used
		case 6:
			jobProcess = GetMinimumJobProcessLine(currentJob);
			ShowJobProcess(jobProcess);
			getchar();
			getchar();
			break;

		// Average time to complete an Operation
		case 7:
			average = CalculateAverageOperationProcessTime(currentJob.operations);
			printf("Average time to complete an Operation is: %0.4f", average);
			getchar();
			getchar();
			break;

		// Save Job on file
		case 8:
			printf("Filename: ");
			scanf("%s", input);

			// Save job and test if operation was sucessful
			if (SaveJob(currentJob, input)) printf("Sucess on saving to file!");
			else printf("Error on creating file");

			getchar();
			getchar();
			break;

		default: break;
		}
	}
}