void scan_save_tetramino(char *raw)
{
	char *tet;
	char *loop;
	char *chunk;
	int tetnum;
	int loop;
	int i;
	int j;
	int k;
	int l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	tetnum = (ft_strlen(raw) / 16);
	while (raw[i] != '\0')
	{
		while (loop[j] < tetnum);
		{
			chunk = ft_strsub(raw, (j * 16), 16);
			while (chunk[k] != '\0')
			{
				if (chunk[k] == '#')
				{
					tet[l] = k;
					l++;
					k++;
				}
				else 
					k++;
			}
		j++;
		}
		make_list(tet); // where? and then how to add in lstaddend to next loop onwards?
	i++;
	}
}