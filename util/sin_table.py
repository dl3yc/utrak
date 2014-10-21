#!/usr/bin/env python
# Creates a sine table from 0 .. 90 Degrees and writes the corresponding C source file.
# The array is filled with scaled unsigned integer representations of a sine.

import math
import sys

if len(sys.argv) != 3:
	print "usage: " + sys.argv[0] + " array_length max_value"
	sys.exit()

n = int(sys.argv[1])
m = float(sys.argv[2])

f = open('sin_table.c', 'w')
f.write('/* sine table\n * generated by sin_table.py\n *\n * array_length: ' + str(n) + ', max_value: ' + str(m) + '\n */\n\n')
f.write('#include <inttypes.h>\n\n')
f.write('uint16_t sin_table['+str(n)+'] = {\n\t')

s_cnt = 0
for i in range(n):
	s_cnt = s_cnt + 1
	val = int(round(m * (( 0.5 * math.sin((float(i)/(float(n))) * 2 * math.pi/4) + 0.5))))
	f.write(str(val));
	if i != n-1:
		f.write(',')
		if s_cnt == 8:
			s_cnt = 0
			f.write('\n\t')
		else:
			f.write(' ')
f.write('\n}')
