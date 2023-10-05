/**
 * _atoi - function that convert a string to an integer.
 * @s: string to convert
 *
 * Return: int
 */
int _atoi(char *s)
{
	unsigned int count = 0;
	unsigned int size = 0;
	unsigned int out = 0;
	unsigned int pn = 1;
	unsigned int m = 1;
	unsigned int i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			return (2);

		if ((*(s + count) >= '0') &&  (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}
	/** if interger is invalid */
	if (count == 0 || size == 0 || (size == 1 && *(s) == '-'))
		return (2);

	for (i = count - size; i < count; i++)
	{
		out = out + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (out * pn);
}
