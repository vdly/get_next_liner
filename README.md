*This project has been created as partof the 42 curriculum by JODEHII*

# get_next_line

### Description

Get Next Line is a function that allows you to read through file, one line at a time. In this project, it is imperative to master:

- ***Memory Management***
- ***Buffer Handling***
- ***Edge cases***

### Instructions

##### Main function to run get_next_line:

```
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

### Resources

* https://stackoverflow.com/questions/572547/what-does-static-mean-in-c
* https://www.codecademy.com/resources/docs/c/static-variables
* AI was also use to further understanding of project
