#ifndef DIRECTED_EDGE_H
#define DIRECTED_EDGE_H

struct dedge
{   public:
        unsigned int a, b, d;
        dedge() = default;
        dedge(unsigned int a, unsigned int b, unsigned int d) : a(a), b(b), d(d) {}
        dedge(const dedge& other) : a(other.a), b(other.b), d(other.d) {}
        dedge& operator =(const dedge& rhs)
        {   a = rhs.a;
            b = rhs.b;
            d = rhs.d;
            return *this;
        }
};

#endif // DIRECTED_EDGE_H