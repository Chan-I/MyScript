#!/usr/bin/env python
import random
import string
import sys
for num1 in range(0,1000000):
        k=str(num1)
        sys.stdout.write(k)
        sys.stdout.write(',')
        for num2 in range(1,4):
                ran_str=''.join(random.sample(string.ascii_letters+string.digits, 8))
                sys.stdout.write(ran_str)
                sys.stdout.write(',')
        ran_str=''.join(random.sample(string.ascii_letters+string.digits, 8))
        sys.stdout.write(ran_str)
        sys.stdout.write('\n')
        sys.stdout.flush()
