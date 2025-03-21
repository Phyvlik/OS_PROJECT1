# OS Project - Process Scheduling

## Author
Vivek Patel

## Description
This project simulates CPU scheduling algorithms in an operating system, including:
- **First-Come, First-Served (FCFS)**
- **Shortest Job First (SJF)**
- **Memory Management using First-Fit Allocation (Bonus)**

The program reads process data from an input file (`processes.txt`) and executes scheduling based on user selection. Results include a Gantt chart, waiting times (WT), turnaround times (TAT), and average performance metrics.

---

## Technologies Used
- **C programming**
- **File handling** (reading process input)
- **Process scheduling algorithms**
- **Memory allocation (First-Fit)**

---

## 🚀 How to Run

### **1. Compile the scheduling program:**
```bash
gcc scheduler.c -o scheduler


2. Run the scheduling program:
./scheduler

You will be prompted to choose a scheduling algorithm:
Choose Scheduling Algorithm:
1. First-Come, First-Served (FCFS)
2. Shortest Job First (SJF)
Enter your choice:


3. Compile and run the memory allocation program (optional bonus feature):
gcc memory.c -o memory
./memory


📊 Sample Output
✅ FCFS Execution Example
Choose Scheduling Algorithm:
1. First-Come, First-Served (FCFS)
2. Shortest Job First (SJF)
Enter your choice: 1

Gantt Chart:
| P1 | P2 | P3 | P4 |
0   5   8   12   14

Process	Arrival	Burst	Waiting	Turnaround
P1	0	5	0	5
P2	1	3	4	7
P3	2	4	6	10
P4	3	2	9	11

Average Waiting Time: 4.75
Average Turnaround Time: 8.25


✅ SJF Execution Example
Choose Scheduling Algorithm:
1. First-Come, First-Served (FCFS)
2. Shortest Job First (SJF)
Enter your choice: 2

Gantt Chart:
| P1 | P4 | P2 | P3 |
0   5   7   10   14

Process	Arrival	Burst	Waiting	Turnaround
P1	0	5	0	5
P2	1	3	6	9
P3	2	4	8	12
P4	3	2	2	4

Average Waiting Time: 4


✅ First-Fit Memory Allocation Example (Bonus)
Memory Blocks:
Block 1: 100 KB
Block 2: 500 KB
Block 3: 200 KB
Block 4: 300 KB
Block 5: 600 KB

Processes:
Process 1: 212 KB
Process 2: 417 KB
Process 3: 112 KB
Process 4: 426 KB

Memory Allocation (First-Fit):
Process 1 (Size 212 KB) --> Block 2
Process 2 (Size 417 KB) --> Block 5
Process 3 (Size 112 KB) --> Block 2
Process 4 (Size 426 KB) --> Not Allocated



