#include <assert.h>
#include <stdio.h>
#include <math.h>

#define END (36000.0)
// QS DRs
long double series1[] = {
36.510254, 37.739562, 38.365079, 38.637311, 39.170384, 39.501006, 39.662938,
39.833846, 40.255752, 40.328943, 40.933243, 41.157442, 41.211145, 41.228979,
41.351358, 41.796638, 42.160382, 42.214631, 42.510143, 43.070664, 43.583659,
44.369137, 44.512721, 44.728749, 44.854787, 45.177707, 46.237215, 46.265118,
46.58655, 47.360211, 48.021923, 48.124353, 51.690667, 51.710857, 52.561983,
54.016317, 54.171573, 56.185903, 57.138399, 60.047792, 61.982603, 64.056988,
65.164125, 65.258305, 65.601548, 68.292868, 68.769434, 69.493605, 69.775006,
70.402518, 72.45192, 75.730529, 79.877823, 80.11299, 80.529691, 82.429194,
84.657224, 86.851432, 90.712605, 93.975184, 96.353075, 99.706684, 101.141091,
101.62696, 103.092741, 103.523732, 104.287254, 104.334906, 104.576109,
106.496646, 106.648468, 106.702727, 107.72336, 115.586888, 120.696353,
122.54649, 127.810423, 136.250888, 141.992309, 152.042405, 158.834142,
163.826769, 168.454978, 174.54547, 177.181624, 181.328461, 181.653364,
185.581022, 187.422864, 200.170433, 203.316413, 204.883637, 210.411072,
212.247479, 246.775512, 322.956047, 331.17364, 369.822964, 375.260412,
380.221346, 445.226695, 453.693388, 457.974405, 463.664797, 593.610861,
617.736286, 772.679389, 816.080472, 833.232277, 887.320373, 1257.8181,
1266.503171, 1524.251812, 1532.174158, 1551.012061, 1590.47937, 1715.713368,
1781.956105, 1922.114035, 1939.692742, 2012.371056, 2054.098519, 2261.579858,
2865.213544, 3069.225804, 3321.310137, 3891.428744, 4084.332501, 4402.315102,
5106.131582, 5446.954874, 5568.344117, 5671.15995, 6164.389778, 6662.561184,
6716.330609, 7555.430816, 7787.214391, 8030.477676, 8181.063836, 8697.435133,
9918.683201, 11530.226695, 11546.209905, 11834.055227, 11964.296253,
12054.183855, 13031.144663, 13983.472142, 17659.890993, 21808.653522,
22012.833548, 24156.911041, 24363.214077, 26235.921685, 26239.965445,
32622.800849, END
};

// ICB
long double series2[] = {
17.994204, 18.004315, 19.40409, 20.560611, 21.067809, 21.254569, 22.135241,
22.368192, 22.427883, 22.467139, 22.543117, 22.555297, 22.608603, 22.766646,
22.79467, 23.05492, 23.166092, 23.389737, 23.605885, 24.214014, 24.654485,
24.974999, 25.040041, 25.198349, 25.218211, 25.341631, 25.628353, 26.291062,
26.326475, 26.530024, 26.622632, 26.99182, 27.281145, 27.839154, 27.925368,
28.171855, 28.173861, 28.228639, 28.237175, 28.34185, 28.375563, 28.703802,
28.779754, 28.780031, 29.129766, 29.188855, 29.385941, 29.395112, 29.615159,
29.783843, 30.444933, 30.760727, 30.815957, 31.4383, 31.659019, 32.122362,
32.151289, 32.287965, 32.523457, 33.082368, 33.167278, 34.172544, 34.173226,
34.9891, 35.708705, 36.76036, 37.680719, 39.031263, 39.190798, 39.42348,
39.613923, 40.761225, 41.595259, 42.480471, 42.48219, 42.838329, 43.091081,
43.130761, 43.494301, 49.404541, 72.682223, 81.285606, 82.273814, 88.472282,
90.859393, 98.50777, 110.263717, 111.844894, 118.244038, 203.739768,
473.037868, 569.814699, 579.142859, 582.016615, 639.690507, 673.07157,
795.725917, 843.174624, 970.285112, 1387.089948, 1410.237694, 1822.463231,
2582.530643, 20959.641808, END
};


#if 0
// Test case -- expect total area to be 75.
#define END 10.000
long double series1[] = {
	0.00001,
	0.00002,
	0.00003,
	0.00004,
	0.00005,
	0.00006,
	0.00007,
	0.00008,
	0.00009,
	0.00010,
	END
};
long double series2[] = {
	5.00001,
	5.00002,
	5.00003,
	5.00004,
	5.00005,
	END
};
#endif
#if 0
// Test case -- expect total area to be 4.
#define END 4.000
long double series1[] = {
	0.0001,
	1.0,
	2.0,
	3.0,
	END
};
long double series2[] = {
	1.0,
	2.0,
	3.0,
	END
};
#endif

