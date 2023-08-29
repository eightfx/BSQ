char	*skip_header(char *str);

int	is_valid_line(char *str)
{
	char	*new_str;
	int		log;
	int		count;

	new_str = skip_header(str);
	log = 0;
	count = 0;
	while (*new_str != '\0')
	{
		if (*new_str == '\n')
		{
			if (log == 0)
			{
				log = count + 1;
			}
			else if (log != count)
				return (0);
			count = 0;
		}
		count++;
		new_str++;
	}
	return (1);
}
