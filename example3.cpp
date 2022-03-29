#include <iostream>
#include <stdexcept>

class prohibited_argument : public std::logic_error
{
    using logic_error::logic_error;
};

void validateArguments(int argc)
{
    if(argc != 2)
    {
        std::cerr << "You need to pass 1 argument" << std::endl;
        exit(-1);
    }
}

class Resource
{
public:
    void use(const char* arg)
    {
        std::cout << "Using resource. Passed " << *arg << std::endl;
        if (*arg == 'd')
        {
            throw prohibited_argument("Passed d. d is prohibited.");
        }
    }
};

int main(int argc, char* argv[])
{
    validateArguments(argc);

    const char* argument = argv[1];
    Resource* rsc = nullptr;

    try
    {
        rsc = new Resource();
        rsc->use(argument);
    }
    catch (std::logic_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    delete rsc;

    return 0;
}

