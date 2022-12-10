#ifndef PHILO_H
# define PHILO_H
# define UNUSED -1
# define FALSE 1
# define FULL 2
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_list {
  int       number_of_philosophers;
  int       time_to_die;
  int       time_to_eat;
  int       time_to_sleep;
  int       number_of_times_each_philosopher_must_eat;
  long      starter;
  int       must_eat;
} t_list;

typedef struct s_philo
{
  int     philo_number;
  long    meals;
  long    last_eat;
  t_list    *global;
  pthread_t *thread;
} t_philo;

int	error(char *error);
int	check_value(char **numbers);
int	check_args(char **argv);
int	ft_atoi(const char *str);
t_list	*init_global(char **args);
t_philo	*init_philosophers(char **args);

#endif

