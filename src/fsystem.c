#include "../headers/shared.h"

int read_content(char *fpath, char **cont)
{
	FILE *fd;
	unsigned fsize;

	fd = fopen(fpath, "r");

	if(fd == NULL)
		return ERR_OPEN;

	//Получаем размер файла
	fseek(fd, 0, SEEK_END);
	fsize = ftell(fd);
	fseek(fd, 0, SEEK_SET);

	cont_len = fsize;
	*cont = malloc(sizeof(char) * fsize);
	fread(*cont, sizeof(char), fsize, fd);
	fclose(fd);
	return 0;
}

int write_content(char *fpath, char *cont)
{
	FILE *fd;
	fd = fopen(fpath, "w");

	if(fd == NULL)
		return ERR_OPEN;

	fwrite(cont, sizeof(char), strlen(cont), fd);
	fclose(fd);
	return 0;
}