# 🧭 Campus Navigator

A data-structure-driven wayfinding tool for **Bahria University Islamabad Campus (BUIC)** — built twice, from the same design: once as a constraint-driven C++17 console application, once as a dependency-free web app.

**🔗 Live demo:** [https://campus-navigator-iota.vercel.app/](#)

---

## Why this project exists

Most DSA coursework stops at diagrams and pseudocode. This project takes seven classical data structures and puts each one to work solving an actual problem — finding a building, checking if a resource is busy, figuring out if two locations are even connected — using **real location data pulled directly from BUIC's own campus signboard**, not placeholder data.

---

## What it does

| Feature | Data Structure | Why that structure |
|---|---|---|
| Location catalog (19 real BUIC sites) | Array | O(1) indexed access; single source of truth every other structure references by index |
| Recent-visits log + Undo | Stack (LIFO) | Most-recent-first is exactly what a stack gives you for free |
| Catalog browsing (Next/Previous) | Array + index pointer | Simple bounded traversal |
| Busy-resource queue simulation | Queue (FCFS) | A waiting line is fair by arrival order — a stack would serve the most recent arrival first, which isn't how real queues work |
| Search by ID or by name | Two Binary Search Trees | A BST is single-key by nature, so two independent trees keep both search modes at O(log n) average case instead of one falling back to linear scan |
| Reachability between buildings | Graph (adjacency matrix) + BFS | BFS explores layer-by-layer, so the first time it reaches a target, that's provably the shortest hop path — not just *a* path |
| Sorting the catalog | Bubble, Selection, Insertion, Merge Sort | Implemented from scratch — alphabetical (A–Z / Z–A) and by distance (nearest-first / farthest-first) |

---

## Two implementations, one design

### 🖥️ C++ Console Application
- **C++17**, standard library only — `<iostream>`, `<fstream>`, `<string>`
- **No STL containers** — every structure (array, stack, queue, BST, graph) is hand-implemented on fixed-size arrays, by design, not oversight
- Modular architecture: one header/implementation pair per data structure

```
include/          src/
├── Location.h     ├── Location.cpp
├── VisitStack.h   ├── VisitStack.cpp
├── CatalogBrowser.h  ├── CatalogBrowser.cpp
├── ResourceQueue.h   ├── ResourceQueue.cpp
├── SearchBST.h    ├── SearchBST.cpp
├── CampusGraph.h  ├── CampusGraph.cpp
├── SortingAlgorithms.h ├── SortingAlgorithms.cpp
└── Menu.h         ├── Menu.cpp
                    └── main.cpp
```

**Build & run:**
```bash
make
./campus_navigator
```

### 🌐 Web Application
- Zero dependencies — vanilla **HTML5 / CSS3 / JavaScript (ES6+)**, no framework, no build step
- Same logic reimplemented client-side: BST search, BFS pathfinding, all four sorts — independently verified in Node.js to produce identical output to the C++ binary
- Interactive route visualizer: pick two buildings, watch BFS find and animate the actual shortest path on an SVG map of campus
- Deployed as a static site on **Vercel**, auto-redeploying on every push to `main`

---

## A design decision worth reading

The brief called for sorting by "distance or rating." I deliberately dropped the rating field — no official popularity rating exists for BUIC buildings, and I didn't want to sort real data against a number I'd have had to invent. Instead, both numeric sorts operate on **distance**, in opposite directions (Insertion Sort ascending, Merge Sort descending) — mirroring how the two alphabetical sorts already operate on name in opposite directions. Same requirement, honest data.

---

## Tech Stack

**Backend/Console:** C++17 · g++ (MinGW-w64) · GNU Make · VS Code
**Frontend:** Vercel
**Tooling:** Git · GitHub · Vercel

---

## Project Structure

```
dsa_project_full/
├── include/          # C++ headers (one per data structure)
├── src/               # C++ implementations + main.cpp
├── web_ui/             # Self-contained HTML/CSS/JS web app
├── sample_data.txt     # Real BUIC location + walkway dataset
├── Makefile
└── README.md
```

---

## Author

**Farah Kayani** — Computer Science, Bahria University Islamabad Campus
[https://www.linkedin.com/in/farahkayani/](#) · [https://github.com/farahkayani](#)