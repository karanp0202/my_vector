template <typename typ>
class my_vector
{
private:
    typ *_data;
    unsigned long _size;
    unsigned long _capacity;

public:
    my_vector();
    my_vector(unsigned long);

    void pop_back();
    void pop_begin();
    void fit_to_size();
    typ& operator[](unsigned long);
    void operator+=(unsigned long);
    void operator-=(unsigned long);
    unsigned long& size();
    my_vector& reverse();
    my_vector &part(unsigned long, unsigned long);
    my_vector &operator>(typ);
    my_vector& operator<(typ);
    my_vector& operator>>(int);
    my_vector& operator<<(int);
    unsigned long& capacity();
};

template <typename typ>
my_vector<typ>::my_vector(){
    _data = new typ;
    _size = 0;
    _capacity = 1;
}

template <typename typ>
my_vector<typ>::my_vector(unsigned long count) : my_vector(){
    operator+=(count);
}

template <typename typ>
typ& my_vector<typ>::operator[](unsigned long pos){
    return _data[pos];
}

template <typename typ>
void my_vector<typ>::operator+=(unsigned long count){
    for (int i = 0; i < count; i++)
        operator>(typ());
}

template <typename typ>
void my_vector<typ>::operator-=(unsigned long count){
    for (int i = 0; i < count; i++)
        pop_back();
}

template <typename typ>
my_vector<typ>& my_vector<typ>::operator<<(int count){
    if(size() == 0)
        return *this;
    for (int i = 0; i < count; i++)
    {
        typ tmp = _data[0];
        for (int j = 0; j < size()-1; j++)
            _data[j] = _data[j + 1];
        _data[size() - 1] = tmp;
    }

    return *this;
}

template <typename typ>
my_vector<typ>& my_vector<typ>::operator>>(int count){
    if(size() == 0)
        return *this;
    for (int i = 0; i < count; i++)
    {
        typ tmp = _data[size()-1];
        for (int j = size() - 1; j > 1; j--)
            _data[j] = _data[j - 1];
        _data[0] = tmp;
    }

    return *this;
}

template <typename typ>
my_vector<typ>& my_vector<typ>::operator>(typ data){
    if(size() == capacity()){
        capacity() *= 2;

        typ *tmp = _data;
        _data = new typ[capacity()];

        for (unsigned long i = 0; i < size(); i++)
            _data[i] = tmp[i];
        delete[] tmp;
    }
    
    _data[size()] = data;
    size()++;

    return *this;
}

template <typename typ>
my_vector<typ>& my_vector<typ>::operator<(typ data){
    if(size() == capacity())
        capacity() *= 2;

    typ *tmp = _data;
    _data = new typ[capacity()];

    for (unsigned long i = 0; i < size(); i++)
        _data[i+1] = tmp[i];
    delete[] tmp;

    _data[0] = data;
    size()++;

    return *this;
}

template <typename typ>
my_vector<typ>& my_vector<typ>::reverse(){
    typ *rev = new typ[capacity()];

    for (int i = 0; i < size(); i++)
        rev[i] = _data[size() - i - 1];

    delete[] _data;
    _data = rev;

    return *this;
}

template <typename typ>
my_vector<typ>& my_vector<typ>::part(unsigned long start, unsigned long end){
    my_vector<typ> *tmp = new my_vector<typ>;
    if(start > size()-1)
        return *tmp;
    for (unsigned long i = start; i <= end && i < size(); i++)
        *tmp > _data[i];

    return *tmp;
}

template <typename typ>
void my_vector<typ>::pop_back(){
    if(size() == 0)
        return;
    
    size()--;
    if(size() != 0)fit_to_size();
}

template <typename typ>
void my_vector<typ>::pop_begin(){
    if(size() == 0)
        return;
    for (unsigned long i = 0; i < size() - 1; i++)
        _data[i] = _data[i + 1];

    size()--;
    if(size() != 0)fit_to_size();
}

template <typename typ>
void my_vector<typ>::fit_to_size(){
    if(capacity() > size()*2){
        capacity() /= 2;
        typ *tmp = new typ[capacity()];

        for (unsigned long i = 0; i < capacity(); i++){
            tmp[i] = _data[i];
        }
        delete[] _data;
        _data = tmp;
    }
}

template <typename typ>
unsigned long& my_vector<typ>::size(){
    return _size;
}

template <typename typ>
unsigned long& my_vector<typ>::capacity(){
    return _capacity;
}