isSafe(v, c):
    // Check whether color c can be assigned to vertex v
    for each vertex u adjacent to v:
        // Adjacent vertices must not have the same color
        if color[u] == c:
            return false       // Color c is not safe for v

    return true                // No adjacent vertex has color c


graphColoring(v):
    // Base case: all vertices have been successfully colored
    if v == n:
        return true

    // Try every available color for the current vertex
    for c = 1 to m:
        // Check whether assigning color c violates any constraint
        if isSafe(v, c):
            color[v] = c       // Assign color c to vertex v

            // Recursively try to color the next vertex
            if graphColoring(v + 1):
                return true    // A valid coloring has been found

            // Backtrack: undo the assignment and try another color
            color[v] = 0

    // No available color works for vertex v
    return falsek