// https://en.wikipedia.org/wiki/Proxy_pattern

#include <iostream>
#include <memory>
#include <string>

class Image {
public:
    virtual ~Image() = default;
    virtual void displayImage() = 0;
};

class RealImage : public Image
{
public:
    RealImage(const std::string& fileName) : fileName(fileName) 
    {
        loadImageFromDisk();
    }

    virtual void displayImage() override
    {
        std::cout << "Displaying " << fileName << std::endl;
    }
private:
    const std::string& fileName;

    void loadImageFromDisk()
    {
        std::cout << "Loading " << fileName << std::endl;
    }
};

/*
Using the proxy pattern, the code of the ProxyImage avoids multiple loading of the image, 
accessing it from the other system in a memory-saving manner.
The lazy loading demonstrated in this example is not part of the proxy pattern, 
but is merely an advantage made possible by the use of the proxy.
*/

class ProxyImage : public Image
{
public:
    ProxyImage(const std::string& fileName) : fileName(fileName) {}

    virtual void displayImage() override
    {
        // lazy loading
        if (realImage == nullptr)
            realImage = std::make_unique<RealImage>(fileName);

        realImage->displayImage();
    }
private:
    std::string fileName;
    // Decorator holds the base class oject, it is used to decorate object
    // Virtual proxy holds the real object, it is used to hide information about(represent) the real object

    std::unique_ptr<RealImage> realImage;
};

int main()
{
    std::unique_ptr<Image> image1 = std::make_unique<ProxyImage>("image1");
    std::unique_ptr<Image> image2 = std::make_unique<ProxyImage>("image2");

    image1->displayImage(); // loading necessary
    image1->displayImage(); // loading unnecessary
    image2->displayImage(); // loading necessary
    image2->displayImage(); // loading unnecessary
    image1->displayImage(); // loading unnecessary
}