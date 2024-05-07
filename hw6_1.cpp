#include <iostream>
#include <thread>
#include <mutex>

const int num_philosophers = 5;
std::mutex forks[num_philosophers];

void philosopher(int id) {
    int left_fork = id;
    int right_fork = (id + 1) % num_philosophers;

    while (true) {
        // Думают
        std::cout << "Philosopher " << id << " is thinking." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        // Берут вилку
        forks[left_fork].lock();
        forks[right_fork].lock();

        // Едят
        std::cout << "Philosopher " << id << " is eating." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        // Кладут вилку
        forks[left_fork].unlock();
        forks[right_fork].unlock();
    }
}

int main() {
    std::thread philosophers[num_philosophers];

    for (int i = 0; i < num_philosophers; ++i) {
        philosophers[i] = std::thread(philosopher, i);
    }

    for (int i = 0; i < num_philosophers; ++i) {
        philosophers[i].join();
    }

    return 0;
}
