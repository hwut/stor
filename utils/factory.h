#pragma one

#include <functional>
#include <string>
#include <map>
#include <memory>

template<typename T, typename K = std::string>
class Factory{
public:
    template<typename N>
    struct reg_h {
        reg_h(const K & k) {
            Factory::inst().map_.emplace(k, []() {return new N();});
        }

        template<typename... Args>
        reg_h(const K &k, Args && ...args) {
            Factory::inst().map_.emplace(k, [&] {return new N(std::forward<Args>(args)...);});
        }
    };

public:
    static T * Get(const K & k) {
        return inst().get(k);
    }

    static T * GetUnique(const K & k) {
        return inst().getUnique(k);
    }

    static T * GetShared(const K & k) {
        return inst().getShared(k);
    }

private:
    explicit Factory() {}

    Factory(const Factory &) = delete;
    Factory & operator=(const Factory &) = delete;
    Factory(Factory &&) = delete;

    static Factory & inst() {
        static Factory f;
        return f;
    }


    T * get(const K & k) {
        return map_.find(k) == map_.end() ? nullptr : map_[k]();
    }

    T * getUnique(const K & k) {
        return std::unique_ptr<T> (get(k));
    }

    T * getShared(const K & k) {
        return std::shared_ptr<T> (get(k));
    }


private:
    std::map<K, std::function<T *()>> map_;
};

#define REG_MODULE_VNAME(T) reg_module_##T##_
#define REG_MODULE(T, key, ...) Factory<T>::reg_h<T> REG_MODULE_VNAME(T) (key, ##__VA_ARGS__);
