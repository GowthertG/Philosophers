#include "philo.h"

void	ms_sleep(int ms)
{
	long	count;

	count = get_time(0);
	while (get_time(count) < ms)
		usleep(300);
}

long	get_time(long ms)
{
	struct timeval	current_time;

	gettimeofday (&current_time, NULL);
	return (((current_time.tv_sec * 1000)
			+ (current_time.tv_usec / 1000)) - ms);
}

void	printf_lock(t_philo *philo, char *str, long time)
{
	pthread_mutex_lock (philo->global->msg);
	printf (str, (int)time, philo->philo_number);
	pthread_mutex_unlock (philo->global->msg);
}

int	next_fork(t_philo *philo)
{
	if (philo->philo_number == philo->global->number_of_philosophers)
		return (0);
	else
		return (philo->philo_number);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	start_eating(t_philo *philo)
{
	int	fork_number;
	int	next_forki;
	// int fork_number = min(philo->philo_number - 1, next_fork(philo));
	// int next_forki = max(philo->philo_number - 1, next_fork(philo));
	fork_number = philo->philo_number - 1;
	next_forki = next_fork(philo);
	pthread_mutex_lock(&philo->global->fork[fork_number]);
	printf_lock(philo, "%d ms philosopher number %d has taken fork\n",
		get_time(philo->global->starter));
	pthread_mutex_lock(&philo->global->fork[next_forki]);
	printf_lock(philo, "%d ms philosopher number %d has taken fork\n",
		get_time(philo->global->starter));
	printf_lock(philo, "%d ms philosopher number %d is eating\n",
		get_time(philo->global->starter));
	ms_sleep(philo->global->time_to_sleep);
	pthread_mutex_unlock(&philo->global->fork[fork_number]);
	pthread_mutex_unlock(&philo->global->fork[next_forki]);
}

void	ft_sleep(t_philo *philo)
{
	printf_lock(philo, "%d ms philosopher number %d is sleeping\n",
		get_time(philo->global->starter));
	ms_sleep(philo->global->time_to_sleep);
}

void	*routine(void *philo)
{
	t_philo	*c_philo;

	c_philo = (t_philo *)philo;
	while (1)
	{
		start_eating(c_philo);
		ft_sleep(c_philo);
		printf_lock(philo, "%d ms philosopher number %d is thinking\n",
			get_time(c_philo->global->starter));
		/*fork_number =  ((t_philo *)(philo))->philo_number - 1;
		pthread_mutex_lock(&c_philo->global->fork[fork_number]);
		printf("philo_number :%d has taken a fork number : %d\n", ((t_philo *)(philo))->philo_number, fork_number);
		pthread_mutex_lock(&c_philo->global->fork[(fork_number + 1) % c_philo->global->number_of_philosophers]);
		printf("philo_number :%d has taken a fork number : %d\n", ((t_philo *)(philo))->philo_number, ((fork_number + 1) % c_philo->global->number_of_philosophers));
		printf("philo_number :%d is eating \n", ((t_philo *)(philo))->philo_number);
		pthread_mutex_unlock(&c_philo->global->fork[fork_number]);
		pthread_mutex_unlock(&c_philo->global->fork[(fork_number + 1) % c_philo->global->number_of_philosophers]);
		printf("philo_number :%d is sleeping\n", ((t_philo *)(philo))->philo_number);
		usleep(60);
		*/
	}
	return (NULL);
}

int	create_thread(t_philo *philo)
{
	int	index;

	philo->global->starter = get_time(0);
	printf("%ld %ld\n", philo->global->starter,
		get_time(philo->global->starter));
	index = 0;
	while (index < philo->global->number_of_philosophers)
	{
		pthread_create(philo[index].thread, NULL, &routine, &philo[index]);
		index += 2;
	}
	usleep(200);
	index = 1;
	while (index < philo->global->number_of_philosophers)
	{
		pthread_create(philo[index].thread, NULL, &routine, &philo[index]);
		index += 2;
	}
	return (0);
}
