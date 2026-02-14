## Introduction

- Now that we have implemented a trivial and a non-trivial segment tree on our own, in this module we will aim to develop a generalized approach for solving range query questions.

- To solve any range query question, we will need to answer these 3 questions,.. if we can have an answer to them, then we are sorted and can use the segment tree template directly. So what are these questions?

## What to store in each node of the segment tree?

- Obviously,.. the stuff we are asked about the range,.. we will need to store that,.. but as you saw while solving [gss3](https://www.spoj.com/problems/GSS3/), we also need to store other stuff in the nodes of the tree,.. what was the drive and intuition behind these you might ask?.. That is answered by our second question

## How do we merge the answer for the left tree and the right tree?

- This gives us the other values we need to store in the node of the tree.

## A value for the null nodes:

- As we know, a segment tree cannot have all nodes filled in all levels, if the size of the original array is not a power of 2. So, we need to know what to fill in the null nodes of the tree

### Let us walk through a previously done question:

- We had solved the gss3 question, but let's do it again this time with a proper intuition and driving force behind the decision of storing the 4 values in the tree nodes
