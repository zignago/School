void get_identity(string &my_id)
{
    my_id = "grzmc7";
}


template <typename T>
void MySwap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;

    return;
}


template <typename T>
MyVector<T>::~MyVector()
{
    delete[] m_data;
}


template <typename T>
MyVector<T>::MyVector()
{
    reserved_size = 0;
    data_size = 0;
}


template <typename T>
MyVector<T> & MyVector<T>::operator=(const MyVector<T> &source)
{
    this->~MyVector();

    reserved_size = source.reserved_size;
    data_size = source.data_size;

    if(source.m_data) //no point in copying if source is empty
    {
        m_data = new T [data_size];

        for(int i = 0; i < data_size; i++)
            m_data[i] = source.m_data[i];
    }

    return *this;
}


// Make sure this does a deep copy
template <typename T>
MyVector<T>::MyVector(const MyVector<T> &source)
{
    this->~MyVector();

    reserved_size = source.reserved_size;
    data_size = source.data_size;

    if(source.m_data) //no point in copying if source is empty
    {
        m_data = new T [data_size];

        for(int i = 0; i < data_size; i++)
            m_data[i] = source.m_data[i];
    }
}


template <typename T>
T & MyVector<T>::operator[](int i)
{
    //if going out of bounds of array
    if(i > data_size || i < 0)
        throw std::out_of_range("Index out of range");

    return m_data[i]; //returns reference to ith element
}


template <typename T>
T & MyVector<T>::at(int index)
{
    //checks if given index is out of bounds
    if(index > data_size || index < 0)
        throw std::out_of_range("Index out of range");

    return m_data[index]; //returns reference to indexed element
}


template <typename T>
T & MyVector<T>::front()
{
    return m_data[0];
}


template <typename T>
T & MyVector<T>::back()
{
    return m_data[data_size - 1];
}


template <typename T>
int MyVector<T>::capacity()
{
    return reserved_size;
}


template <typename T>
void MyVector<T>::reserve(int new_cap)
{
    //reserve should never be called with a new cap 
    //that is less than data size

    //if it is, the vector remains unchanged

    if(new_cap >= data_size)
    {
        //new_cap needs to be greater than 0
        if (new_cap == 0) { new_cap++; }

        //data allocation in temp variable
        T* newBlock = new T[new_cap];

        //copies existing data
        for(int i = 0; i < data_size; i++)
            newBlock[i] = m_data[i];

        //gets rid of existing data and replace
        //delete[] m_data;
        this->~MyVector();
        m_data = newBlock;

        reserved_size = new_cap;
    }

    return;
}


template <typename T>
void MyVector<T>::shrink_to_fit()
{
    //new size to shrink to
    const int new_size = 2 * data_size;

    //data allocation in temp variable
    T* newBlock = new T[new_size];

    //copies existing data up to data_size
    for(int i = 0; i < data_size; i++)
        newBlock[i] = m_data[i];

    //delete[] m_data;
    this->~MyVector();
    m_data = newBlock;

    reserved_size = new_size;

    return;
}


template <typename T>
void MyVector<T>::assign(int count, const T &value)
{
    //replaces array with new array of given size if
    //count is less than or greater than reserved size

    if(count != reserved_size)
    {   
        //if count is less than reserved size, 
        //deletes vector before reserve is called

        if(count < reserved_size)
        {
            //delete[] m_data;
            this->~MyVector();

            reserved_size = 0;
            data_size = 0;
        }
            reserve(count);

            data_size = count;
    }

    for(int i = 0; i < count; i++)
        m_data[i] = value;

    return;
}


template <typename T>
void MyVector<T>::clear()
{
    this->~MyVector();
    //delete[] m_data;

    data_size = 0;
    reserved_size = 0;
    m_data = nullptr;

    return;
}


template <typename T>
void MyVector<T>::push_back(const T &x)
{
    //Doubles vector capacity when full, as specified
    //reserved_size = 0 case handled within reserve function
    if (data_size >= reserved_size)
        reserve(2 * reserved_size);

    m_data[data_size] = x;
    data_size++;

    return;
}


template <typename T>
void MyVector<T>::pop_back()
{
    if(data_size > 0)
        erase(data_size - 1); //erases last element

    return;
}


template <typename T>
void MyVector<T>::insert(int i, const T &x)
{
    //pushes back last element, also increments data_size
    push_back(m_data[data_size-1]);

    //starts at previous index of last element, loops down to i
    for(int j = data_size - 2; j > i; j--)
    {
        //shifts up data from next lesser index
        m_data[j] = m_data[j-1];
    }

    //fills specified index, now empty, with x
    m_data[i] = x;

    return;
}


template <typename T>
void MyVector<T>::erase(int i)
{
    //makes sure i is within data range
    if(i > data_size || i < 0)
        throw std::out_of_range("Index out of range");

    //Removes the element at index i in the array
    for(int j = i; j < data_size - 1; j++)
        m_data[j] = m_data[j + 1];

    if(data_size) //if the size of the list is greater than 0
        data_size--;

    if( (reserved_size / 4) > data_size ) 
        shrink_to_fit();
    
    return;
}


template <typename T>
int MyVector<T>::size()
{
    return data_size;
}

