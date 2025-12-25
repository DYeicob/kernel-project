#ifndef SCHEDULER_H
#define SCHEDULER_H

/**
 * @brief Initializes the scheduler subsystem.
 * Sets up global counters and prepares the Ready Queue for execution.
 */
void init_scheduler();

/**
 * @brief Simulates a single system clock tick.
 * This function handles the logic for process execution and 
 * manages context switching when the Time Quantum is exhausted.
 */
void scheduler_tick();

#endif /* SCHEDULER_H */
