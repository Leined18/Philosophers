
## Project Description

The **Philosophers** project simulates the classic dining philosophers problem. The goal is to manage access to shared resources (forks) between philosophers in a way that prevents them from entering a state of deadlock or starvation.

Key concepts involved:
- **Threads**: Each philosopher is represented as an independent thread.
- **Mutex (Mutual Exclusion)**: Forks are shared resources managed with mutexes to prevent conflicts.
- **Deadlock & Starvation**: The program must avoid deadlock (when philosophers wait indefinitely) and starvation (when a philosopher never gets to eat).

---

## Compilation
To compile the project, use:
```bash
make
```

This will generate the executable file for the simulation.

---

## Execution
The program is executed with the following command:
```bash
./philo <num_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [num_meals]
```

### Parameters:
- **num_philosophers**: The number of philosophers sitting at the table.
- **time_to_die**: Maximum time (in milliseconds) a philosopher can live without eating. If this time is exceeded, the philosopher dies.
- **time_to_eat**: Time (in milliseconds) a philosopher spends eating.
- **time_to_sleep**: Time (in milliseconds) a philosopher spends sleeping.
- **[num_meals]**: (Optional) The number of meals each philosopher must eat before the simulation ends. If not specified, the simulation runs indefinitely until a philosopher dies.

### Example:
```bash
./philo 5 800 200 200
```
This creates a simulation with 5 philosophers. Each philosopher has 800ms to live without eating, 200ms to eat, and 200ms to sleep.

---

## Notes
- Avoid unnecessary locks to ensure smooth execution.
- Correct synchronization should be implemented to prevent race conditions and ensure that the philosophers behave as expected.

