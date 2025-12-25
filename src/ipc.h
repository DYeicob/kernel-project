#ifndef IPC_H
#define IPC_H

/**
 * @brief Initializes the IPC message queue subsystem.
 * This should be called during the kernel boot sequence.
 */
void init_ipc();

/**
 * @brief Dispatches a message to a target process.
 * * @param to_pid The Process ID of the intended recipient.
 * @param msg    The character buffer containing the data to be sent.
 */
void send_message(int to_pid, const char* msg);

/**
 * @brief Retrieves the next available message for a process.
 * * @param pid The Process ID of the caller attempting to read from its queue.
 */
void receive_message(int pid);

#endif /* IPC_H */
