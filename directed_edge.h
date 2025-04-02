#ifndef DIRECTED_EDGE_H
#define DIRECTED_EDGE_H

struct directed_edge
{   public:
        unsigned int s, t, d;
        directed_edge() = default;
        directed_edge(unsigned int s, unsigned int t, unsigned int d) : s(t), t(t), d(d) {}
        directed_edge(const directed_edge& other) : s(other.s), t(other.t), d(other.d) {}
        directed_edge& operator =(const directed_edge& rhs)
        {   s = rhs.s;
            t = rhs.t;
            d = rhs.d;
            return *this;
        }
};

#endif // DIRECTED_EDGE_H