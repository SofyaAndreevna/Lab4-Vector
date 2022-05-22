#pragma once
#include <iostream>

template <class T>
class TVector
{
public:
    TVector();
    TVector(int c, T d);
    TVector(const TVector<T>& p);
    ~TVector();

    void SetLen(int l);
    int GetLen();
    void Resize(int newLen);

    TVector<T> operator+ (const TVector<T>& p);
    TVector<T> operator- (const TVector<T>& p);
    TVector<T> operator* (const TVector<T>& p);
    TVector<T> operator/ (const TVector<T>& p);
    TVector<T>& operator= (const TVector<T>& p);
    bool operator== (const TVector<T>& p);
    bool operator!= (const TVector<T>& p);

    T& operator [](int i);

    void BubbleSort();
    void InsertSort();
    void QuickSort(int left = 0, int right = 0);

    template <class T>
    friend std::ostream& operator << (std::ostream& B, TVector<T>& A);
    template <class T>
    friend std::istream& operator >> (std::istream& B, TVector<T>& A);

protected:
    T* data;
    int length;
};

template<class T>
inline TVector<T>::TVector()
{
    length = 0;
    data = nullptr;
}

template<class T>
inline TVector<T>::TVector(int c, T d)
{
    if (c > 0)
    {
        data = new T[c];
        length = c;
        for (int i = 0; i < length; i++)
            data[i] = d;
    }
    else throw "err";
}

template<class T>
inline TVector<T>::TVector(const TVector<T>& p)
{
    if (p.data == nullptr)
    {
        data = nullptr;
        length = 0;
    }
    else
    {
        length = p.length;
        data = new T[length];
        for (int i = 0; i < length; i++)
            data[i] = p.data[i];
    }
}

template<class T>
inline TVector<T>::~TVector()
{
    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
    }
    length = 0;
}

template<class T>
inline void TVector<T>::SetLen(int l)
{
    this->Resize(l);
}

template<class T>
inline int TVector<T>::GetLen()
{
    return length;
}

template<class T>
inline void TVector<T>::Resize(int newLen)
{
    if (newLen <= 0) throw "err";
    T* mas = new T[newLen];
    if (data != nullptr)
    {
        int index = 0;
        if (length > newLen) index = newLen;
        else index = length;
        for (int i = 0; i < index; i++)
            mas[i] = data[i];
        delete[] data;
    }
    data = mas;
    length = newLen;
}



template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& p)
{
    if (length == 0) throw "err";
    if (length != p.length) throw "err";
    TVector<T> A(length, 0);
    for (int i = 0; i < length; i++)
        A[i] = data[i] + p.data[i];
    return A;
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p)
{
    if (length == 0) throw "err";
    if (length != p.length) throw "err";
    TVector<T> A(length, 0);
    for (int i = 0; i < length; i++)
        A[i] = data[i] - p.data[i];
    return A;
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p)
{
    if (length == 0) throw "err";
    if (length != p.length) throw "err";
    TVector<T> A(length, 0);
    for (int i = 0; i < length; i++)
        A[i] = data[i] * p.data[i];
    return A;
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& p)
{
    if (length == 0) throw "err";
    if (length != p.length) throw "err";
    TVector<T> A(length, 0);
    for (int i = 0; i < length; i++)
        if (p.data[i] == 0) A[i] = 0;
        else A[i] = data[i] / p.data[i];
    return A;
}

template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& p)
{
    if (this == &p) return *this;
    if (data != nullptr) delete[] data;
    if (p.data == nullptr)
    {
        length = 0;
        data = nullptr;
    }
    else
    {
        length = p.length;
        data = new T[length];
        for (int i = 0; i < length; i++)
            data[i] = p.data[i];
    }
    return *this;
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& p)
{
    if (length != p.length) return false;
    for (int i = 0; i < length; i++)
        if (data[i] != p.data[i]) return false;
    return true;
}

template<class T>
inline bool TVector<T>::operator!=(const TVector<T>& p)
{
    if (length != p.length) return true;
    for (int i = 0; i < length; i++)
        if (data[i] != p.data[i]) return true;
    return false;
}

template<class T>
inline T& TVector<T>::operator[](int i)
{
    if (data == nullptr)
        throw "err";
    if (i < 0 || i >= length)
        throw "err";
    return data[i];
}

template<class T>
inline void TVector<T>::BubbleSort()
{
    for (int i = 0; i < length; i++)
        for (int j = i + 1; j < length; j++)
            if (data[j] < data[i])
            {
                int tmp = data[j];
                data[j] = data[i];
                data[i] = tmp;
            }
}

template<class T>
inline void TVector<T>::InsertSort()
{
    for (int i = 1; i < length; i++)
    {
        int k = i;
        while (k > 0 && data[k - 1] > data[k])
        {
            int tmp = data[k - 1];
            data[k - 1] = data[k];
            data[k] = tmp;
            k -= 1;
        }
    }
}

template<class T>
inline void TVector<T>::QuickSort(int left = 0, int right = 0)
{
    int i, j;
    if (right == 0)
    {
        left = 0;
        right = length - 1;
    }
    i = left;
    j = right;
    int middle = data[(left + right) / 2];
    int tmp;
    while (i <= j) {
        while (data[i] < middle) i++;
        while (data[j] > middle) j--;
        if (i <= j) {
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j) QuickSort(left, j);
    if (right > i) QuickSort(i, right);
}

template<class T>
inline std::ostream& operator<<(std::ostream& B, TVector<T>& A)
{
    for (int i = 0; i < A.GetLen(); i++)
        B << A[i] << "  ";
    return B;
}

template<class T>
inline std::istream& operator>>(std::istream& B, TVector<T>& A)
{
    std::cout << "¬ведите " << A.length << " значение вектора: \n";
    for (int i = 0; i < A.length; i++)
        B >> A[i];
    return B;
}
