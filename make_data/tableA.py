#!/usr/bin/env python
import random
import string
import sys
i=0
for num1 in range(0,10000):
        i=random.randint(1,1000000)
        k=str(i)
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
