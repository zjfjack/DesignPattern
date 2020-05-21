// FacadePattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://en.wikipedia.org/wiki/Facade_pattern

#include <iostream>
#include <memory>

class CPU
{
public:
    void freeze()
    {
        std::cout << "CPU freeze" << std::endl;
    }

    void jump(long position)
    {
        std::cout << "CPU jump to position: " << position << std::endl;
    }

    void execute()
    {
        std::cout << "CPU execute" << std::endl;
    }
};

class HardDrive 
{
 public:
     std::string read(long lba, int size)
     {
         std::cout << "Hard Drive logical blocking adressing: " << lba << " and size: " << size << std::endl;
         return "hardDrivceData";
     }
};

class Memory 
{
public:
    void load(long position, std::string data)
    {
        std::cout << "Memory load position: " << position << " and data: " << data << std::endl;
    }
};

class ComputerFacade
{
public:
    void start()
    {
        cpu->freeze();
        memory->load(kBootAddress, hardDrive->read(kBootSector, kSectorSize));
        cpu->jump(kBootAddress);
        cpu->execute();
    }
private:
    std::unique_ptr<CPU> cpu = std::make_unique<CPU>();
    std::unique_ptr<HardDrive> hardDrive = std::make_unique<HardDrive>();
    std::unique_ptr<Memory> memory = std::make_unique<Memory>();

    long kBootAddress = 10008000;
    long kBootSector = 100;
    int kSectorSize = 1024;
};


int main()
{
    ComputerFacade computer;
    computer.start();
}