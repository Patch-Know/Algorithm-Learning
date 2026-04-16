//base class
class CD
{
private:
    char performance[50];
    char label[20];
    int selections;
    double playtime;
public:
    CD();
    CD(const CD & d);
    CD(const char * s1,const char * s2 , int n, double x);
    virtual ~CD(){}
    virtual void Report() const;
    virtual CD & operator=(const CD & d);
};

//detrived class
class Classic : public CD
{
private:
    char mainwork[50];
public:
    Classic(/* args */);
    Classic(const Classic & d);
    Classic(const char * s1,const char * s2 ,const char * s3, int n, double x);

    ~Classic(){}
    virtual void Report() const;
    virtual Classic & operator=(const Classic & d);
};



