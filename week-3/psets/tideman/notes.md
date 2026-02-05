# Tideman & Graph Theory

The implementation of Tideman voting system appears to require an understanding of graph theory.

## The problem at hand

The `lock_pairs()` function should create the `locked` graph,
adding all edges in decreasing order of victory strength---as done by `sort_pairs()` for the `pairs` array---so
long as the edge would not create a cycle.

In order to detect the cyclic graph a **cycle detection algorithm** should be implemented.

## Adjacency matrix

The `pairs` arrays represent directed variation of an adjacency matrix
with the candidates representing the nodes (or vertices)

* **Adjacency matrix:** A square matrix that represents a graph
* **Directed graph (Digraph):** A graph made up of a set of nodes
connected by directed edges (often called arcs)

In the `paris[]` graph: the set of vertices is represented by the `pair_count`
and as it is a `struct` type the verticies themselves are represented by
head (`pairs[].winner`) & tail (`pairs[].loser`)

## Cycle detection

A common implementation of a cycle detection algorithm is the **depth-first search** (DFS)

For digraphs, finding cycles is done by distributed message-based algorithms.
These algorithms rely on the idea that a message sent by a vertex in a cycle will come back to itself.

### Algorithm

The pseudo-code---from [Wikipedia](https://en.wikipedia.org/wiki/Cycle_(graph_theory)#Algorithm)---using
DFS to find a cycle is as follows:

    For every vertex v: visited(v) = finished(v) = false
    For every vertex v: DFS(v)

where

    DFS(v) =
        if finished(v): return
        if visited(v):
            "Cycle found"
            return
        visited(v) = true
        for every neighbour w: DFS(w)
        finished(v) = true

### Implementation

For `pairs[3]` that would create a lock, in decreasing order of victory strength:

    Pair 0: [0-1] Alice beats Bob
    Pair 1: [2-0] Charlie beats Alice
    Pair 2: [1-2] Bob beats Charlie

Locking `Pair 2` would create a cycle
which can be detected by traversing the graph from the tail (`Charlie`)
to every neighbour of it recursively to see if it appears again as head (in `Pair 0`)
where head & tail are `pairs[].winner` & `pairs[].loser` respectively.

Or it can be done by traversing backwards from the head (`Bob`) but that would be unconventional.
