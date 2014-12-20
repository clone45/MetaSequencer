#include "Arduino.h"
#include "GlobalTranspositionTables.h"


const int8_t TRANSPOSITION_TABLES[][16] = {
	// 0) None
	{ 	
		0,0,0,0, 
		0,0,0,0, 
		0,0,0,0, 
		0,0,0,0 
	},
	// 1) Subtle
	{ 
		0,0,0,0, 
		2,2,2,2, 
		0,0,0,0, 
		2,2,2,2 
	},
	// 2) Subtle+
	{ 
		0,0,0,0, 
		2,2,2,2, 
		0,0,0,0, 
		9,9,9,9 
	},
	// 3) Launch
	{ 
		0,0,0,0, 
		2,2,2,2, 
		36,36,36,36, 
		9,9,9,9 
	},
	// 4) Tadeoffs
	{ 
		24,0,24,0, 
		12,36,36,2, 
		29,10,29,10, 
		9,9,9,9 
	},
	// 5) Return Home
	{ 
		0,14,-6,14, 
		0,-3,-12,14, 
		0,-5,20,10, 
		0,12,7,24 
	},
	// 6) Octaves	 
	{   
		0,0,-12,-12, 
		12,12,0,0, 
		0,0,-12,-12, 
		12,12,0,0 
	}, 
	// 7) Down & Up	
	{   
		0,0,-3,-3, 
		-6,-6,-9,-9, 
		-12,-12,-4,-4, 
		7,7,10,10 
	},
	// 8) Fast Acention
	{  
		-11,-9,-7,-5, 
		-3,-1,1,3, 
		5,7,9,11, 
		13,15,17,19 
	},
	// 9) Movement
	{  
		0,0,0,0, 
		-7,-7,-7,-7, 
		4,4,4,4, 
		-10,-10,-10,-13 
	},
	// 10) Extremes
	{  
		0,0,-48,-48, 
		48,48,-36,-36, 
		36,36,-24,-24, 
		24,24,-12,-12 
	},
	// 11) Fairly Random
	{  
		0,30,-4,-19, 
		14,5,-11,24, 
		22,6,-6,-12, 
		24,14,-12,2 
	},
	// 12) Arp up
	{  
		0,2,4,2, 
		4,6,4,6, 
		8,6,8,9, 
		8,9,11,8 
	},
	// 13) Arp up down
	{  
		0,4,8,4, 
		8,12,8,12, 
		16,12,8,4, 
		8,4,0,-4 
	},
	// 14) Wider
	{  
		0,1,-1,2
		-2,3,-3,4, 
		-4,5,-5,6, 
		-6,7,-7,-8 
	},
	// 15) down slide
	{  
		9,8,7,6, 
		5,4,3,2, 
		1,0,-1,-2, 
		-3,-4,-5,-6
	},
	// 16) Baby steps
	{  
		0,1,2,1, 
		0,-1,-2,-1, 
		0,1,2,1,
		0,-1,-2,-1
	}	
			
};


/* notes

  0  1   2    3    4    5    6    7    8    9    10   11
  0, 69, 137, 206, 274, 343, 412, 480, 549, 617, 686, 754,

  12   13   14   15    16    17    18    19    20    21    22    23
  823, 892, 960, 1029, 1097, 1166, 1234, 1303, 1372, 1440, 1509, 1577,

  24    25    26    27    28    29    30    31    32    33    34    35
  1646, 1715, 1783, 1852, 1920, 1989, 2058, 2126, 2195, 2263, 2332, 2400,

  36    37    38    39    40    41    42    43    44    45    46    47
  2469, 2538, 2606, 2675, 2743, 2812, 2880, 2949, 3018, 3086, 3155, 3223,

  48    49    50    51    52    53    54    55    56    57    58    59
  3292, 3361, 3429, 3498, 3566, 3635, 3703, 3772, 3841, 3909, 3978, 4046

  */