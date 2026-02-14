// Sarthak stalk krna buri baat hoti hai
#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
private:
    vector<long long> arr;
    vector<long long> tree;
    long long n;
    long long combine(long long a, long long b)
    {
        return a + b;
    }
    void update_tree(long long idx, long long val, long long node, long long left, long long right)
    {
        if (left == right)
        {
            tree[node] = val;
            return;
        }
        long long mid = (left + right) / 2;
        if ((left <= idx) && (idx <= mid))
        {
            update_tree(idx, val, 2 * node + 1, left, mid);
        }
        else if (((mid + 1) <= idx) && (idx <= right))
        {
            update_tree(idx, val, 2 * node + 2, mid + 1, right);
        }
        tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
    }
    long long sum_tree(long long L, long long R, long long node, long long left, long long right)
    {
        if ((left == L) && (right == R))
        {
            return tree[node];
        }
        long long mid = (left + right) / 2; // 0
        if ((max(L, left) <= min(mid, R)) && (max(mid + 1, L) <= min(R, right)))
        {
            long long leftsum = sum_tree(max(L, left), min(mid, R), 2 * node + 1, left, mid);
            long long rightsum = sum_tree(max(mid + 1, L), min(R, right), 2 * node + 2, mid + 1, right);
            return combine(leftsum, rightsum);
        }
        else if (max(L, left) <= min(mid, R))
        {
            return sum_tree(max(L, left), min(mid, R), 2 * node + 1, left, mid);
        }
        else
        {
            return sum_tree(max(mid + 1, L), min(R, right), 2 * node + 2, mid + 1, right);
        }
    }
    void build(long long node, long long left, long long right)
    {
        if (left == right)
        {
            tree[node] = arr[left];
            return;
        }
        long long mid = (left + right) / 2;
        build(2 * node + 1, left, mid);
        build(2 * node + 2, mid + 1, right);
        tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
    }

public:
    SegmentTree(vector<long long> v)
    {
        long long nv = 0;
        arr = v;
        n = arr.size();
        tree.resize(4 * n, nv);
        build(0, 0, n - 1);
    }
    void update(long long idx, long long val)
    {
        update_tree(idx, val, 0, 0, n - 1);
    }
    long long query(long long L, long long R)
    {
        return sum_tree(L, R, 0, 0, n - 1);
    }
};
