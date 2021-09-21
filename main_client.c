#include "minitalk.h"

static void	send_message(int pid, char *message, int length)
{
	int	i;
	int	step;

	i = 0;
	while (i <= length)
	{
		step = 0;
		while (step < 7)
		{
			if ((message[i] >> step) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			step++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Используйте [pid_server] [message]", 1);
		return (0);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		send_message(pid, argv[2], ft_strlen(argv[2]));
	}
	return (0);
}
