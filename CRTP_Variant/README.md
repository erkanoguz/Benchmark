# Polymorphism and CRRP+Variant

---

`Runtime polymorphism` is resolved at runtime by using `vptr` and `vtable`. `vptr` is a pointer and it points `vtable` that contains virtual functions. 

It is also possible to implement `static polymorphism` in C++ and  resolving is performed at compile-time. `[CRTP](https://en.cppreference.com/w/cpp/language/crtp)` (Curiously Recurring Template Pattern) may be used to implement `compile-time polymorphism`. You can get more detail information from this [presentation](https://www.youtube.com/watch?v=jBnIMEb2GhA). 

The class template `std::variant` represents a type-safe [union](https://en.cppreference.com/w/cpp/language/union). It enables us to access all derived class from a container which can hold all derived class type. 

`[CRTP + std::variant](https://godbolt.org/z/6cq1KvfWv)` based implementation and `[runtime polymorphic](https://godbolt.org/z/ezhjbfcb9)` implementation has been compared in Quick C++ Benchmark. Check out the [result](https://quick-bench.com/q/TV1osSAcqmU9sgzMqknzXbOhTvc). 

### Resources

---

[1] : ****[C++ : Polymorphic inheritance without vtable](https://gist.github.com/olibre/3d0774df0f7a16e2da10fae2b2f26c4f)****