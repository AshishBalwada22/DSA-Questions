# DSA-Questions

A contest and concept bank in C++, organised by the idea each problem teaches rather than by problem number. When I get a problem wrong, it lands in the folder of the concept that beat me — so revision means opening that folder, not scrolling a submission history.

```
CP/
├── Graph_question/     DFS/BFS, DSU, topological sort, round-trip detection
├── STL_question/       sets, maps, ordering tricks
├── question_bank/      number theory, combinatorics, modular arithmetic
└── *.cpp               graph.cpp, tree.cpp, combinatorics, modulo arithmetic
Contest/                Codeforces rounds, filed by date
DSA-200/Array/          the array track
```

## Why it's organised this way

`Graph_question/` is the clearest example. Ten files, each one a distinct graph *technique* rather than a distinct problem:

- `connected_component_size.cpp`, `number_of_rooms.cpp` — traversal and counting
- `building_roads.cpp`, `creating_team.cpp` — union-find
- `round_trip.cpp`, `round_trip2.cpp` — cycle detection, directed and undirected
- `Easy_graph_queries.cpp`, `kwalk.cpp` — query-shaped graph problems
- `Color_tree.cpp`, `One_edge.cpp` — trees as a special case

The same split applies to `question_bank/`: `double_factorial.cpp`, `modulo_summation.cpp`, `reminder_minimization.cpp` are all modular-arithmetic problems written down as separate tricks.

## Running

```bash
g++ -std=c++17 -O2 CP/Graph_question/building_roads.cpp -o br && ./br < input.txt
```

Contest files expect stdin; the concept files carry their own explanation in a header comment.
