#ifndef DIRECTED_EDGE_H
#define DIRECTED_EDGE_H

struct directed_edge
{   public:
        unsigned int p, q, d;
        directed_edge() = default;
        directed_edge(unsigned int p, unsigned int q, unsigned int d) : p(q), q(q), d(d) {}
        directed_edge(const directed_edge& other) : p(other.p), q(other.q), d(other.d) {}
        directed_edge& operator =(const directed_edge& rhs)
        {   p = rhs.p;
            q = rhs.q;
            d = rhs.d;
            return *this;
        }
};

#endif // DIRECTED_EDGE_H