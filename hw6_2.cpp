#include <iostream>
#include <vector>
#include <shared_mutex>
#include <thread>

template <typename T>
class ThreadSafeContainer {
public:
    void add(const T& item) {
        std::unique_lock<std::shared_mutex> lock(mutex);
        data.push_back(item);
    }

    void remove(const T& item) {
        std::unique_lock<std::shared_mutex> lock(mutex);
        data.erase(std::remove(data.begin(), data.end(), item), data.end());
    }

    bool contains(const T& item) {
        std::shared_lock<std::shared_mutex> lock(mutex);
        return std::find(data.begin(), data.end(), item) != data.end();
    }

private:
    std::vector<T> data;
    mutable std::shared_mutex mutex;
};

void writer(ThreadSafeContainer<int>& container, int value) {
    container.add(value);
}

void reader(ThreadSafeContainer<int>& container, int value) {
    if (container.contains(value)) {
        std::cout << "Value " << value << " found!" << std::endl;
    } else {
        std::cout << "Value " << value << " not found." << std::endl;
    }
}

int main() {
    ThreadSafeContainer<int> container;

    std::thread writer_thread1(writer, std::ref(container), 42);
    std::thread writer_thread2(writer, std::ref(container), 100);

    std::thread reader_thread1(reader, std::ref(container), 42);
    std::thread reader_thread2(reader, std::ref(container), 50);

    writer_thread1.join();
    writer_thread2.join();
    reader_thread1.join();
    reader_thread2.join();

    return 0;
}
