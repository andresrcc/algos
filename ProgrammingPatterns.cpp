
//to make it Singleton thread safe for non fully c+11 compliant compilers 
#include<mutex>

class Singleton{
private:
  static Singleton* instance;
  int data;
  static once_flag flag;
	
  Singleton(int value = 0){
    data = value;
  }
	
public:
  static Singleton* get_instance(){
    if(instance == nullptr)
      call_once(flag, [] {instance = new Singleton();});
    return instance;
  }
  void set_value(int value){
    data = value;
  }
  void get_value(){
    return data;
  }
}

//allocating the pointer
Singleton* Singleton::instance = 0;

//usage
int main(){
  int data = Singleton::get_instance()->get_value();
  Singleton::get_instance()->set_value(4);
}

/// Adapter Pattern

// Desired interface (Target)
class Point
{
  public:
  //virtual means can be customized
    virtual void draw() = nullptr;
};


// Legacy component (Adaptee)
class LegacyPoint
{
	int x_;
	int y_;
  public:
    LegacyPoint(int x, int y) {
		x_ = x;
		y_ = y
    }
    void oldDraw() {
        //draws point;
    }   
}

// Adapter Pattern (wrapper) Multiple inheritance
// because inherits from class legacy and implements LegacyPoint interface
class PointAdapter: public Point, private LegacyPoint
{
  public:
  //call base constructor (LegacyPoint class)
    PointAdapter(int x, int y): LegacyPoint(x, y) {
         //add extra stuff needed at adapter,
		 //or just forward to legacy constructor
      }
    
    void draw() {
		//forwards execution to old LegacyPoint class
        oldDraw();
    }
};

//usage
int main()
{
  int x = 20, y = 50;
  //remember PointAdapter implements point
  //client thinks it's using a point. It's using a legacy point on the other side.
  //or could be a special implementation of point from the UI component of the system
  Point *r = new PointAdapter(x,y);
  
  //using an instance of the impementation of the interface, use draw method
  //notice draw is virtual in the interface, such that it is implemented by PointAdapter.
  r->draw();
}

//Adapter design pattern translates the interface for one class into a compatible but different interface.


