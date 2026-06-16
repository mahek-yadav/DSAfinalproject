# Smart Manufacturing Supply Dependency Analyzer

A Data Structures and Algorithms (DSA) based C++ project that analyzes supply chain dependencies in manufacturing industries. The system helps organizations manage supplier networks, identify critical dependencies, discover alternative suppliers, and perform efficient supplier searches using fundamental DSA concepts.

---

## Project Overview

Modern manufacturing industries depend on complex supply chains involving suppliers, manufacturers, distributors, and logistics providers. Any disruption in one part of the supply chain can affect the entire production process.

The Smart Manufacturing Supply Dependency Analyzer uses Linked Lists, Graphs, DFS, BFS, and Binary Search to model and analyze supply chain relationships, helping organizations improve supply chain visibility and resilience.

---

## Objectives

- Register and manage suppliers dynamically.
- Map supply chain dependencies using graphs.
- Identify critical dependency chains.
- Discover alternative suppliers during disruptions.
- Perform efficient supplier searches.
- Demonstrate practical applications of Data Structures and Algorithms.

---

## Data Structures & Algorithms Used

### 1. Linked List
Used for dynamic supplier registration.

**Operations:**
- Add Supplier
- Store Supplier Information
- Traverse Supplier Records

### 2. Graph
Used to represent the supply chain network.

**Nodes:**
- Suppliers
- Manufacturers
- Distributors

**Edges:**
- Supply dependencies
- Business relationships

### 3. Depth First Search (DFS)
Used for critical dependency analysis.

**Purpose:**
- Trace complete dependency chains.
- Identify suppliers critical to production continuity.

### 4. Breadth First Search (BFS)
Used for alternative supplier discovery.

**Purpose:**
- Explore neighboring suppliers.
- Find alternate supply paths during disruptions.

### 5. Binary Search
Used for fast supplier lookup.

**Purpose:**
- Efficient supplier retrieval.
- Reduced search time in sorted records.

---

## Features

- Supplier Registration using Linked List
- Supply Dependency Mapping using Graphs
- Critical Dependency Analysis using DFS
- Alternative Supplier Discovery using BFS
- Supplier Search using Binary Search
- Menu-Driven Console Interface
- Dynamic Supplier Management

---

## 📂 Project Structure

```text
Smart-Manufacturing-Supply-Dependency-Analyzer/
│
├── main.cpp
├── README.md

```

---

## How to Run

### Compile

```bash
g++ main.cpp -o analyzer
```

### Run

```bash
./analyzer
```

For Windows:

```bash
g++ main.cpp -o analyzer.exe
analyzer.exe
```

---

## Menu Options

```text
1. Register Supplier
2. Display Suppliers
3. Add Dependency
4. Display Network
5. Critical Dependency Analysis (DFS)
6. Alternative Supplier Discovery (BFS)
7. Search Supplier (Binary Search)
8. Exit
```

---

## Time Complexity Analysis

| Operation | Complexity |
|------------|------------|
| Add Supplier | O(n) |
| Display Suppliers | O(n) |
| Add Dependency | O(1) |
| DFS Traversal | O(V + E) |
| BFS Traversal | O(V + E) |
| Binary Search | O(log n) |

Where:

- V = Number of vertices (suppliers)
- E = Number of edges (dependencies)

---

## Real-World Applications

- Manufacturing Supply Chain Management
- Automotive Industry
- Electronics Manufacturing
- Aerospace Supply Networks
- Pharmaceutical Production
- Procurement and Vendor Management

---

## Academic Information

**Course:** Data Structures & Algorithms with C++

**Program:** B.Tech Computer Science Engineering

**Semester:** II

**Case Study:** Smart Manufacturing Supply Dependency Analyzer

---

## Future Enhancements

- Supplier Risk Assessment Module
- Alert Management System
- Procurement Analytics
- Supply Chain Dashboard
- Dependency Visualization
- Risk Prediction System
- Database Integration

---

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- Linked List
- Graph
- DFS
- BFS
- Binary Search
- STL (Vector, Queue)

---

## Conclusion

The Smart Manufacturing Supply Dependency Analyzer demonstrates how fundamental Data Structures and Algorithms can be applied to solve real-world supply chain management problems. By combining Linked Lists, Graphs, DFS, BFS, and Binary Search, the project provides an efficient framework for analyzing supplier dependencies and improving manufacturing resilience.
