# CUBESAT

This repository contains the (uncompleted) flight for the CubeSat mission, developed using the **RTEMS (Real-Time Executive for Multiprocessor Systems)** Classic API. The architecture is designed for high reliability, focusing on asynchronous communication between subsystems.

## Project Overview

The software manages data acquisition from sensors and executes (yet to commit) the FDIR (Fault Detection, Isolation,and Recovery) logic.

### Software Architecture
- **Task Sensor (Housekeeping):** Periodically coollects data from the satellite's non critical environment.
- **FDIR LOGIC:** Processes incoming sensor (mission critical and non critical) data and executes Fault Recovery commands.
- **IPC Layer:** A robust messaging system based on RTEMS Message Queues for safe data exchange between tasks (futue triple check to be added).

## File Structure

| File | Description |
| :--- | :---|
| 'init.c' | System initialization and task spawning. |
| 'rtems_msg.h | Global protocol definition (Packed structures for Payload/OBC compatibility). |
| 'ipc_queue.c/h' | Implementation of the Message Queue wapper API. |
| 'task_sensor.c' | Critical and Housekeeping task logic (500ms period). |
| 'task_control.c' | Command processing and safety logic. |

## Requirement & Build

- **Operating System:** RTEMS 5/6/7 (Classic API)
- **Compiler:** 'sparc-rtems-gcc' or 'arm-rtems-gcc' (Depending on the OBC architecture)
- **Build System:** Designed to be compatible with GNU Make or Code::Blocs IDE.

### Communication Protocol
ALL messages follow a standardized 'rtems_msg_t' structure:
- **Header:** Message type and Source/Destination IDs.
- **Timestamp:** Uptime-based synchronization.
- **Payload:** 32-byte data buffer for sensor readings or commands.

# How to Run

1. Configure your RTEMS enviroment variables.
2. Compile the source files:
	'''bash
	# Example for SPARC (Leon3)
	sparc-rtems-gcc -02 -c *.c
3. Link with the RTEMS executive and deploy to the target hardware or QEMU.

## Sensor test software

A simple host-side validation program was added at `tools/sensor_test.c` to verify raw-byte to engineering-units conversion:

```bash
gcc -Iinclude tools/sensor_test.c src/sensor_data.c -o sensor_test
./sensor_test
```

## License
This project uese the GNU 3.0 LICENCE and is developed for educational and aerospace research purposes.
