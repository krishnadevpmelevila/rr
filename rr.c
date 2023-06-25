#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 50
#define MAX_QUEUE 1000

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void enqueue(struct Process p, struct Process queue[], int *rear, int *size) {
    if (*size == MAX_QUEUE) {
        printf("Queue is full\n");
        return;
    }
    queue[*rear] = p;
    (*rear)++;
    (*size)++;
}

struct Process dequeue(struct Process queue[], int *front, int *size) {
    if (*size == 0) {
        printf("Queue is empty\n");
        struct Process empty;
        empty.id = -1;
        return empty;
    }
    struct Process p = queue[*front];
    (*front)++;
    (*size)--;
    return p;
}

bool is_empty(int size) {
    return size == 0;
}

int main() {
    int n; // number of processes
    int quantum; // time quantum
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    struct Process processes[MAX_PROCESSES];

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    struct Process queue[MAX_QUEUE];
    int front = 0;
    int rear = 0;
    int size = 0;
    int current_time = 0;

    // Add first process to queue
    enqueue(processes[0], queue, &rear, &size);
    int i = 1;

    // Process each item in the queue using Round Robin scheduling
    while (!is_empty(size)) {
        struct Process current = dequeue(queue, &front, &size);
        int slice = current.remaining_time < quantum ? current.remaining_time : quantum;
        current.remaining_time -= slice;
        current_time += slice;

        // Add new processes to the queue
        while (i < n && processes[i].arrival_time <= current_time) {
            enqueue(processes[i], queue, &rear, &size);
            i++;
        }

        // If the process is not yet finished, add it back to the queue
        if (current.remaining_time > 0) {
            enqueue(current, queue, &rear, &size);
        } else {
            // Calculate completion time, turnaround time and waiting time for the process
            current.completion_time = current_time;
            current.turnaround_time = current.completion_time - current.arrival_time;
            current.waiting_time = current.turnaround_time - current.burst_time;
            printf("Process %d:\n", current.id);
            printf("Completion time: %d\n", current.completion_time);
            printf("Turnaround time: %d\n", current.turnaround_time);
            printf("Waiting time: %d\n\n", current.waiting_time);
        }
    }

    return 0;
}
