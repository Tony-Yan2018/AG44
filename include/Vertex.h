#ifndef VERTEX_H
#define VERTEX_H


class Vertex
{
    public:
        int id;
        int color;
        int * neighbours;

        Vertex(int Id);
        virtual ~Vertex();

    protected:

    private:
};

#endif // VERTEX_H
