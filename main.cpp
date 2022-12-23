/*	2021 copyright by Charles Leung
	Program to convert CD mode 1 2352 raw dump to 2336 XA*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv) 
{
    char    buff[16];
    FILE    *in, *out;
    size_t  n;
	int count;
	int size;

	count=0;

	if (argc != 3)
	{
		printf("CD MODE 1 2352 raw dump to 2336 converter v0.9\n");
		printf("Usage: strcopy.exe infile outfile\n");
		return 1;
	}

    in = fopen(argv[1], "rb" );

	if (in == NULL)
	{
		printf("Input file not found!\n");
		return 2;
	}

	/* check file size*/
	fseek(in, 0L, SEEK_END);
	size = ftell(in);
	if (size % 2352 != 0)
	{
		printf("Input size is not in multiple of 2352!\n");
		return 3;
	}

	rewind(in);

    out= fopen(argv[2], "wb" );

    while ( (n=fread(buff,1,16,in)) != 0 ) {
        if (count % 147 != 0)
		fwrite(buff, 1, n, out);
		count++;
    }
    return 0;
}
