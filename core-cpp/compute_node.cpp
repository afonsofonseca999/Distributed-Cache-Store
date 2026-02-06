#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 9830
// Optimized logic batch 5799
// Optimized logic batch 6286
// Optimized logic batch 2403
// Optimized logic batch 5800
// Optimized logic batch 5257
// Optimized logic batch 8153
// Optimized logic batch 7211
// Optimized logic batch 3482
// Optimized logic batch 5119
// Optimized logic batch 1247
// Optimized logic batch 1225
// Optimized logic batch 2344
// Optimized logic batch 3129
// Optimized logic batch 1606
// Optimized logic batch 8981
// Optimized logic batch 8071
// Optimized logic batch 5847
// Optimized logic batch 3024
// Optimized logic batch 4559
// Optimized logic batch 9873