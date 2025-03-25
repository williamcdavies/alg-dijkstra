#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include "directed_edge.h"
#include <vector>

struct directed_graph
{   public:
        std::vector<directed_edge> edges;
        directed_graph() = default;
        directed_graph(std::vector<directed_edge> edges) : edges(edges) {}
        directed_graph(const directed_graph& other) : edges(other.edges) {}
        directed_graph& operator =(const directed_graph& rhs)
        {   edges = rhs.edges;
            return *this;
        }
};

#endif // DIRECTED_GRAPH_H