import numpy as np;

sizes = [100,1000,10000];

# sizes = [10,20,30]
def FindEmpties (sizes):
    bins = [[0 for _ in range(size)] for size in sizes]

    balls = [np.random.rand(size)*size for size in sizes]

    for i in range(len(sizes)):
        for j in balls[i]:
            bins[i][int(j)] += 1
        print ("No of Zeros:",bins[i].count(0),"\tNo of Ones:", bins[i].count(1),end=' ')
        print ( "\tMax in bucket:", max(bins[i]), "\tlogn/loglogn:", np.log(sizes[i])/np.log(np.log(sizes[i])) )
    return bins

def MinNtoFull (sizes):

    bins = [[0 for _ in range(size)] for size in sizes]

    counts = [0 for _ in range(len(sizes))]

    for i in range(len(sizes)):
        while (bins[i].count(0) > 0):
            bins[i][int(np.random.rand()*sizes[i])] += 1
            counts[i] += 1
        print (counts[i],"\tnLogn =",sizes[i]*np.log(sizes[i]))
    return counts
        
print(FindEmpties(sizes)[0])
# MinNtoFull(sizes)
