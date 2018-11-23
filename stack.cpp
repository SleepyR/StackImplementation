#include <iostream>
using namespace std;

template <class T>
class Stack
{
  protected:
  T* arr;
  int top;
  int max=100;
  public:
  Stack()
  {
    top=-1; arr=new T[max];
  }
  ~Stack() 
  { 
    delete []arr; 
  }
  void push(T x)
  {
    top++;
    if(top>max)
    {
      max=max*2;
      T* b =new T[max];
      for(int i=0;i<max/2;i++)
      {
        b[i]=arr[i];
      }
      arr=b;
    }
    arr[top]=x;
  } 

  T pop()
  {
    top--;
    return arr[top]; // optional , it can just decrease top, and return nothing
  } 

  bool isEmpty()
  {
    return top==-1;
  } 

  T get_top()
  {
    return arr[top];
  }
};


int main()
{
  Stack<int>* s=new Stack<int>();
  s->push(5); 
  s->push(15);
  s->push(25);
  cout<<s->isEmpty()<<endl;
  cout<<s->get_top()<<endl;
  s->pop();
  cout<<s->get_top()<<endl;
  s->pop();
  cout<<s->get_top()<<endl;
  s->pop();
  cout<<s->isEmpty()<<endl;
  return 0;
}
