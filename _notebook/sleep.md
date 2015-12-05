# sleep

- https://github.com/ErikDubbelboer/node-sleep/issues/24
```cpp
#include <chrono>
#include <thread>

std::this_thread::sleep_for(std::chrono::nanoseconds(ssec));
std::this_thread::sleep_for(std::chrono::microseconds(usec));
std::this_thread::sleep_for(std::chrono::milliseconds(ms)); 
std::this_thread::sleep_for(std::chrono::seconds(sec));
std::this_thread::sleep_for(std::chrono::minutes(min));
std::this_thread::sleep_for(std::chrono::hours(hrs));
```
