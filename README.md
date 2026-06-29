*This project has been created as part of the 42 curriculum by epandele.*

---

# 🍝 Philosophers

## 🇬🇧 English

### Description

This project is an implementation of the classic **Dining Philosophers Problem**, a well-known concurrency problem formulated by Edsger Dijkstra.

A number of philosophers sit at a round table with a bowl of spaghetti in the middle. There is one fork between each pair of adjacent philosophers. To eat, a philosopher must pick up both the fork to their left and the fork to their right. After eating, they put the forks down and start sleeping. After sleeping, they start thinking again. The simulation ends when a philosopher dies of starvation, or when all philosophers have eaten a specified number of times.

The goal of this project is to learn the basics of threading and synchronization in C using **POSIX threads** (`pthreads`) and **mutexes**, while avoiding data races and deadlocks.

Key constraints:
- Each philosopher is a separate thread
- Each fork is protected by a mutex
- No global variables allowed
- No data races allowed

---

### Instructions

#### Compilation

```bash
make
```

#### Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

#### Arguments

| Argument | Description |
|---|---|
| `number_of_philosophers` | Number of philosophers (and forks) at the table |
| `time_to_die` | Time in ms before a philosopher dies if they haven't started eating |
| `time_to_eat` | Time in ms it takes a philosopher to eat |
| `time_to_sleep` | Time in ms a philosopher spends sleeping |
| `number_of_times_each_philosopher_must_eat` | (Optional) Simulation stops when all philosophers have eaten this many times |

#### Examples

```bash
# 5 philosophers, should not die
./philo 5 800 200 200

# 4 philosophers, each must eat at least 7 times
./philo 4 410 200 200 7

# 1 philosopher, will die (only one fork available)
./philo 1 800 200 200
```

#### Makefile rules

| Rule | Effect |
|---|---|
| `make` / `make all` | Compile the project |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and executable |
| `make re` | Full rebuild |
| `make help` | Show command reference |

---

### Resources

- [POSIX Threads Programming — Lawrence Livermore National Laboratory](https://hpc-tutorials.llnl.gov/posix/)
- [The Dining Philosophers Problem — Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [pthread_mutex_lock — man page](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)
- [gettimeofday — man page](https://man7.org/linux/man-pages/man2/gettimeofday.2.html)
- [Deadlock — Wikipedia](https://en.wikipedia.org/wiki/Deadlock)

#### AI Usage

AI was used as a study tool to better understand threading concepts and mutexes, and to help identify and fix small bugs during development.

---
---

## 🇮🇹 Italiano

### Descrizione

Questo progetto è un'implementazione del classico **Problema dei Filosofi a Cena**, un noto problema di concorrenza formulato da Edsger Dijkstra.

Un certo numero di filosofi siede attorno a un tavolo rotondo con una ciotola di spaghetti al centro. Tra ogni coppia di filosofi adiacenti è presente una forchetta. Per mangiare, un filosofo deve raccogliere sia la forchetta alla sua sinistra che quella alla sua destra. Dopo aver mangiato, posa le forchette e inizia a dormire. Dopo aver dormito, ricomincia a pensare. La simulazione termina quando un filosofo muore di fame, oppure quando tutti i filosofi hanno mangiato un numero specificato di volte.

L'obiettivo del progetto è imparare le basi del threading e della sincronizzazione in C usando i **thread POSIX** (`pthreads`) e i **mutex**, evitando data race e deadlock.

Vincoli principali:
- Ogni filosofo è un thread separato
- Ogni forchetta è protetta da un mutex
- Variabili globali vietate
- Nessuna data race consentita

---

### Istruzioni

#### Compilazione

```bash
make
```

#### Utilizzo

```bash
./philo numero_filosofi tempo_morte tempo_mangiare tempo_dormire [numero_pasti]
```

#### Argomenti

| Argomento | Descrizione |
|---|---|
| `numero_filosofi` | Numero di filosofi (e forchette) al tavolo |
| `tempo_morte` | Tempo in ms prima che un filosofo muoia se non ha iniziato a mangiare |
| `tempo_mangiare` | Tempo in ms impiegato da un filosofo per mangiare |
| `tempo_dormire` | Tempo in ms che un filosofo trascorre a dormire |
| `numero_pasti` | (Opzionale) La simulazione si ferma quando tutti i filosofi hanno mangiato questo numero di volte |

#### Esempi

```bash
# 5 filosofi, non devono morire
./philo 5 800 200 200

# 4 filosofi, ognuno deve mangiare almeno 7 volte
./philo 4 410 200 200 7

# 1 filosofo, morirà (ha accesso a una sola forchetta)
./philo 1 800 200 200
```

#### Regole del Makefile

| Regola | Effetto |
|---|---|
| `make` / `make all` | Compila il progetto |
| `make clean` | Rimuove i file oggetto |
| `make fclean` | Rimuove i file oggetto e l'eseguibile |
| `make re` | Ricompilazione completa |
| `make help` | Mostra il riferimento ai comandi |

---

### Risorse

- [POSIX Threads Programming — Lawrence Livermore National Laboratory](https://hpc-tutorials.llnl.gov/posix/)
- [Il Problema dei Filosofi a Cena — Wikipedia](https://it.wikipedia.org/wiki/Problema_dei_filosofi_a_cena)
- [pthread_mutex_lock — man page](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)
- [gettimeofday — man page](https://man7.org/linux/man-pages/man2/gettimeofday.2.html)
- [Deadlock — Wikipedia](https://it.wikipedia.org/wiki/Deadlock)

#### Uso dell'IA

L'IA è stata utilizzata come strumento di studio per comprendere meglio i concetti di threading e mutex, e per aiutare a identificare e correggere piccoli bug durante lo sviluppo.