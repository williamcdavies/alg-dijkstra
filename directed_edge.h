#ifndef DIRECTED_EDGE_H
#define DIRECTED_EDGE_H

struct directed_edge
{   public:
        unsigned int a;
        unsigned int b;
        unsigned int l;
        directed_edge() = default;
        directed_edge(unsigned int a, unsigned int b, unsigned int l) : a(a), b(b), l(l) {}
        directed_edge(const directed_edge& other) : a(other.a), b(other.b), l(other.l) {}
        directed_edge& operator =(const directed_edge& rhs)
        {   a = rhs.a;
            b = rhs.b;
            l = rhs.l;
            return *this;
        }
};

#endif // DIRECTED_EDGE_H