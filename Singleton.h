#pragma once

template <typename T>
concept has_singleton_friend = requires { T(); };

template <typename T>
class Singleton {
  public:
    Singleton(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;

    Singleton &operator=(const Singleton &) = delete;
    Singleton &operator=(Singleton &&) = delete;

    static T &get_instance()
        requires has_singleton_friend<T>
    {
        static T instance;
        return instance;
    }

  protected:
    Singleton() = default;
    virtual ~Singleton() = default;
};