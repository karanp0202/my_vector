template <typename typ>
class my_vector
{
private:
    typ *_data;
    unsigned long _size;
    unsigned long _capacity;
    my_vector& at_begin(typ);

public:
    my_vector();
    my_vector(unsigned long);

    void clear();
    void pop_back();
    void pop_begin();
    void fit_to_size();
    typ& operator[](unsigned long);
    void operator+=(unsigned long);
    void operator-=(unsigned long);
    my_vector& reverse();
    my_vector &part(unsigned long, unsigned long);
    my_vector &operator<<(typ);
    my_vector &operator<<(my_vector<typ>&);
    my_vector& operator>>=(int);
    my_vector& operator<<=(int);
    unsigned long& capacity();
    unsigned long& size();

    template <typename typ2>
    friend my_vector<typ2>& operator<<(typ2, my_vector<typ2>&);
};

template <typename typ>
my_vector<typ>::my_vector(){
    this->_data = new typ;
    this->_size = 0;
    this->_capacity = 1;
}

template <typename typ>
my_vector<typ>::my_vector(unsigned long count) : my_vector(){
    this->operator+=(count);
}

template <typename typ>
typ& my_vector<typ>::operator[](unsigned long pos){
    return this->_data[pos];
}

template <typename typ>
void my_vector<typ>::operator+=(unsigned long count){
    for (int i = 0; i < count; i++)
        this->operator<<(typ());
}

template <typename typ>
void my_vector<typ>::operator-=(unsigned long count){
    for (int i = 0; i < count; i++)
        this->pop_back();
}

template <typename typ>
my_vector<typ>& my_vector<typ>::operator<<=(int count){
    if(this->size() == 0)
        return *this;
    for (int i = 0; i < count; i++)
    {
        typ tmp = this->_data[0];
        for (int j = 0; j <this->size()-1; j++)
            this->_data[j] = this->_data[j + 1];
        this->_data[this->size() - 1] = tmp;
    }

    return *this;
}

template <typename typ>
my_vector<typ>& my_vector<typ>::operator>>=(int count){
    if(this->size() == 0)
        return *this;
    for (int i = 0; i < count; i++)
    {
        typ tmp = this->_data[this->size()-1];
        for (int j =this->size() - 1; j > 1; j--)
            this->_data[j] = this->_data[j - 1];
        this->_data[0] = tmp;
    }

    return *this;
}

template <typename typ>
my_vector<typ>& my_vector<typ>::operator<<(typ data){
    if(this->size() ==this->capacity()){
       this->capacity() *= 2;

        typ *tmp = this->_data;
        this->_data = new typ[this->capacity()];

        for (unsigned long i = 0; i <this->size(); i++)
            this->_data[i] = tmp[i];
        delete[] tmp;
    }
    
    this->_data[this->size()] = data;
    this->size()++;

    return *this;
}

template <typename typ>
my_vector<typ>& my_vector<typ>::operator<<(my_vector<typ>& vec){
    my_vector<typ> tmp;

    for (unsigned long i = 0; i < vec.size(); i++)
        tmp << vec[i];

    for (unsigned long i = 0; i < tmp.size(); i++)
        this->operator<<(tmp[i]);

    return *this;
}

template <typename typ>
my_vector<typ>& my_vector<typ>::at_begin(typ data){
    if(this->size() ==this->capacity())
       this->capacity() *= 2;

    typ *tmp = this->_data;
    this->_data = new typ[this->capacity()];

    for (unsigned long i = 0; i <this->size(); i++)
        this->_data[i+1] = tmp[i];
    delete[] tmp;

    this->_data[0] = data;
    this->size()++;

    return *this;
}

template <typename typ>
my_vector<typ>& my_vector<typ>::reverse(){
    typ *rev = new typ[this->capacity()];

    for (int i = 0; i <this->size(); i++)
        rev[i] = this->_data[this->size() - i - 1];

    delete[] this->_data;
    this->_data = rev;

    return *this;
}

template <typename typ>
my_vector<typ>& my_vector<typ>::part(unsigned long start, unsigned long end){
    my_vector<typ> *tmp = new my_vector<typ>;
    if(start > this->size()-1)
        return *tmp;
    for (unsigned long i = start; i <= end && i < this->size(); i++)
        *tmp << this->_data[i];

    return *tmp;
}

template <typename typ>
void my_vector<typ>::clear(){
    delete[] _data;
    _data = new typ;
    this->size() = 0;
    this->capacity() = 1;
}

template <typename typ>
void my_vector<typ>::pop_back(){
    if(this->size() == 0)
        return;
    
    this->size()--;
    if(this->size() != 0)this->fit_to_size();
}

template <typename typ>
void my_vector<typ>::pop_begin(){
    if(this->size() == 0)
        return;
    for (unsigned long i = 0; i < this->size() - 1; i++)
        this->_data[i] = this->_data[i + 1];

    this->size()--;
    if(this->size() != 0)this->fit_to_size();
}

template <typename typ>
void my_vector<typ>::fit_to_size(){
    if(this->capacity() > this->size()*2){
        this->capacity() /= 2;
        typ *tmp = new typ[this->capacity()];

        for (unsigned long i = 0; i < this->capacity(); i++){
            tmp[i] = this->_data[i];
        }
        delete[] this->_data;
        this->_data = tmp;
    }
}

template <typename typ>
unsigned long& my_vector<typ>::size(){
    return this->_size;
}

template <typename typ>
unsigned long& my_vector<typ>::capacity(){
    return this->_capacity;
}

template <typename typ2>
my_vector<typ2>& operator<< (typ2 data, my_vector<typ2>& vec){
    return vec.at_begin(data);
}