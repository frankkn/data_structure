class SuffixTrie(object):
  def __init__(self, t):
    """ Make suffix trie from t"""
    t += "$" # special terminator symbol
    self.root = {}
    for i in range(len(t)): # for each suffix
      cur = self.root
      for c in t[i:]: # for each character in i'th suffix
        if c not in cur:
          cur[c] = {} # add outgoing edge if necessary
        cur = cur[c]

  def followPath(self, s):
    """ Follow path given by characters of s. Return node at the end of path, or Nonde if we fall off. """
    cur = self.root
    for c in s:
      if c not in cur:
        return None
      cur = cur[c]
    return cur

  def hasSubstring(self, s):
    """ Return true iff s appears as a substring of t. """
    return self.followPath(s) is not None

  def hasSuffix(self, s):
    """ Return true iff s is a suffix of t. """
    node = self.followPath(s)
    return node is not None and '$' in node

if __name__ == '__main__':
  strie = SuffixTrie('there would have been a time for such a word')
  print(strie.hasSubstring('nope')) # output: False
  print(strie.hasSubstring('would have been')) # output: True
  print(strie.hasSubstring('such a word')) # output: True
  print(strie.hasSuffix('would have been')) # output: False
  print(strie.hasSuffix('such a word')) # output: True