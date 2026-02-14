### Counting the number of zeros, searching for the  k-th zero

- Here we have 3 types of queries

1. We need to support point updates
2. We need to count the number of zeroes in a given range
3. We need to find the position of the kth 0 for a given k

### Node structure:

```
struct Node{
    int zerocount;
};
```

### Combine function:

```
Node combine(Node left, Node right)
{
    Node res;
    res.zerocount = left.zerocount+right.zerocount;
    return res;
}
```

### Answering the 3rd query

- We can see that the 3rd query can be answered in this way:
  For a given index, if we can find the number of zeroes in its prefix, we can look for the smallet such index with k 0s in its prefix.. and this will be our answer for the 3rd query
- Finding the number of zeroes in a prefix is a type 2 query only,.. and using binary search we can find the desired index as the number of zeroes in a prefix is non decreasing function. So we can see monotonicity and apply binary searhc here
- Code for 3rd query( O((logn)^2) )

```
ll lo = 0;
ll hi = n-1;
ll ans = -1; // incase there are less than k 0s in the array currently
while(lo<=hi)
{
    ll mid = (lo+hi)/2;
    if(segtree.query(0,mid)>=k)
    {
        ans = mid;
        hi = mid-1;
    }
    else
    {
        lo = mid+1;
    }
}
cout<<ans<<"\n;
```
