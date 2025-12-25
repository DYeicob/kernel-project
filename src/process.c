#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "process.h"

// Global pointers for the process management subsystem
static process_t* process_list = NULL; // The head of the Ready Queue
static process_t* current = NULL;      // Pointer to the process currently in the CPU
static int next_pid = 1;               // Simple counter for unique Process IDs

/**
 * Initializes the process management subsystem.
 * In a real kernel, this would set up the initial Process Table.
 */
void init_process_system() {
    printf("[Process] Process management system initialized.\n");
}

/**
 * Creates a new process and appends it to the global process list.
 * Demonstrates basic PCB allocation and initialization.
 */
int create_process(const char* name) {
    process_t* p = malloc(sizeof(process_t));
    if (p == NULL) return -1; // Allocation failure

    p->pid = next_pid++;
    strncpy(p->name, name, sizeof(p->name) - 1);
    p->state = READY;
    p->next = NULL;

    // Add the new process to the end of the linked list
    if (process_list == NULL) {
        process_list = p;
    } else {
        process_t *tmp = process_list;
        while (tmp->next != NULL) tmp = tmp->next;
        tmp->next = p;
    }

    printf("[Process] Created process '%s' (PID=%d)\n", name, p->pid);
    return p->pid;
}

/**
 * Returns a pointer to the process currently being executed.
 */
process_t* get_current_process() {
    return current;
}

/**
 * Implements a simple round-robin selection logic.
 * Advances the 'current' pointer to the next process in the list.
 */
process_t* schedule_next_process() {
    if (process_list == NULL) return NULL;

    // If no process is running, start at the beginning of the list
    if (current == NULL) {
        current = process_list;
    } else {
        // Otherwise, move to the next process or loop back to the head (Circular Queue)
        current = current->next ? current->next : process_list;
    }

    current->state = RUNNING;
    return current;
}
