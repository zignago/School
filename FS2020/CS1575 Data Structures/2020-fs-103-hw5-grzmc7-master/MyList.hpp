//MyList.hpp

void get_identity(string &my_id)
{
    my_id = "grzmc7";
}


// Here is where you will initialize your list (of size 0) with a
//  sentinel node
template <typename T>
MyList<T>::MyList()
{
   m_size = 0;
   m_sentinel = new Node<T>(nullptr, nullptr);
}


template <typename T>
MyList<T>::MyList(const MyList<T> &source)
{
   //size gets incremented every push_back()
   //gets overridden at end of function

   m_size = 0;
   m_sentinel = source.m_sentinel;

   if(source.m_size)
   {
      Node<T> *p = m_sentinel;

      while(p != m_sentinel)
      {
         push_back(p->m_element);
         p = p->m_next;
      }

      //ensures size is correct
      m_size = source.m_size;
   }
}


// Use the removeall function from the sample lecture code as your guide
template <typename T>
MyList<T>::~MyList()
{
   Node<T> *head = m_sentinel;
   Node<T> *curr;

   if(m_size)
   {
      head = head->m_next;
      do
      {
         curr = head;
         head = head->m_next;
         delete curr;

      } while (head != m_sentinel);

      m_size = 0;
   }
}


template <typename T>
MyList<T> & MyList<T>::operator=(const MyList<T> &source)
{
   this->~MyList();

   m_size = 0;
   m_sentinel = source.m_sentinel;

   //copies all nodes
   if(source.m_size)
   {
      Node<T> *p = m_sentinel;
      p = p->m_next;

      while(p != m_sentinel)
      {
         push_back(p->m_element);
         p = p->m_next;
      }

      m_size = source.m_size;
   }

   return *this;
}


//returns data in first node
template <typename T>
T & MyList<T>::front()
{
   return m_sentinel->m_next->m_element;
}

//returns data in last node
template <typename T>
T & MyList<T>::back()
{
   return m_sentinel->m_prev->m_element;
}


// Assigns new contents (#count elements, each initialized to a copy of
//  value) to the list and replace its current contents
//  (size should be modified accordingly)
template <typename T>
void MyList<T>::assign(int count, const T &value)
{
   //deletes all nodes, sets size to 0
   clear();

   //appensds each consecutive value to the back of the list
   //because all the elements are the same, there are 
   //multiple ways to do this
   for(int i = 0; i < count; i++)
      push_back(value);

   return;
}


// Default list size of 0, with one sentinel node as in the
//  default constructor
template <typename T>
void MyList<T>::clear()
{
   int s = m_size;

   for(int i = 0; i < s; i++)
      pop_front();

   //default sentinel node
   m_sentinel = new Node<T>(nullptr, nullptr);

   return;
}


template <typename T>
void MyList<T>::push_front(const T &x)
{
   if(!m_size) //empty list
   {
      //temp and sentinel linked together
      Node<T> *temp;
      temp = new Node<T>(x, m_sentinel, m_sentinel);
      m_sentinel->m_prev = temp;
      m_sentinel->m_next = temp;
   }
   else
   {
      Node<T> *temp, *p = m_sentinel;
      p = p->m_next;

      //creating node
      temp = new Node<T>(x, m_sentinel, p);

      //linking neighboring nodes to temp
      p->m_prev = temp;
      m_sentinel->m_next = temp;
   }

   m_size++;

   return;
}


template <typename T>
void MyList<T>::push_back(const T &x)
{
   if(!m_size) //empty list
   {
      //temp and sentinel linked together
      Node<T> *temp;
      temp = new Node<T>(x, m_sentinel, m_sentinel);
      m_sentinel->m_prev = temp;
      m_sentinel->m_next = temp;
   }
   else
   {
      Node<T> *temp, *p = m_sentinel;
      p = p->m_prev;

      //creating node
      temp = new Node<T>(x,p,m_sentinel);

      //linking neighboring nodes to temp
      p->m_next = temp;
      m_sentinel->m_prev = temp;
   }

   m_size++;

   return;
}


