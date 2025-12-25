# 🛡️ OS Project — Scheduler and Inter-Process Communication (IPC)

## 1. Introduction

This project is part of the **Operating Systems** curriculum and consists of implementing a streamlined simulation of an educational kernel. We focus on three fundamental pillars of any modern operating system:

* **Process Management and Representation.**
* **CPU Scheduling** (The Scheduler).
* **Inter-Process Communication (IPC).**

The goal is to understand how processes are managed at a low level, how an OS decides which process executes at any given time, and how processes communicate securely.

---

## 2. Project Architecture

The project follows a modular design to ensure a clear separation of concerns.

```text
src/
├── main.c              # Kernel entry point and simulation loop
├── process.c / .h      # Process Control Block (PCB) and lifecycle logic
├── scheduler.c / .h    # Round Robin implementation
└── ipc.c / .h          # Message passing primitives
include/                # Global definitions and shared constants
docs/                   # Technical reports and diagrams
tests/                  # Unit and integration tests

```

---

## 3. Process Module (`process.c`)

This module implements the **Process Control Block (PCB)** and state management.

### Key Components:

* **`Process` Structure**: Includes PID, current state, priority (optional), remaining quantum, and IPC mailbox.
* **State Management**:
* **READY**: Awaiting CPU allocation.
* **RUNNING**: Currently occupying the CPU.
* **BLOCKED**: Waiting for an I/O or IPC event.
* **FINISHED**: Execution completed; awaiting cleanup.



---

## 4. Scheduler (`scheduler.c`)

The scheduler manages process execution using a **Round Robin (RR)** algorithm, which is standard for time-sharing systems.

### Features:

* **Ready Queue**: A FIFO structure for processes in the READY state.
* **Configurable Quantum**: Defines the time slice each process receives.
* **Simulated Context Switching**: Saving and restoring process metadata.
* **Preemption**: Automatically returning a process to the READY queue once its quantum expires.

---

## 5. Inter-Process Communication (IPC) — `ipc.c`

IPC is implemented via **Message Queues (Mailboxes)**.

### Core Functions:

* `send(dest_pid, message)`: Dispatches data to a specific process.
* `recv(src_pid, &message)`: Retrieves data; triggers an **automatic block** if the mailbox is empty.
* **Synchronization**: Automatically unblocks the receiving process when a message arrives, notifying the scheduler to move it back to the READY state.

---

## 6. System Diagrams

### 6.1. Process State Transitions

Visualizes the flow between:
`NEW` → `READY` ↔ `RUNNING` → `BLOCKED` → `READY` → `FINISHED`.

### 6.2. Scheduler Queue Logic

Demonstrates the circular nature of the RR queue and how the "Time Quantum Expired" event triggers a context switch.

### 6.3. IPC Communication Flow

Illustrates the "Send/Receive" handshake and how the kernel acts as a secure intermediary for message buffering.

---

## 7. Testing and Validation

* **Scheduler Tests**: Verified correct RR rotation and quantum compliance.
* **IPC Tests**: Confirmed that processes correctly block/unblock during message exchanges.
* **Process Integrity**: Ensured that PCBs are allocated and deallocated without memory leaks.

---

## 8. Conclusions

This project provides a practical foundation in kernel design, demonstrating:

1. How abstract processes are represented in memory.
2. The mechanics of fair CPU distribution.
3. The necessity of IPC for cooperative multitasking.

---

## 9. Future Work

Potential evolutions for this "Mini-Kernel" include:

* **Memory Management**: Implementing paging or segmentation.
* **Multilevel Feedback Queues (MLFQ)**: For more advanced scheduling.
* **Virtual File System (VFS)**: To simulate disk I/O.
* **Thread Support**: Introducing lightweight processes.
