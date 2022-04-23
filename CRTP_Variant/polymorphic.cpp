#include <iostream>
#include <vector>
#include <memory>

class AbstractBase 
{
public:
    AbstractBase() = default;
    virtual ~AbstractBase() {}    

    virtual void initialize() noexcept = 0;
    virtual void run() noexcept = 0;
    virtual void finish() noexcept = 0;
};

class Base : public AbstractBase
{
public:
    Base(){}
    virtual ~Base(){}

    void initialize() noexcept override {}
    void run() noexcept override {}
    void finish() noexcept override {};
};

class Derived1 : public Base
{
public:
    Derived1() = default;
    virtual ~Derived1(){}

    void initialize() noexcept override {}
    void run() noexcept override{}
    void finish() noexcept override{}
};

class Derived2 : public Base
{
public:
    Derived2() = default;
    virtual ~Derived2(){}

    void initialize() noexcept override{}
    void run() noexcept override{}
    void finish() noexcept override{}
};

class Derived3 : public Base
{
public:
    Derived3() = default;
    ~Derived3(){}

    void initialize() noexcept override {}
    void run() noexcept override{}
    void finish() noexcept override{}
};

class Manager 
{
public:
    Manager() = default;
    ~Manager() {}

    void add() noexcept {
        devices.push_back(std::make_unique<Derived1>());
        devices.push_back(std::make_unique<Derived2>());
        devices.push_back(std::make_unique<Derived3>());
    }

    void initialize() noexcept {
        for(const auto& device : devices) {
            device->initialize();
        }
    }

    void run() noexcept {
        for(const auto& device : devices) {
            device->run();
        }    
    }

    void finish() noexcept {
        for(const auto& device : devices) {
            device->finish();
        }      
    }

private:
    std::vector<std::unique_ptr<AbstractBase>> devices;
};

int main() 
{
    Manager manager;
    manager.add();
    manager.initialize();
    manager.run();
    manager.finish();
}