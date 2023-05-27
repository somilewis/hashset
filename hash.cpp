#include <iostream>
#include<cstdlib>

#define ARRAY_SIZE 717

union b32
{
    int i;
    float f;

};
// assumes T is an object that is greater in size than an integer
template<typename T>
int hashcode(const T& obj)
{
    size_t size{sizeof(T) / sizeof(int)};//how many int we have in an object
    int* it{reinterpret_cast<int*>(&obj)};//it will return a pointer we ask for
    int code{0};
    for (size_t i = 0; i < size; i++)
    {
        code ^= *(it++);
        //++it;
    }
    return code;
    
}

int min(int l, int r)
{
    return l < r ? l : r;
}
int hashcode(const std::string& k)
{
    int code{0};
    for (size_t i =0; i < min(k.size(), 15); ++i)

    {
        code = code * 10 + k[i];
    }
    //code = k[0] *100 + k[1] * 10 + k[2];
    //for(char c : k) code ^= c;
    return code;
}
int hashcode(int k) { return k; }

int hashcode(long long k)
{
    return static_cast<int>( (k >> 32) ^ k);

}
int hashcode(float k)
{
    return *reinterpret_cast<int*>(&k);

}
int hashcode(double k)
{
    return hashcode(*reinterpret_cast<long long*>(&k)) % ARRAY_SIZE;

}
int compress(int hashcode)
{
    //return (hashcode & ~(1 << 31)) % ARRAY_SIZE;
    //return((hashcode < 0) ? -hashcode : hashcode) % ARRAY_SIZE;

    srand(hashcode);//Generates a random value.compression technique
    return rand() % ARRAY_SIZE;

}

int main(int argc, char const *argv[])
{
    //std::cout << compress(hashcode(8786867880000000ll)) << std::endl;
    //b32 b{25};
    // std::cout << hashcode("dog") << std::endl;
    // std::cout << hashcode("god") << std::endl;
    // std::cout << hashcode("odg") << std::endl;

    std::cout << compress(hashcode(20))<< std::endl;
    std::cout << compress(hashcode(40))<< std::endl;
    std::cout << compress(hashcode(60))<< std::endl;
    std::cout << compress(hashcode(80))<< std::endl;
    std::cout << std::endl;
    std::cout << compress(hashcode(20))<< std::endl;
    std::cout << compress(hashcode(40))<< std::endl;
    std::cout << compress(hashcode(60))<< std::endl;
    std::cout << compress(hashcode(80))<< std::endl;


    return 0;

}
