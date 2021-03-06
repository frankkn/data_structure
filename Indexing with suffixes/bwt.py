# Burrows-Wheeler Transform

def rotations(t):
    # Return list of rotations of input string t
    tt = t * 2 # in order to make index reasonable
    return [ tt[i:i+len(t)] for i in range(len(t)) ]

def bwm(t):
    # Return lexicographically sorted list of t’s rotations (Burrows-Wheeler matrix)
    return sorted(rotations(t))

def bwtViaBwm(t):
    # Given T, returns BWT(T) by way of the BWM 
    # i.e., take the last column of bwm
    # map (function, iterable)
    # lambda parameter_list: expression
    return ''.join(map(lambda x: x[-1], bwm(t)))

def suffixArray(s):
    """ Given T return suffix array SA(T). """
    satups = sorted([(s[i:], i) for i in range(len(s))])
    # Extract and return just the offsets
    return map(lambda x: x[1], satups)

def bwtViaSa(t):
    # Given T, returns BWT(T) by way of the suffix array
    bw = []
    for si in suffixArray(t):
        if si == 0:
            bw.append('$')
        else:
            bw.append(t[si-1])
    return ''.join(bw) # return string-ized version of list bw

if __name__ == '__main__':
  print(rotations('cat'))

  print(bwm('abaaba$'))
  print('\n'.join(bwm('abaaba$')))

  print("BWT of \"abaaba\" is : " + bwtViaBwm('abaaba$')) # we can see the result equals the last column of the matrix above

  print(bwtViaBwm('abaaba$'), bwtViaSa('abaaba$')) # same result

  print("BWT of \"banana\" is : " + bwtViaSa("banana$"))

