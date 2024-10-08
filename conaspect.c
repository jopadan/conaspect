#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <sys/param.h>

#ifndef __MMX__
typedef int32_t __m64 __attribute__((__vector_size__(sizeof(int32_t) * 2), __may_alias__));
#else
#include <mmintrin.h>
#endif

typedef __m64 vec2i;

int gcd(int x, int y)
{
	return y == 0 ? MAX(x, -x) : gcd(y, x % y);
}


int main(int argc, char** argv)
{
	if(argc > 2)
	{
		vec2i res     = { atoi(argv[1])      , atoi(argv[2])       };
		vec2i ratio   = { gcd(res[0], res[1]), gcd(res[0], res[1]) }; 
		vec2i aspect  = { res[0] / ratio[0]  , res[1] / ratio[1]   };
		vec2i console = { (res[0] >> 3)      , (res[1] >> 4)       };

		if(argc > 3)
			console[1] *= strtof(argv[3], NULL);

		fprintf(stdout, "MODE: %dx%d %d:%d CONSOLE: %dx%d\n",
		                res[0], res[1],
				aspect[0], aspect[1],
				console[0], console[1]);

		exit(EXIT_SUCCESS);
	}

	fprintf(stderr, "Usage: %s <width> <height> [scale]...\nCalculate aspect ratio and kernel console parameters.\n\n  <width>  - integer screen width\n  <height> - integer screen height\n  [scale]  - optional floating point row multiplier\n\nExamples:\n%s 1024 768\n%s 1024 768 2.0\n\n", argv[0], argv[0], argv[0]);

	exit(EXIT_FAILURE);
}
