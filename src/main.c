#include <stdio.h>
#include "scheduler.h"
#include "process.h"
#include "ipc.h"

/**
 * Academic Kernel Entry Point
 * This file orchestrates the initialization of the OS subsystems
 * and executes the primary scheduling loop.
 */
int main() {
    // 1. Subsystem Initialization Phase
    init_process_system(); // Allocate PCB tables
    init_ipc();            // Setup message queues
    init_scheduler();      // Configure Round Robin parameters

    printf("--- Academic Mini-Kernel Boot Sequence Complete ---\n");

    // 2. Process Creation Phase
    // These processes are added to the READY queue
    create_process("Process A");
    create_process("Process B");
    create_process("Process C");

    // 3. Kernel Execution Loop
    // Simulates 10 clock ticks to observe context switching
    printf("Starting system execution loop...\n");
    for (int i = 0; i < 10; i++) {
        scheduler_tick();
    }

    printf("\n--- Simulation Finished Successfully ---\n");

    return 0;
}
