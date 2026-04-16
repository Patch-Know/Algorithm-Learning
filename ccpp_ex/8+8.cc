struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

template<typename T> 
T max(T a,T b)
{
    return a>b? a : b; 
}

template<> box max(box a,box b)
{
    return a.volume>b.volume ? a : b;
}
