#include "get_next_line.h"

int	main (void)
{
	char	*s;
	int		fd1;

	fd1 = open("1char.txt", O_RDONLY);
	if (fd1 == -1)
	{
		perror("shit aint openeing");
		return (1);
	}
	// while ((s = get_next_line(fd1)) != NULL)
	// {
	// 	printf("%s", s);
	// 	free(s);
	// }
	s = get_next_line(fd1);
	printf("%s", s);
	free(s);
	s = get_next_line(fd1);
	printf("%s", s);
	free(s);
	if (close(fd1) == -1)
	{
		perror ("it aiint closing");
		return (1);
	}
	return (0);
}