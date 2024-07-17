/*
单例模式：保证一个类仅有一个实例，并提供一个访问它的全局访问点。首先，怎么让类只有一个实例呢？
肯定是构造函数需要做点“手脚”了，如果构造函数一如既往的是public属性，那还是可以任意构造对象，
则不满足要求了。所以大神们想出来将构造函数私有化的方法，即把构造函数设置成私有属性，并对外提
供一个访问的接口。

单例模式的实现有两种方式：懒汉模式和饿汉模式。懒汉模式：顾名思义，很“懒”，只有用到了才实例化
对象并返回（调用了对外的接口才会实例化对象）。饿汉模式：不管调不调用对外接口，都已经实例化对象了。

懒汉模式存在线程安全问题：由于没有了对象，所以将instance设置为static属性，让其能通过类名来访
问获取。但是在多线程环境下，这种实现方式是不安全的，原因在于在判断instance是否为空时，可能存
在多个线程同时进入if中，此时可能会实例化多个对象。于是，出现了二重锁的懒汉模式
*/

#include <iostream>
#include <mutex>
using namespace std;
// 懒汉模式
class lazy_single{
private:
    static lazy_single* Instance;
    lazy_single(){};
    lazy_single(const lazy_single & cp){};
public:
    static lazy_single* GetInstance()
    {
        if (Instance == nullptr)
            Instance = new lazy_single();
        return Instance;
    }
};
lazy_single* lazy_single::Instance = nullptr;

// 懒汉双重锁模式
class dl_lazy_single{
private:
    static dl_lazy_single* Instance;
    static mutex i_mutex;
    dl_lazy_single(){};
    dl_lazy_single(const dl_lazy_single & ) = delete;
    dl_lazy_single operator=(const dl_lazy_single&) = delete;
public:
    static dl_lazy_single* GetInstance()
    {
        if (Instance == nullptr)
        {
            i_mutex.lock();
            if (Instance == nullptr);
            Instance = new dl_lazy_single();
            i_mutex.unlock();
        }
        return Instance;
    }
};
dl_lazy_single* dl_lazy_single::Instance = nullptr;

// 饿汉模式
class eager_single{
private:
    static eager_single* Instance;
    eager_single();
public:
    static eager_single* GetInstance()
    {
        // 没有判断，直接返回
        return Instance;
    }
}
int main(){
    //懒汉模式
	lazy_single* singlep1= lazy_single::GetInstance();//通过类域获取接口
	lazy_single* singlep2 = lazy_single::GetInstance();
 
    cout << singlep1 << endl;
	cout << singlep2 << endl;
 
    system("pause");
    return 0;
}