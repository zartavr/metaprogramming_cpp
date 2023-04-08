#include <iostream>
#include <string>

enum MessageLvl
{
    NO_MESSAGE,
    NORMAL,
    DEBUG,
};

template <class T>
struct Device_logs
{
    const int port;
    int lvl;
    T message;
};

template <template <typename> class C, typename T, int printlvl = MessageLvl::DEBUG>
void print(C<T> log)
{
    if (log.lvl <= printlvl)
    {
        std::cout << "port: " << log.port << std::endl;
        std::cout << log.message << std::endl;
    }
};

int main()
{
    Device_logs<std::string> complex_device = {.port = 0, .lvl = MessageLvl::DEBUG, .message = "Okay!"};
    Device_logs<std::uint32_t> plotter = {.port = 1, .lvl = MessageLvl::NORMAL, .message = 475};

    print<Device_logs, std::string, MessageLvl::NORMAL>(complex_device);
    print(plotter);

    std::cin.get();

    return 0;
}