template <typename T>
void MyList<T>::pop_back()
{
   if(m_size)
   {
      //temp is the node to be deleted, p is the node before it
      Node<T> *temp = m_sentinel, *p;

      temp = temp->m_prev;
      p = temp->m_prev;

      //linking the nodes that were linked to temp
      p->m_next = m_sentinel;
      m_sentinel->m_prev = p;

      delete(temp);
      m_size--;
   }

   return;
}


template <typename T>
void MyList<T>::pop_front()
{
   if(m_size)
   {
      //temp is the node to be deleted, p is the node after it
      Node<T> *temp = m_sentinel, *p;

      temp = temp->m_next;
      p = temp->m_next;

      //linking the nodes that were linked to temp
      p->m_prev = m_sentinel;
      m_sentinel->m_next = p;

      delete(temp);
      m_size--;
   }


   return;
}


template <typename T>
void MyList<T>::insert(int i, const T &x)
{
   if(m_size) //populated list
   {
      Node<T> *p, *n = m_sentinel;

      n = n->m_next;

      //finds node at index
      for(int pos = 0; pos < i; pos++)
         n = n->m_next;

      p = n->m_prev;

      Node<T> *temp = new Node<T>(x, p, n);

      p->m_next = temp;
      n->m_prev = temp;
   }


   else //empty list
   {
      Node<T> *temp = new Node<T>(x, m_sentinel, m_sentinel);

      m_sentinel->m_next = temp;
      m_sentinel->m_prev = temp;
   }

   m_size++;

   return;
}


// Removes all elements in list that are equal to value
template <typename T>
void MyList<T>::remove(T value)
{
   if(m_size) //not an empty list
   {
      Node<T> *n = m_sentinel; //current node
      int i = 0; //index of current node

      n = n->m_next;

      while(n != m_sentinel)
      {
         if(n->m_element == value)
            erase(i);

         n = n->m_next;
         i++;
      }
   }
   
   return;
}


// Removes element at position i
template <typename T>
void MyList<T>::erase(int i)
{
   if(m_size >= i)
   {
      Node<T> *p, *n, *temp = m_sentinel;

      temp = temp->m_next;

      //finds node at index
      for(int pos = 0; pos < i; pos++)
         temp = temp->m_next;

      //neighboring nodes
      p = temp->m_prev;
      n = temp->m_next;

      delete(temp);
      m_size--;

      //connecting neighboring nodes
      p->m_next = n;
      n->m_prev = p;
   }

   /*Note: For a std::list, attempting to alter a non-existant or out of 
   bounds index causes "undefined behavior" (often crashes the program, 
   never throws error). Because such behavior cannot be replicated, I 
   will not be adding any exception handling for invalid inputs (invalid 
   inputs will cause the function to not execute code).*/

   return;
}


// Reverses the order of the elements in the list
template <typename T>
void MyList<T>::reverse()
{
   if(m_size)
   {
      // Initialize current, previous and
      // next pointers
      Node<T> *temp = m_sentinel->m_next;
      Node<T> *p = m_sentinel, *n = m_sentinel;
 
      while (temp != m_sentinel)
      {
         // Store next
         n = temp->m_next;
 
         // Reverse current node's pointer
         temp->m_next = p;
 
         // Move pointers one position ahead.
         p = temp;
         temp = n;
      }

      m_sentinel->m_next = p;
   }

   return;
}


template <typename T>
bool MyList<T>::empty()
{
   bool isEmpty = 0;

   if(m_size == 0)
      isEmpty = 1;

   return isEmpty;
}


template <typename T>
int MyList<T>::size()
{
   return m_size;
}

/*
//optional function that prints out the list
//in a more visually appealing manner
template <typename T>
void MyList<T>::print()
{
   cout << endl << "Size: " << m_size;

   Node<T> *n = m_sentinel;

   n = n->m_next;

   cout << endl;

   do
   {
      cout << n->m_element << " -- ";
      n = n->m_next;

   } while (n != m_sentinel);
   
   cout << endl;

   return;
}
*/
