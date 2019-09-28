int			ft_strchr_index(char *string, char character)
{
	int		i;

	i = -1;
	while (string[++i])
		if (string[i] == character)
			return (i);
	return (-1);
}