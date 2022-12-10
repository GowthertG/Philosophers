#include "philo.h"

int start_eating(t_philo *philo)
{
  int c_fork;
  int next_fork;

  c_fork = ((t_philo *)(philo))->philo_number - 1;
  next_fork = ((t_philo *)(philo))->philo_number % 5;

return (1);
}
void *routine (void *philo)
{
    start_eating(philo); 
  return (0);
}

int start_routine (t_philo *philo)
{
  pthread_create(philo->thread, NULL, &routine, &philo);
  printf ("philosopher number has been created %d\n", philo->philo_number);

  while (1);
  return (0);
}
int create_philosophers(t_philo *philo)
{
  int index;

  index = 0;
  int pid;


  while (index < philo->global->number_of_philosophers)
  {
    pid = fork();
    if (pid == 0)
      start_routine(&philo[index]);
    index++;
  }
 return(0); 
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	(void)(argc);
  printf ("argc = %d\n", argc);
  if (argc == 5 || argc == 6)
  {
	  if (check_args(argv) )
	  	return (error ("invalid argument"));
	  philo = init_philosophers(argv);
     create_philosophers(philo);
  /*
  create_thread(philo);
	return (third_eye(philo));
  }
*/
  while (1);
  }
  return (error("invalid number of arguments"));
}
  
