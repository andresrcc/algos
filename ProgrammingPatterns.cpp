//singleton. Also, multithreaded
//adapter
//anything else? look at your course online (the one with the troll)

class Singleton{
private:
  static Singleton* instance;
  int data;
  Singleton(int value = 0){
    data = 0;
  }
public:
  static Singleton* get_instance(){
    if(!instance)
      instance = new Singleton;
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

int main(){
  int data = Singleton::get_instance()->get_value();
  Singleton::get_instance()->set_value(4);
}


//Try to have implemented in all programming languages C#, Python, C++

