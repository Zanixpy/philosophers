## Description

The goal of this project **philosopher** is to learn the basics of **threading a process**. It allows you to learn how to create **threads** and explore the use of **mutexes**.

The program simulates one or more philosophers sitting at a round table with a large bowl of spaghetti in the middle. The philosophers take turns eating, thinking, and sleeping. There are as many forks on the table as there are philosophers. To eat, a philosopher must pick up both the fork to their left and the fork to their right. 

When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. **The main goal of the simulation is to ensure that every philosopher needs to eat and should never starve.**

## Instructions

To compile the program, execute the Makefile with the following command:

```
make
```

The program is executed by passing the following arguments:

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] 
```
- number_of_philosophers: The number of philosophers and also the number of forks

- time_to_die: The time in milliseconds if a philosopher has not started eating since the start of their last meal or the simulation, they die.

- time_to_eat: The time in milliseconds it takes for a philosopher to eat. During that time, they will need to hold two forks.

- time_to_sleep: The time in milliseconds a philosopher will spend sleeping.

- number_of_times_each_philosopher_must_eat (optional): If all philosophers have eaten at least this many times, the simulation stops. If not specified, the simulation stops when a philosopher dies.


## Resources

- [Threads, Mutexes and Concurrent Programming in C](https://www.codequoi.com/en/threads-mutexes-and-concurrent-programming-in-c/)
- [Shichao's Notes](https://notes.shichao.io/apue/ch11/)
- [Geeks for geeks](https://www.geeksforgeeks.org/c/multithreading-in-c/)
- [Multithreading Using pthreads in C language](https://www.youtube.com/watch?v=qPhP86HIXgg)

I used AI to go deeper in the concept of threads and mutex managing.