void sanity() {
	assert(series1[0] != END);
	for (unsigned int i = 0; series1[i] != END; i++) {
		assert(series1[i+1] > series1[i]);
	}
	assert(series2[0] != END);
	for (unsigned int i = 0; series2[i] != END; i++) {
		assert(series2[i+1] > series2[i]);
	}
}
void main() {
	unsigned int i1 = 0, i2 = 0;
	long double last1 = 0.0, last2 = 0.0;
	long double area = 0.0;
	long double log_area = 0.0;
	long double last_x = 0.0;
	sanity();
	// first rectangles special case
	if (series1[i1] < series2[i2]) {
		// measure area of series1 while it's alone
		last_x = series1[i1];
		while (series1[i1+1] < series2[i2]) {
			long double deltax = series1[i1+1] - last_x;
			long double deltax_log =
				logl(series1[i1+1]) - logl(last_x);
			area += deltax * (i1+1);
			log_area += deltax_log * (i1+1);
			printf("Initial corner from series1: (%Lf,%u); "
			       "area %Lf logarea %Lf\n", series1[i1+1], i1+1,
			       deltax * (i1+1), deltax_log * (i1+1));
			last_x = series1[i1+1];
			i1++;
		}
		// now get series2 onto the board
		long double deltax = series2[i2] - last_x;
		long double deltax_log = logl(series2[i2]) - logl(last_x);
		assert(i2 == 0);
		area += deltax * (i1+1);
		log_area += deltax_log * (i1+1);
		printf("Meeting series2 1stpt: (%Lf,%u); area %Lf logarea %Lf\n",
		       series2[i2], i2, deltax * (i1+1), deltax_log * (i1+1));
		last_x = series2[i2];
	} else {
		// measure area of series2 while it's alone
		last_x = series2[i2];
		while (series2[i2+1] < series1[i1]) {
			long double deltax = series2[i2+1] - last_x;
			long double deltax_log =
				logl(series2[i2+1]) - logl(last_x);
			area += deltax * (i2+1);
			log_area += deltax_log * (i2+1);
			printf("Initial corner from series2: (%Lf,%u); "
			       "area %Lf logarea %Lf\n", series2[i2+1], i2+1,
			       deltax * (i2+1), deltax_log * (i2+1));
			last_x = series2[i2+1];
			i2++;
		}
		// now get series1 onto the board
		long double deltax = series1[i1] - last_x;
		long double deltax_log = logl(series1[i1]) - logl(last_x);
		assert(i1 == 0);
		area += deltax * (i2+1);
		log_area += deltax_log * (i2+1);
		printf("Meeting series1 1stpt: (%Lf,%u); area %Lf logarea %Lf\n",
		       series1[i1], i1, deltax * (i2+1), deltax_log * (i2+1));
		last_x = series1[i1];
	}
	// general case
	while (series1[i1] != END && series2[i2] != END) {
		// find the closest next point to identify the corner of the rectangle
		if (series1[i1+1] < series2[i2+1]) {
			// Next corner is from series1. Opposite corner is
			// the last point from series2.
			// Compute width.
			long double deltax = series1[i1+1] - last_x;
			long double deltax_log = logl(series1[i1+1]) - logl(last_x);
			// Compute height.
			unsigned int height = i1 > i2 ? i1 - i2 : i2 - i1;
			// This would be for "step at end" interpolation
			// unsigned int height = i1+1 > i2 ? (i1+1) - i2 : i2 - (i1+1);
			area += deltax * height;
			log_area += deltax_log * height;
			printf("Next corner from series1: (%Lf,%u) x last (%Lf,%u); "
			       "area %Lf logarea %Lf\n", series1[i1+1], i1,
			       last_x, i2, deltax * height, deltax_log * height);
			// advance
			last_x = series1[i1+1];
			i1++;
		} else {
			// Next corner is from series2. Opposite corner is
			// the last point from series1.
			// Compute width.
			long double deltax = series2[i2+1] - last_x;
			long double deltax_log = logl(series2[i2+1]) - logl(last_x);
			// Compute height.
			unsigned int height = i2 > i1 ? i2 - i1 : i1 - i2;
			area += deltax * height;
			log_area += deltax_log * height;
			printf("Next corner from series2: (%Lf,%u) x last (%Lf,%u); "
			       "area %Lf logarea %Lf\n", series2[i2+1], i2,
			       last_x, i1, deltax * height, deltax_log * height);
			// advance
			last_x = series2[i2+1];
			i2++;
		}
	}
	// TODO: end condition
	if (series2[i2] == END) {
		// Need advance series1 to the end
	} else {
		// Need advance series2 to the end
	}
	printf("Done, series1 was %u long; series2 was %u long\n", i1, i2);
	printf("\033[01;32mTotal area %Lf; logarithmic area %Lf\033[00m\n", area, log_area);
}
