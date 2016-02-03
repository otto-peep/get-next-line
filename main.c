#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_error(char *error_type)
{
	ft_putstr(error_type);
	ft_putchar('\n');
	exit(0);
}

int		ft_close(int fd)
{
	if (close(fd) == -1)
		ft_error("error during close");
	return (0);
}

int	ft_open_rdly(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("error during open");
	return (fd);
}

int main(int argc, char **argv)
{
	int fd1 = 0;
	char *line = NULL;
	int r;
	int i = 1;

	if (argc != 2)
		ft_error("Bad number of argument !");
	 fd1 = ft_open_rdly(argv[1]);
	if (argv[1])
		printf("Fd1: %d\n", fd1);
	while ((r = get_next_line(fd1, &line)) > 0)
	{
		//ft_putstr("test");
		printf("NlFichier1 = %d - r = %d - |%s|\n", i, r, line);
		i++;
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	printf("r: %d", r);
	r = get_next_line(fd1, &line);
	printf("r: %d", r);
	ft_close(fd1);
}
