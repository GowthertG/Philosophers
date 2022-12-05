#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_list {
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long			starter;
	pthread_mutex_t	*msg;
	pthread_mutex_t	*fork;
}	t_list;

typedef struct s_pjilo
{
	int			philo_number;
	t_list		*global;
	pthread_t	*thread;
}	t_philo;

long	get_time(long ms);
int		check_value(char **numbers);
void	ms_sleep(int ms);
int		check_args(char **argv);
int		ft_atoi(const char *str);
int		error(char *error);
void	printf_lock(t_philo *philo, char *str, long time);
t_philo	*init_philosophers(char **args);
t_list	*init_global(char **args);
t_philo	*init_philosophers(char **args);

//threads
int		create_thread(t_philo *philo);
void	*routine(void *philo);
void	start_eating(t_philo *philo);
void	ft_sleep(t_philo *philo);
int		next_fork(t_philo *philo);
int		min(int a, int b);
int		max(int a, int b);

#endif
