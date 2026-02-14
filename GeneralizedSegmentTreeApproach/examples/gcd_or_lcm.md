### Range gcd or range lcm queries

- we need to support point updates and gcd / lcm queries for a given range

### Node structure:

```
struct Node{
    int g;
    int l;
};
```

### Combine function:

```
Node combine(Node left, Node right)
{
    Node res;
    res.g = gcd(left.g,right.g);
    res.l = lcm(left.l,right.l);
    return res;
}
```
