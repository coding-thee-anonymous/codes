#include <iostream>
using namespace std;

class Box
{
    private:
        float length;
        float width;
        float height;

    public:
        Box(float l, float w, float h)
        {
             length = l;
             width = w;
             height = h;
        }

        float volume()
        {
            return length * width * height;
        }
};