//
// Created by misho on 2/19/2022.
//

#ifndef STL_VECTOR_CUSTOMVECTOR_H
#define STL_VECTOR_CUSTOMVECTOR_H


template <typename T>
class CustomVector{
public:
    CustomVector();
    CustomVector(int size);
    CustomVector (const CustomVector& x);
    ~CustomVector();
    T at(int IND);
    operator= (const CustomVector& v);
    void print();
    bool Empty();
    void Clear();
    bool valid_position(int pos);
    void Push_back(T x);
    void Pop_back();
    void Insert(int position, const T element);
    void Erase(int position);
    void Resize(int Size);
    int Find(T element);

private:
    T *v;
    int vsize;
};


#endif //STL_VECTOR_CUSTOMVECTOR_H
