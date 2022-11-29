#include "philo.h"



int main(int argc, char **argv)
{
  (void)(argc);
  
  t_philo *philo;
  if (check_args(argv) || check_value(argv))
    return (error("invalid argument"));
  philo = init_philosophers(argv);
  create_thread(philo);

  while (1);
}
