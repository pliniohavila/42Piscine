#include <stdio.h>
#include <stdlib.h>


char    *ft_strstr(char *str, char *to_find)
{
    int     flag;
    int     i;
    int     i_tmp;
    int     j;

    flag = 0;
    i = 0;
    while(str[i] != '\0')
    {
        j = 0;
        if (str[i] == to_find[j])
        {
            flag = 1;
            i_tmp = i;
            while ((to_find[j] != '\0') && (flag == 1))
            {
                if (str[i_tmp] != to_find[j])
                {
                    flag = 0;
                }
                j++;
                i_tmp++;
            }
            if (flag)
            {
                return (str + i);
            }
            flag = 0;
        }
        i++;
    }

    return NULL;
}

char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
    if (dest == NULL)
        return NULL;

    char    *dest_start;
    unsigned int     i;

    dest_start = dest;
    i = 0;
    while ((src[i] != '\0') && (i < n))
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return (dest_start);
}

int 	ft_strlen(char *str)
{
	int 	i;

	i = 0;
	while(*str++)
		i++;

	return (i);
}


char 	**ft_split(char *str, char *charset)
{
	int 	i;
	int 	count_words;
	char 	*start;
	int 	difference;
	char 	**spliteds;
	char 	*substr;

	count_words = 0;
	difference = 0;
	substr = NULL;
	start = str;
	while (*str)
	{
		if ((substr = ft_strstr(str, charset)) != NULL)
		{
			count_words++;
			difference = substr - str;
			str += difference;
		}
		str++;
	}

	difference = 0;
	substr = NULL;
	i = 0;
	str = start; 
	// sum one to include final null char
	spliteds = (char**)malloc(sizeof(char*) * (count_words + 1));

	while (*str)
	{
		substr = ft_strstr(str, charset);
		if (substr == NULL)
			substr = &str[ft_strlen(str) - 1]; 
	
		difference = substr - str; 
		spliteds[i] = (char*)malloc(sizeof(char) * (difference + 1));
		ft_strncpy(spliteds[i], str, difference + 1);
		spliteds[i][difference + 1] = '\0';
		i++;
		str += difference;
		
		str++;
		substr = NULL;
	}
		
	spliteds[i] = (char*)malloc(sizeof(char));
	spliteds[i] = NULL;
	
	return (spliteds);
}

int 	len_array(char **str)
{
	int 	i;

	i = 0;
	while(str[i] != NULL)
		i++;

	return (i);

}

int 	main(void)
{	
	char 	**splited;
	int 	len_splited;

	printf("ORIGINAL STRING: ");
	printf("the new, the old, the never\nSEPARATOR: [\', \']\n");
	splited = ft_split("the new, the old, the never", ", ");
	
	len_splited = len_array(splited);
	
	for (int i = 0; i < len_splited; i++)
		printf("%s ", splited[i]);

	printf("\n");	

	return (0);
}
