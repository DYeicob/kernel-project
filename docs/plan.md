# 🛠️ Educational Kernel Development Plan

## 🧩 Core Modules
- **Round Robin Scheduler**: Implements time-sliced preemptive multitasking.
- **Process Management System**: Manages lifecycles using standard states (**READY**, **RUNNING**, **BLOCKED**).
- **Inter-Process Communication (IPC)**: Facilitates data exchange via message queuing.

## 🎯 Objectives
1. **Process Architecture**: Define and implement the **Process Control Block (PCB)** and linked-list Ready Queue.
2. **Scheduling Logic**: Implement the Round Robin algorithm with a configurable **Time Quantum**.
3. **IPC Design**: Architect a robust message queue system for safe communication between isolated processes.
4. **Validation**: Execute functional unit tests to verify context switching and synchronization.

## 🧵 Process States

- **READY**: The process is loaded in the queue and waiting for CPU allocation.
- **RUNNING**: The process currently holds the CPU and is executing instructions.
- **BLOCKED**: The process is suspended, waiting for an external event (I/O or IPC signal).
