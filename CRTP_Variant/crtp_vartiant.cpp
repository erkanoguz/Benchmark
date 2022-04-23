#include <iostream>
#include <vector>
#include <variant>

template <typename T>
class AbstractBase
{
public:
    void initialize() noexcept {
        T& device = static_cast<T&>(*this);
        device.initialize();
    }

    void run() noexcept {
        T& device = static_cast<T&>(*this);
        device.run();
    }

    void finish() noexcept {
        T& device = static_cast<T&>(*this);
        device.finish();
    }
private:

};

template <typename T>
class Base : public AbstractBase<Base<T>>
{
    Base() = default;
     void initialize() noexcept {
        T& device = static_cast<T&>(*this);
        device.initialize();
    }

    void run() noexcept {
        T& device = static_cast<T&>(*this);
        device.run();
    }

    void finish() noexcept {
        T& device = static_cast<T&>(*this);
        device.finish();
    }

public:
    friend class AbstractBase<Base<T>>;
};

class Derived1 : public Base<Derived1>
{
public:
    Derived1() = default;

    void initialize() noexcept {}
    void run() noexcept {}
    void finish() noexcept{}
};

class Derived2 : public Base<Derived2>
{
public:
    Derived2() = default;
    void initialize() noexcept  {}
    void run() noexcept {}
    void finish() noexcept {}
};

class Derived3 : public Base<Derived3>
{
public:
    Derived3() = default;

    void initialize() noexcept {}
    void run() noexcept {}
    void finish() noexcept {}
};

class Manager
{
    using container= std::vector <std::variant<Derived1, Derived2, Derived3 >>;

public:
    Manager() = default;
    ~Manager() {}
    
    void add() noexcept {
        devices.emplace_back( Derived1{} );
        devices.emplace_back( Derived2{} );
        devices.emplace_back( Derived3{} );
    }

    void initialize() noexcept {
        for (auto & device : devices)
        {  
            std::visit([](auto & device)
            {
                device.initialize();
            }, device );
        }
    }

    void run() noexcept {
        for (auto & device : devices)
        {  
            std::visit([](auto & device)
            {
                device.run();
            }, device );
        }
    }

    void finish() noexcept {
        for (auto & device : devices)
        {  
            std::visit([](auto & device)
            {
                device.finish();
            }, device );
        }
    }

private:
     container devices;
};

int main() 
{
    Manager manager;
    manager.add();
    manager.initialize();
    manager.run();
    manager.finish();
}