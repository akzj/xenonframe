#include "xutil/xworker_pool.hpp"


uint64_t count_ = 0;
uint64_t last_count_ = 0;

void print_() {
    std::thread *thread = new std::thread([&] {
        do {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << count_ - last_count_ << std::endl;
            last_count_ = count_;
        } while (1);
    });

    std::cout << thread->get_id() << std::endl;
}

int main1() {

    using namespace xutil;

    xworker_pool pool;

    for (size_t i = 0; i < 10000000; i++) {
        pool.add_job([&, i] {
            count_ = i;
        });
    }
    getchar();
    getchar();
    getchar();
    return 0;
}


int main() {
    print_();
    main1();
    return 0;
}