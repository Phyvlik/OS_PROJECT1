#include <stdio.h>

#define MAX_BLOCKS 10
#define MAX_PROCESSES 10

int main() {
    int memory_blocks[MAX_BLOCKS], block_count;
    int process_size[MAX_PROCESSES], process_count;
    int allocation[MAX_PROCESSES];

    // Input number of memory blocks and their sizes
    printf("Enter number of memory blocks: ");
    scanf("%d", &block_count);

    printf("Enter sizes of memory blocks:\n");
    for (int i = 0; i < block_count; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &memory_blocks[i]);
    }

    // Input number of processes and their sizes
    printf("\nEnter number of processes: ");
    scanf("%d", &process_count);

    printf("Enter sizes of processes:\n");
    for (int i = 0; i < process_count; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &process_size[i]);
        allocation[i] = -1; // initialize to -1 (not allocated)
    }

    // First-Fit Allocation
    for (int i = 0; i < process_count; i++) {
        for (int j = 0; j < block_count; j++) {
            if (memory_blocks[j] >= process_size[i]) {
                allocation[i] = j;
                memory_blocks[j] -= process_size[i];
                break;
            }
        }
    }

    // Output allocation results
    printf("\nMemory Allocation (First-Fit):\n");
    for (int i = 0; i < process_count; i++) {
        if (allocation[i] != -1) {
            printf("Process %d (Size %d KB) --> Block %d\n", i + 1, process_size[i], allocation[i] + 1);
        } else {
            printf("Process %d (Size %d KB) --> Not Allocated\n", i + 1, process_size[i]);
        }
    }

    return 0;
}
