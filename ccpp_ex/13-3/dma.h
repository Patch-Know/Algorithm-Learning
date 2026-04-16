// dma.h  -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

//Pure Base Class
class PureDMA
{
private:
    char * label;
    int rating;
    
protected:
    const char * Lable() const {return label;}
    int Rating() const {return rating;}

public:
    PureDMA(const char * l = "null", int r = 0);
    PureDMA(const PureDMA & rs);
    virtual ~PureDMA() ;
    virtual PureDMA & operator=(const PureDMA & rs) ;
    friend  std::ostream & operator<<(std::ostream & os, 
                                     const PureDMA & rs);
    virtual void Sayself() const = 0;
    virtual void Show() const = 0;
};


//  Base Class Using DMA
class baseDMA : public PureDMA
{
private:
    
public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, 
                                     const baseDMA & rs);
    void Sayself() const {std::cout<<"Base!\n";}
    void Show() const {std::cout << *this;Sayself();}
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public PureDMA
{
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null",
              int r = 0);
    lacksDMA(const char * c, const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, 
                                     const lacksDMA & rs);
    void Sayself() const {std::cout<<"Lake!\n";}
    void Show() const {std::cout << *this << std::endl;Sayself();}

};

// derived class with DMA
class hasDMA :public PureDMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
              int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);  
    friend std::ostream & operator<<(std::ostream & os, 
                                     const hasDMA & rs);
    void Sayself() const {std::cout<<"Has!\n";}
    void Show() const {std::cout << *this <<std::endl;Sayself();}
    
};

#endif
