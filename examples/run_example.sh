#!/bin/bash
# Kernel Simulation Launcher
# This script automates the build process and starts the kernel execution.

echo "--- Initializing Academic Kernel Simulation ---"

# Step 1: Compile the project using the Makefile
# This ensures all dependencies are linked and the binary is up to date.
echo "Step 1: Building project binaries..."
make

# Check if the build was successful before proceeding
if [ $? -eq 0 ]; then
    echo "Build successful."
    echo "-----------------------------------------------"
    
    # Step 2: Execute the compiled kernel binary
    echo "Step 2: Launching Kernel..."
    ./kernel
else
    echo "Error: Build failed. Please check the source code for errors."
    exit 1
fi
