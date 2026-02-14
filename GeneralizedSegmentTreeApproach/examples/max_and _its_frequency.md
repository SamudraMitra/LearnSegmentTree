### Range max and its frequency and point update

- We are given an array. We need to suppport 2 typs of queries:

1. change value at a given index to another value
2. change compute for a given range l,r the maximum for this range and how many times the max appears in the range

### Approach:

- We need to store the max and it's frequency obviously
- How do we merge? .. the max for the parent will obviously be either max of left or right child,.. and the frequency will be that of the greater max. incase the max of left and right are equal, we add their frequencies.
- So, the Node will be:

```
struct Node{
    long long val;
    long long freq;
};
```

- The combine function will be:

```
  Node combine(Node a, Node b)
  {
  Node res;
  if(a.val > b.val)
  {
  res = a;
  }
  else if(a.val < b.val)
  {
  res = b;
  }
  else
  {
  res.val = a.val;
  res.freq = a.freq+b.freq;
  }
  return res;
  }
```
