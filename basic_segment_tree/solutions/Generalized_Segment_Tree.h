#include <bits/stdc++.h>
using namespace std;
template <typename T>
class SegmentTree
{
private:
    vector<T> arr;
    vector<T> tree;
    long long n;
    T combine(T a, T b)
    {
        return a + b;
    }
    void update_tree(long long idx, T val, long long node, long long left, long long right)
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
    T sum_tree(long long L, long long R, long long node, long long left, long long right)
    {
        if ((left == L) && (right == R))
        {
            return tree[node];
        }
        long long mid = (left + right) / 2; // 0
        if ((max(L, left) <= min(mid, R)) && (max(mid + 1, L) <= min(R, right)))
        {
            T leftsum = sum_tree(max(L, left), min(mid, R), 2 * node + 1, left, mid);
            T rightsum = sum_tree(max(mid + 1, L), min(R, right), 2 * node + 2, mid + 1, right);
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
    SegmentTree(vector<T> v)
    {
        arr = v;
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }
    void update(long long idx, T val)
    {
        update_tree(idx, val, 0, 0, n - 1);
    }
    T query(long long L, long long R)
    {
        return sum_tree(L, R, 0, 0, n - 1);
    }
};