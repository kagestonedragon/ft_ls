int 		get_integer_length(int n)
{
	int 	length;

	length = 1;
	while (n /= 10)
		length++;
	return (length);
}