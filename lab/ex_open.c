#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUF 1024


int	main(int argc, char **argv)
{
	char 	*file;
	char 	buf[1024];
	int 	fd;
	int 	flags;
	int 	bytes_reads;
	int 	bytes_writes;

	if (argc < 2)
	{
		perror("Arquivo de destino não definido.\n");
		return (1);
	}

	flags = O_WRONLY | O_CREAT | O_TRUNC;
	file = argv[1];

	fd = open(file, flags, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		perror("Erro ao abrir o arquivo!\n");
		return (1);
	}

	while ((bytes_reads = read(STDIN_FILENO, buf, MAX_BUF - 1)) > 0)
	{
		bytes_writes = write(fd, buf, bytes_reads);
		if (bytes_writes != bytes_reads)
		{
			perror("Error ao escrever no arquivo\n.");
			close(fd);
			return (1);
		}
	}	

	if (bytes_reads == -1)
	{
		perror("Erro na leitura do STDIN\n");
		close(fd);
		return (1);
	}	

	close(fd);
	return (0);
}
