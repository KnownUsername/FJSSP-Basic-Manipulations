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
	Job currentJob;

	int machine, time;

	// Repeat form while invalid input
	while (invalid) {

		// Clear console
		system("cls");

		// Display first menu
		ShowFirstMenu();
#pragma region SOURCE_INFO
		scanf("%s", input);

		// Convert string to int, if possible
		option = atoi(input);

		// Valid inputs leave cycle
		if (!option && !IsNumberBetweenInclusive(option, 1, 2)) continue;

#pragma endregion 
		// Clear console
		system("cls");

#pragma region LOAD_JOB
		// Load a Job
		if (option == 1) {

			// Used to know if file was loaded or if doesn't exists
			// 0 -> Doesn't exists
			// 1 -> Loaded successful
			int fileStatus;

			do {
				// Menu for creating a file
				ShowFileMenu();

				// Get filename
				scanf("%s", input);

				// Get Job from file
				currentJob = LoadJob(input, &fileStatus);

				if (!fileStatus) {
					// Convert string to int, if possible
					inputtedId = atoi(input);

					// Leave menu, to main menu
					if (inputtedId == -1) break;
				}
				
				invalid = 0;

			} while (!fileStatus);
		}
#pragma endregion

		// Start a new Job
		else {
#pragma region SCRATCH-CREATED
			// Ask user for an ID for job
			ShowAskForJobID();

			scanf("%s", input);

			// Assign input to Job's identifier
			currentJob.jobIdentifier = strdup(input);
			currentJob.operations = NULL;

			invalid = 0;
#pragma endregion
		}
	}

	//					Main menu 
	while (option && IsNumberBetweenInclusive(option, 1, 8)) {

#pragma region GET-OPTION
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

#pragma endregion

		switch (option) {

		// Show Job
		case 1:
#pragma region SHOW_JOB
			// Displays job being used
			ShowJob(currentJob);

			// Wait an user input to return to Principal Menu
			// 1st getchar reads enter from previous user's input
			getchar();
			getchar();

#pragma endregion
			break;

		// Insert Operation 
		case 2:
#pragma region INSERT_OP
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
#pragma endregion
			break;

		// Remove Operation
		case 3:
#pragma region REMOVE_OP
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
#pragma endregion
			break;

		// Edit Operation
		case 4:
#pragma region CHOOSE_OP
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
#pragma endregion
			// Return to Main Menu
			if (inputtedId == -1) break;

			// Reuse control variable
			invalid = 1;

			// Store Operation chosen, based on given id, to edit 
			Operation* operationToEdit = SearchOperation(currentJob.operations, inputtedId);

			system("cls");

			// Choose option on what to edit
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
#pragma region CHANGE_OP
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
#pragma endregion
					break;

				// Add Process
				case 2:
#pragma region ADD_PROCESS
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

					// If id is already taken, it won't insert the Process
					else if (ProcessExists(operationToEdit->alternProcesses, inputtedId)) {
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

					// Insert Process on Operation's list of Operations
					operationToEdit->alternProcesses = InsertProcess(operationToEdit->alternProcesses, CreateProcess(machine, time));
					printf("Process added with success!");
					getchar();
					getchar();
					
#pragma endregion
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

#pragma region MENU_PROCESS
						// Menu (information)
						ShowChangeProcessMenuHeader();

						// Show available Processes to help user pick
						ShowProcess(SearchProcess(operationToEdit->alternProcesses, machine)->process);

						// Options of fields to edit
						ShowChangeProcessMenuOptions();
#pragma endregion

#pragma endregion
						scanf("%s", input);

						// Convert string to int, if possible
						inputtedId = atoi(input);

						// Return to Menu to edit a Process
						if (inputtedId == -1) continue;

#pragma region CHANGE_MACHINE
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
#pragma endregion
#pragma region CHANGE_TIME
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
#pragma endregion
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
#pragma region REMOVE_PROCESS
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
#pragma endregion
					break;

				// Show Processes
				case 5:
#pragma region SHOW_PROCESSES
					ShowProcessList(operationToEdit->alternProcesses);
					getchar();
					getchar();
					break;
#pragma endregion
				default: break;
				}

			}

			break;

		// Maximum time for job and Operations used
		case 5:
#pragma region MAX_OPERATIONS
			printf("Maximum time unit's quantity, necessary to complete job and corresponding operations\n\n\n");
			jobProcess = GetMaximumJobProcessLine(currentJob);
			ShowJobProcess(jobProcess);
			getchar();
			getchar();
#pragma endregion
			break;

		// Minimum time for job and Operations used
		case 6:
#pragma region MIN-OPERATIONS
			printf("Minimum time unit's quantity, necessary to complete job and corresponding operations\n\n\n");
			jobProcess = GetMinimumJobProcessLine(currentJob);
			ShowJobProcess(jobProcess);
			getchar();
			getchar();
#pragma endregion 
			break;

		// Average time to complete an Operation
#pragma region AVERAGE
		case 7:
			average = CalculateAverageOperationProcessTime(currentJob.operations);
			printf("Average time to complete an Operation is: %0.4f", average);
			getchar();
			getchar();
			break;
#pragma endregion
		// Save Job on file
		case 8:
#pragma region SAVE_JOB
			printf("Filename: ");
			scanf("%s", input);

			// Save job and test if operation was sucessful
			if (SaveJob(currentJob, input)) printf("Sucess on saving to file!");
			else printf("Error on creating file");

			getchar();
			getchar();
#pragma endregion
			break;

		default: break;
		}
	}
}