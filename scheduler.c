#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    int completed;
} Process;

int read_processes(const char *filename, Process *processes, int max_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    char line[100];
    fgets(line, sizeof(line), file); // Skip header

    int i = 0;
    while (fscanf(file, "%d %d %d %d",
                  &processes[i].pid,
                  &processes[i].arrival_time,
                  &processes[i].burst_time,
                  &processes[i].priority) == 4) {
        processes[i].completed = 0;
        i++;
        if (i >= max_count) break;
    }

    fclose(file);
    return i;
}

void print_gantt_chart(Process *p, int order[], int n) {
    printf("\nGantt Chart:\n|");
    int time = 0;

    for (int i = 0; i < n; i++) {
        printf(" P%d |", p[order[i]].pid);
    }

    printf("\n0");
    for (int i = 0; i < n; i++) {
        time += p[order[i]].burst_time;
        printf("   %d", time);
    }
    printf("\n");
}

void print_results(Process *p, int n) {
    float total_wt = 0, total_tat = 0;
    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival_time, p[i].burst_time,
               p[i].waiting_time, p[i].turnaround_time);

        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
}

void fcfs(Process *p, int n) {
    int time = 0;
    int order[100];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrival_time > p[j].arrival_time) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival_time)
            time = p[i].arrival_time;
        p[i].waiting_time = time - p[i].arrival_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        time += p[i].burst_time;
        order[i] = i;
    }

    print_gantt_chart(p, order, n);
    print_results(p, n);
}

void sjf(Process *p, int n) {
    int completed = 0, time = 0, order[100], ord_index = 0;

    while (completed < n) {
        int idx = -1, min_bt = 9999;

        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].arrival_time <= time && p[i].burst_time < min_bt) {
                min_bt = p[i].burst_time;
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        p[idx].waiting_time = time - p[idx].arrival_time;
        time += p[idx].burst_time;
        p[idx].turnaround_time = time - p[idx].arrival_time;
        p[idx].completed = 1;
        order[ord_index++] = idx;
        completed++;
    }

    print_gantt_chart(p, order, n);
    print_results(p, n);
}

int main() {
    Process processes[100];
    int count = read_processes("processes.txt", processes, 100);
    if (count <= 0) {
        printf("No processes found.\n");
        return 1;
    }

    int choice;
    printf("Choose Scheduling Algorithm:\n");
    printf("1. First-Come, First-Served (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fcfs(processes, count);
            break;
        case 2:
            sjf(processes, count);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}