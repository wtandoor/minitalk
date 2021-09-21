#include "minitalk.h"

static t_message	g_message;

static	void	get_message(int bit)
{
	g_message.c = g_message.c + ((bit & 1) << g_message.size);
	g_message.size++;
	if (g_message.size == 7)
	{
		ft_putchar_fd(g_message.c, 1);
		if (!g_message.c)
			ft_putchar_fd('\n', 1);
		g_message.c = 0;
		g_message.size = 0;
	}
}

int	main(void)
{
	g_message.c = 0;
	g_message.size = 0;
	ft_putstr_fd("server pid:", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR2, get_message);
		signal(SIGUSR1, get_message);
		pause();
	}
}
