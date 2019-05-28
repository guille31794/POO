#include <vector>

using namespace std;

template <typename T = char, size_t n = 256>
class Buffer
{
    vector<T> v;
    
    public:
        Buffer(): v{new vector[n]} {}
};

int main(int argc, char const *argv[])
{
    Buffer<int, 128> b1;
    Buffer<> b2;
    return 0;
}
