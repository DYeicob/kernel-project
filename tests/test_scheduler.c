#include <stdio.h>
#include "../src/scheduler.h"
#include "../src/process.h"

/**
 * Scheduler Simulation Test
 * Demonstrates process creation and the Round Robin execution flow.
 */
int main() {
    // Initialize the underlying process structures and PCB tables
    init_process_system();
    
    // Initialize the scheduler queues and set the default Time Quantum
    init_scheduler();

    // Create mock processes to populate the READY queue
    create_process("Test1");
    create_process("Test2");

    printf("Starting Scheduler Tick Simulation...\n");

    // Simulate 5 system clock ticks to observe process rotation (Preemption)
    for (int i = 0; i < 5; i++) {
        printf("\n--- System Tick %d ---\n", i + 1);
        scheduler_tick();
    }

    return 0;
}
