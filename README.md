Binary-Search-Tree-Implementation


This project implements a classic Binary Search Tree (BST) in modern C++ (C++11). The BST supports insertion, deletion, searching, and various tree traversal methods (in-order, pre-order, and post-order). It also demonstrates recursive algorithms, memory management, and pointer handling.

 What It Does
- Insert, delete, and search for integer values in a Binary Search Tree.
- Perform **in-order**, **pre-order**, and **post-order** traversals.
- Compute the **minimum** and **maximum** values in the BST.
- Handle deletion cases: leaf nodes, nodes with one child, and nodes with two children.
- Uses recursive logic for traversal and node deletion.

Algorithms & Features
Core Algorithms
- **Insertion** — Recursively inserts elements in correct sorted position.
- **Deletion** — Handles:
  - Leaf nodes
  - Nodes with one child
  - Nodes with two children (using in-order successor)
- **Search** — Recursively determines if a value exists in the tree.
- **Traversals**:
  - In-order
  - Pre-order
  - Post-order

Implementation Details
- Modern C++11 features (e.g., in-class member initialization).
- Recursive destructors for automatic memory cleanup.
- Pointer-based tree management.

How It Works
- Input: Series of integer values entered via standard input.
  - First, input values to **insert** into the tree (end with `-1`).
  - Then, input values to **remove** from the tree (end with `-1`).

- Output:
  - After each deletion, tree is printed using all three traversal methods.
