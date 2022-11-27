#include "philo.h"

void printf_lock(t_philo *philo, char *str)
{
  pthread_mutex_lock(&philo->global->msg);
  printf(str, philo->philo_number); 
  pthread_mutex_unlock(&philo->global->msg);
}

void start_eating(t_philo *philo)
{
  int fork_number;

  fork_number = philo->philo_number - 1;
  pthread_mutex_lock(&philo->global->fork[fork_number]); 
  printf_lock(philo, "philosophers number %d has taken a fork\n");
  pthread_mutex_lock(&philo->global->fork[fork_number + 1 % philo->global->number_of_philosophers]);
  printf_lock(philo, "philosophers number %d has taken a fork\n");
  printf_lock(philo, "philosophers number %d is eating\n");
  usleep(philo->global->time_to_eat);
  pthread_mutex_unlock(&philo->global->fork[fork_number + 1 % philo->global->number_of_philosophers]);
  pthread_mutex_unlock(&philo->global->fork[fork_number]);
}

void ft_sleep(t_philo *philo)
{
  printf_lock(philo, "philosopher number % is sleeping\n");
  usleep(philo->global->time_to_sleep);
}

void *routine(void *philo)
{
  t_philo *c_philo;
  
  c_philo = (t_philo *)philo;
  while (1)
  {
    start_eating(c_philo);
    ft_sleep(c_philo);
    printf_lock(philo, "philosopher number %d is thinking\n");
    
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
  return(NULL);
}

int create_thread(t_philo *philo)
{
  int index;

  index = 0;
  while(index < philo->global->number_of_philosophers)
  {
    pthread_create(&philo->global->id[index], NULL, &routine, &philo[index]);
    usleep(500);
    index++;
  }
  return (0);
}
