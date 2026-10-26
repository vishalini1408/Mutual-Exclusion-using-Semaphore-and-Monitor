# Mutual-Exclusion-using-Semaphore-and-Monitor
# Experiment 4: Mutual Exclusion using Semaphore and Monitor

**Aim:** To implement mutual exclusion using a semaphore and a mutex, following the Operating Systems lab manual (Experiment 4). The manual's Part B uses a mutex; it does not provide a separate monitor implementation in the shown experiment.

## Part A — Semaphore (`experiment4_semaphore.c`)

A semaphore initialized to 1 protects the shared ATM balance. Each customer thread withdraws 100 while holding the semaphore, so only one thread updates the balance at a time.

Compile and run on Linux/Ubuntu:

```bash
gcc experiment4_semaphore.c -o experiment4_semaphore -pthread
./experiment4_semaphore
```

Example input: `3`. The output order can vary because threads may run in different orders. The balance values should decrease from 1000 by 100 per customer.

Manual output image: [`experiment4_semaphore_output.png`](experiment4_semaphore_output.png)

## Part B — Mutex (`experiment4_mutex.c`)

A mutex protects the shared parking-slot count. Each vehicle thread locks the mutex, decrements the count, prints the remaining slots, and unlocks the mutex.

Compile and run on Linux/Ubuntu:

```bash
gcc experiment4_mutex.c -o experiment4_mutex -pthread
./experiment4_mutex
```

Example input: `3`. The output order can vary. The available slot count decreases from 5 by 1 per vehicle.

Manual output image: [`experiment4_mutex_output.png`](experiment4_mutex_output.png)

## Files

- `experiment4_semaphore.c` — Part A semaphore program
- `experiment4_mutex.c` — Part B mutex program
- `experiment4_semaphore_output.png` — original output screenshot extracted from the supplied manual
- `experiment4_mutex_output.png` — original output screenshot extracted from the supplied manual
