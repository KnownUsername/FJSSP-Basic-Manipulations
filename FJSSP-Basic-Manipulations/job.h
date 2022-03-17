/*
	Student: João Rodrigues
	Student Number: 16928
	Lective year: 2021/2022

	Subject: Advanced Data Structures
	About: First Practical Work

	File: job.h
	Intent:
		- Define needed structures for jobs
		- Identify functions to manipulate those structures
*/

#ifndef JOB
#define JOB

#include "operation.h"

/// <summary>
/// Defines 1 job
/// </summary>
typedef struct Job {
	int jobIdentifier; 
	OperationList* operations; // List of operations to complete a job
}Job;

/// <summary>
/// Defines a list of jobs
/// </summary>
typedef struct JobList {
	Job job;
	struct JobList* nextJob;
}JobList;

#endif