#include "philo.h"



int main(int argc, char **argv)
{
  int index;
  (void)(argc);
  
  t_philo *philo;
  if (check_args(argv) || check_value(argv))
    return (error("invalid argument"));
  philo = init_philosophers(argv);
  create_thread(philo);

  index = 0;
  while (index <  philo[0].global->number_of_philosophers)
     pthread_join(philo->global->id[index++], NULL);
}
