# Copyright 2013 Philip N. Klein
def dict2list(dct, keylist): return [dct[x] for x in keylist]

def list2dict(L, keylist): return { keylist[x]:L[x] for x in range(0,len(L)) }

def listrange2dict(L):
	"""
	Input: a list L

	Output: a dictionary that, for i = 0,1,2...,len(L)-1, maps i to L[i]

	"""

	return list2dict(L, list(range(0,len(L))))