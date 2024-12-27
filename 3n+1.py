def collatz_sequence(x):
    num_seq = [x]
    #print(x)
    if x < 1:
       return []
    while x > 1:
       if x % 2 == 0:
         x = x / 2
       else:
         x = 3 * x + 1
    # Added line
       num_seq.append(x)
    #print (num_seq)
    return num_seq

from sys import stdin

for line in stdin:

    [mini, maxi] = [int (i) for i in line.split()]

    maxCycle = 0
    for i in range(mini,maxi+1):
        maxCycle = max(maxCycle,len(collatz_sequence(i)))

    print (mini, maxi, maxCycle)
