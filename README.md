# 🌲 Learning Segment Tree

This repository contains my implementations and experiments with **Segment Trees**, progressing from basic structures to more generalized and reusable designs.

📖 [Reference material](https://cp-algorithms.com/data_structures/segment_tree.html)

---

## 📚 Project Structure

```
.
├─ SegmentTree.h
├─ GeneralizedSegmentTree.h
├─ basic_segment_tree/
│   ├─ input/
│   ├─ output/
│   ├─ judge.ps1
```

---

## 🚀 Part 1 — Basic Segment Tree

### Goals

- Implement a classic segment tree
- Support range queries and point updates
- Build a clean, reusable template
- Practice modular and maintainable design

### Tasks

- [ ] Implement `SegmentTree.h`
- [ ] Implement `GeneralizedSegmentTree.h`

---

## ▶️ How to Run Tests

### Step 1 — Navigate

```bash
cd basic_segment_tree
```

### Step 2 — Run judge script (PowerShell)

```powershell
.\judge.ps1
```

---

## ⚙️ What the judge does

- Compiles your C++ files
- Runs all test cases automatically
- Compares outputs with expected results
- Displays PASS / FAIL for each test

---

## 🛠 Requirements

- C++17 or later
- g++
- PowerShell (Windows)

Optional manual compile:

```bash
g++ -std=c++17 main.cpp
```
