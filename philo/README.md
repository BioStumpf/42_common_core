*This project has been created as part of the 42 curriculum by \<dstumpf\>.*

# philo
## Description

A multithreaded implementation of the classic **Dining Philosophers** problem, built for 42's Common Core. Each philosopher is simulated as a POSIX thread that alternates between eating, sleeping, and thinking, competing with its neighbors for a shared pair of forks. The goal is to keep every philosopher alive and fed without deadlocks or data races.

`N` philosophers sit around a circular table with `N` forks between them (one fork per pair of neighbors). To eat, a philosopher needs both the fork on its left and the fork on its right. If a philosopher goes too long without eating, it dies — and the simulation must detect and report that death as close to real time as possible.

This implementation handles that with:

- One `pthread_t` per philosopher, all running the same routine (`phil`).
- One `pthread_mutex_t` fork per philosopher, shared between neighbors.
- A dedicated `stop_lock` mutex guarding a shared `stop` flag, used to broadcast "the simulation is over" to every thread.
- Per-philosopher locks guarding each philosopher's own state (`died`, `times_eaten`, `last_eaten`).
- A monitoring loop on the main thread that continuously checks whether any philosopher has starved, or whether everyone has finished eating.

## Instructions

```sh
make
```

This compiles all sources into an object directory (`obj/`) with generated dependency files (`dep/`) and links the `philo` binary. Standard targets are available:

```sh
make        # build
make clean  # remove object/dependency files
make fclean # remove object/dependency files and the binary
make re     # fclean + build
```

## Usage

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

| Argument | Meaning |
|---|---|
| `number_of_philosophers` | Number of philosophers and forks |
| `time_to_die` (ms) | If a philosopher doesn't start eating within this time of its last meal, it dies |
| `time_to_eat` (ms) | Time a philosopher spends eating once it has both forks |
| `time_to_sleep` (ms) | Time a philosopher spends sleeping after eating |
| `number_of_times_each_philosopher_must_eat` (optional) | If given, the simulation stops once every philosopher has eaten this many times |

Example:

```sh
./philo 5 800 200 200
./philo 4 410 200 200 7
```

All arguments are parsed with a custom `ft_atoi`. Invalid argument counts, non-positive philosopher counts, or non-positive time values cause the program to exit early.

## Output format

Every state change is timestamped relative to the start of the simulation and printed as:

```
<timestamp_ms> <philosopher_id> has taken a fork
<timestamp_ms> <philosopher_id> is eating
<timestamp_ms> <philosopher_id> is sleeping
<timestamp_ms> <philosopher_id> is thinking
<timestamp_ms> <philosopher_id> died
```

Philosopher IDs are 1-indexed in the output even though they're tracked 0-indexed internally.

## Design notes

**Thread lifecycle.** All philosopher threads are created up front and immediately block in `wait_for_start`, polling the shared `start` flag under `stop_lock`. Once every thread is spawned, `gettimeofday` captures `sim_start` and `start_sim` releases them all at (almost) the same instant, so timestamps are comparable across philosophers.

**Single philosopher edge case.** With only one philosopher there's only one fork, so it can never eat. `phil` special-cases this (`one_phil`): the philosopher picks up its one fork, waits out `time_to_die`, and dies — matching the expected behavior of the classic problem.

**Avoiding deadlock.** With `N` philosophers each trying to grab a left and a right fork, naively picking up "left, then right" in every thread deadlocks when everyone grabs their left fork simultaneously. This is avoided by having odd- and even-numbered philosophers pick up forks in opposite order (`pickup_forks`), so at least one philosopher will always successfully acquire both forks. Additionally, odd-numbered philosophers offset their start slightly (`usleep(eat_time / 2)`) to further reduce fork contention.

**Death detection.** Each philosopher's `last_eaten` timestamp is updated (under its own lock) every time it starts eating. A central loop in `simulation_done` walks every philosopher, checking if anyone died, and as soon as one is found to be starved, sets the global `stop` flag and prints the death message. Because every blocking action (`pickup_fork`, `ph_eat`, `ph_sleep`, `ph_think`) also checks `stop`/`died` itself before proceeding, philosophers unwind quickly instead of continuing to act after the simulation should have ended.

**Odd philosopher counts and think time.** When there's an odd number of philosophers and sleep time doesn't exceed eat time, an extra `think_time` is calculated (`1000 + (eat_time - sleep_time)`) to help even out fork availability and reduce starvation in tightly-timed configurations.

**Shutdown.** Once the simulation ends (a death or everyone satisfied), `sim_cleanup` flips `stop` (and briefly `start`, to unblock any thread still waiting to begin), joins every thread, and destroys all mutexes — including the forks and `stop_lock`.

## File layout

| File | Responsibility |
|---|---|
| `main.c` | Entry point, argument validation, allocation of philosophers/forks |
| `philo.h` | Shared types (`t_philo`, `t_dat`) and function prototypes |
| `ft_atoi.c` | Custom argument parsing (no libc `atoi`) |
| `simulation.c` | Mutex/thread initialization, simulation start, main monitoring loop |
| `simulation_threads.c` | The per-philosopher thread routine (`phil`), single-philosopher case |
| `simulation_control.c` | Start/stop signaling, per-tick death/completion checks |
| `eat.c` | Fork pickup/putdown logic, ordered locking to prevent deadlock |
| `think_sleep.c` | Sleeping and thinking routines |
| `time.c` | Relative-time helper and death check |
| `print.c` | Timestamped state-change logging |
| `cleanup.c` | Thread joining and mutex destruction |

## Resources
- To understand threads and mutexes, the [Linux man pages online](https://man7.org/linux/man-pages/) were used.
- To understand threads and mutexes, the [Introduction To Threads (pthreads) | C Programming Tutorial youtube video](https://www.youtube.com/watch?v=ldJ8WGZVXZk) was used.
