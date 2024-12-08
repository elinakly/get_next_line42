#include "get_next_line_bonus.h"

int	main(void)
{
	char	*s;
	int		fd1;
	int		fd2;

	fd1 = open("1char.txt", O_RDONLY);
	fd2 = open("empty_file.txt", O_RDONLY);

	s = get_next_line(fd1);
	printf("%s", s);
	free(s);

	s = get_next_line(fd1);
	printf("%s", s);
	free(s);

	s = get_next_line(fd2);
	printf("%s", s);
	free(s);
	close(fd2);
	close(fd1);
	return (0);
}