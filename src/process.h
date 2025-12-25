#ifndef PROCESS_H
#define PROCESS_H

/**
 * @brief Represents the possible lifecycle states of a process.
 */
typedef enum { 
    READY,   // Waiting for the CPU
    RUNNING, // Currently executing
    BLOCKED  // Waiting for an I/O or IPC event
} state_t;

/**
 * @brief The Process Control Block (PCB) structure.
 * This structure tracks the identity and state of a process
 * within the kernel's memory space.
 */
typedef struct process {
    int pid;                // Unique Process Identifier
    char name[32];          // Process name for debugging/logging
    state_t state;          // Current execution state
    struct process *next;   // Pointer to the next process (Linked List)
} process_t;

/**
 * @brief Initializes the process management subsystem.
 */
void init_process_system();

/**
 * @brief Allocates and initializes a new process.
 * @param name The human-readable name of the process.
 * @return The assigned PID of the new process.
 */
int create_process(const char* name);

/**
 * @brief Retrieves the process currently occupying the CPU.
 * @return Pointer to the RUNNING process.
 */
process_t* get_current_process();

/**
 * @brief Selects the next process to run based on Round Robin logic.
 * @return Pointer to the newly selected process.
 */
process_t* schedule_next_process();

#endif /* PROCESS_H */
