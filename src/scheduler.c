#include <stdio.h>
#include "scheduler.h"
#include "process.h"

// Configuration for the Round Robin algorithm
static int quantum = 2;          // Maximum time slices allowed per process
static int quantum_counter = 0;  // Tracks current elapsed slices

/**
 * Initializes the scheduler subsystem.
 */
void init_scheduler() {
    printf("[Scheduler] Subsystem initialized successfully.\n");
}

/**
 * Simulates a hardware timer interrupt.
 * This function manages context switching based on the Time Quantum.
 */
void scheduler_tick() {
    process_t *p = get_current_process();

    // If no process is currently in the CPU, select the first one
    if (p == NULL) {
        p = schedule_next_process();
        return;
    }

    quantum_counter++;

    printf("[Scheduler] Executing process: %s (PID=%d)\n", p->name, p->pid);

    // Check if the current process has exhausted its allocated time
    if (quantum_counter >= quantum) {
        printf("[Scheduler] Time Quantum expired. Performing context switch...\n");
        
        // Reset the counter and select the next process from the READY queue
        quantum_counter = 0;
        schedule_next_process();
    }
}
