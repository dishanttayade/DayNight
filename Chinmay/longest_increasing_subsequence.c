P = array of length N
M = array of length N + 1

L = 0
for i in range 0 to N-1:
    // Binary search for the largest positive j ≤ L
    // such that X[M[j]] < X[i]
    lo = 1
    hi = L + 1
    while lo < hi:
        mid = lo + floor((hi-lo)/2)
        if X[M[mid]] < X[i]:
            lo = mid+1
        else:
            hi = mid

    // After searching, lo is 1 greater than the
    // length of the longest prefix of X[i]
    newL = lo

    // The predecessor of X[i] is the last index of 
    // the subsequence of length newL-1
    P[i] = M[newL-1]
    M[newL] = i
    
    if newL > L:
        // If we found a subsequence longer than any we've
        // found yet, update L
        L = newL

// Reconstruct the longest increasing subsequence
S = array of length L
k = M[L]
for i in range L-1 to 0:
    S[i] = X[k]
    k = P[k]

return S